/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_vetting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:19:57 by myener            #+#    #+#             */
/*   Updated: 2019/10/29 15:43:36 by myener           ###   ########.fr       */
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
	tab ? free(tab) : 0;
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
			&& ft_strcmp(*instruc, "rr\n") && ft_strcmp(*instruc, "")
			&& ft_strcmp(*instruc, "sa") && ft_strcmp(*instruc, "sb")
			&& ft_strcmp(*instruc, "pa") && ft_strcmp(*instruc, "pb")
			&& ft_strcmp(*instruc, "ra") && ft_strcmp(*instruc, "rb")
			&& ft_strcmp(*instruc, "rra") && ft_strcmp(*instruc, "rrb")
			&& ft_strcmp(*instruc, "ss") && ft_strcmp(*instruc, "rrr")
			&& ft_strcmp(*instruc, "rr"))
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
		if (list->data > i)
			i = list->data;
		if (!list->next)
			break ;
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

int		duplicate_finder(t_pslist *l)
{
	int			high;
	int			*tab;

	if (((check_length(l) == 3) && (l->data == l->next->data
	|| l->data == l->next->next->data || l->next->data == l->next->next->data))
	|| ((check_length(l) == 2) && (l->data == l->next->data)))
		return (1);
	high = find_highest_value(l);
	if (high == 2147483647 || !(tab = malloc(sizeof(int) * (high + 1))))
		return (0);
	tab = initialize_tab(tab, high);
	while (l && l->data >= 0)
	{
		(tab[l->data] == 1) ? free(tab) : 0;
		if (tab[l->data] == 1)
			return (1);
		if (!l->next)
			break ;
		if (tab[l->data] == 0)
			tab[l->data] = 1;
		l = l->next;
	}
	free(tab);
	return (0);
}
