/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_vetting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:19:57 by myener            #+#    #+#             */
/*   Updated: 2019/07/31 17:35:31 by myener           ###   ########.fr       */
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
	int	i;

	i = 0;
	while (instruc[i])
	{
		if (ft_strcmp(instruc[i], "sa\n") && ft_strcmp(instruc[i], "sb\n")
			&& ft_strcmp(instruc[i], "pa\n") && ft_strcmp(instruc[i], "pb\n")
			&& ft_strcmp(instruc[i], "ra\n") && ft_strcmp(instruc[i], "rb\n")
			&& ft_strcmp(instruc[i], "rra\n") && ft_strcmp(instruc[i], "rrb\n")
			&& ft_strcmp(instruc[i], "ss\n") && ft_strcmp(instruc[i], "rrr\n")
			&& ft_strcmp(instruc[i], "rr\n") && ft_strcmp(instruc[i], ""))
			return (1);
		i++;
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
			break;
		if (list->data > i)
			i = list->data;
		list = list->next;
	}
	return (i);
}

int	*initialize_tab(int *tab, int len)
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

int		duplicate_finder(t_pslist *list) // find duplicates using hash table
{
	int			high;
	int			*tab;

	high = find_highest_value(list); // find the highest value (to allocate enough memory)
	if (!(tab = malloc(sizeof(int) * (high + 1))))
		return (0);
	tab = initialize_tab(tab, high); // fill the array with some sweet Z's
	while (list) // while we go through the list,
	{
		if (!list->next)
			break;
		if (tab[list->data] == 1) // if the data has already been encountered,
		{
			free (tab);
			return (1); // return 1 (AKA "yep, that duplicate officer")
		}
		else if (tab[list->data] == 0) // else if that's the first time we encounter it
			tab[list->data] = 1; // "switch" it on so we know we've encountered it already later on
		list = list->next;
	}
	// if (tab[list->data] == 1) // last node check
	// {
	// 	free (tab);
	// 	return (1);
	// }
	free (tab);
	return (0);
}