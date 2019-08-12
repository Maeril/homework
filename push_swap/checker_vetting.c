/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_vetting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:19:57 by myener            #+#    #+#             */
/*   Updated: 2019/08/12 17:10:09 by myener           ###   ########.fr       */
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
	// int	i;

	// i = 0;
	while (*instruc != NULL)
	{
		// printf("i = %d\n", i);
		if (ft_strcmp(*instruc, "sa") && ft_strcmp(*instruc, "sb")
			&& ft_strcmp(*instruc, "pa") && ft_strcmp(*instruc, "pb")
			&& ft_strcmp(*instruc, "ra") && ft_strcmp(*instruc, "rb")
			&& ft_strcmp(*instruc, "rra") && ft_strcmp(*instruc, "rrb")
			&& ft_strcmp(*instruc, "ss") && ft_strcmp(*instruc, "rrr")
			&& ft_strcmp(*instruc, "rr") && ft_strcmp(*instruc, ""))
			return (1);
		// if (!instruc[i + 1])
		// i++;
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
	int			len;
	int			high;
	int			*tab;

	len = check_length(list);
	if (len == 3)
	{
		if (list->data == list->next->data || list->data == list->next->next->data
			|| list->next->data == list->next->next->data)
				return (1);
	}
	else if (len == 2)
	{
		if (list->data == list->next->data)
			return (1);
	}
	else
	{
		high = find_highest_value(list); // find the highest value (to allocate enough memory)
		if (!(tab = malloc(sizeof(int) * (high + 1))))
			return (0);
		tab = initialize_tab(tab, high); // fill the array with some sweet Z's
		while (list) // while we go through the list,
		{
			if (tab[list->data] == 1) // if the data has already been encountered,
			{
				free (tab);
				return (1); // return 1 (AKA "yep, that duplicate officer")
			}
			if (!list->next)
				break;
			if (tab[list->data] == 0) // else if that's the first time we encounter it
				tab[list->data] = 1; // "switch" it on so we know we've encountered it already later on
			list = list->next;
		}
		free (tab);
	}
	return (0);
}