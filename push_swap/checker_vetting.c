/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_vetting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:19:57 by myener            #+#    #+#             */
/*   Updated: 2019/08/13 18:12:01 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tab_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int		bad_instructions(char **instruc)
{
	while (*instruc != NULL)
	{
		if (ft_strcmp(*instruc, "sa\n") && ft_strcmp(*instruc, "sb\n")
			&& ft_strcmp(*instruc, "pa\n") && ft_strcmp(*instruc, "pb\n")
			&& ft_strcmp(*instruc, "ra\n") && ft_strcmp(*instruc, "rb\n")
			&& ft_strcmp(*instruc, "rra\n") && ft_strcmp(*instruc, "rrb\n")
			&& ft_strcmp(*instruc, "ss\n") && ft_strcmp(*instruc, "rrr\n")
			&& ft_strcmp(*instruc, "rr\n") && ft_strcmp(*instruc, ""))
			return (1);
		instruc++;
	}
	return (0);
}

int		find_highest_value(t_pslist *list)
{
	int		i;

	i = 0;
	while (list)
	{
		if (!list->next)
			break ;
		if (list->data > i)
			i = list->data;
		list = list->next;
	}
	return (i);
}

int		*initialize_tab(int *tab, int len)
{
	int i;

	i = 0;
	while (i <= len)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int		duplicate_finder(t_pslist *l) // find duplicates using hash table
{
	int			high;
	int			*tab;

	if (((check_length(l) == 3) && (l->data == l->next->data
	|| l->data == l->next->next->data || l->next->data == l->next->next->data))
	|| ((check_length(l) == 2) && (l->data == l->next->data)))
		return (1);
	high = find_highest_value(l); // find the highest value (to allocate enough memory)
	if (!(tab = malloc(sizeof(int) * (high + 1))))
		return (0);
	tab = initialize_tab(tab, high); // fill the array with some sweet Z's
	while (l) // while we go through the list,
	{
		if (tab[l->data] == 1) // if the data has already been encountered,
		{
			free(tab);
			return (1); // return 1 (AKA "yep, that duplicate officer")
		}
		if (!l->next)
			break ;
		if (tab[l->data] == 0) // else if that's the first time we encounter it
			tab[l->data] = 1; // "switch" it on so we know we've encountered it already later on
		l = l->next;
	}
	free(tab);
	return (0);
}
