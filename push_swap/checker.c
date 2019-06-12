/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/06/12 17:47:41 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*convertto_list(char **argv, t_pslist *list)
{
	int			i;

	i = 0;
	while (argv[i]) /* while we go through the proof-read arguments*/
	{
		list = listfill(list, ft_atoi(argv[i])); /* fill eveery node with each argument as an int */
		i++;
	}
	list->next = NULL; /* end the chained list accordingly once it's out of the loop */
	return (list); /* return the filled-up list */
}

void		checker(t_pslist *list, char **argv)
{
	t_pslist *curr;

	list = convertto_list(argv, list); /* put all the arguments in chained list nodes */
	curr = &list; /* keep track of the head of the chained list */
	while (curr && curr->next) /* while the chained list exists, go through it */
	{
		if (curr->data > curr->next->data) /* if one data is greater than the next, */
		{
			ft_putstr("KO\n"); /* output "KO", as it means the list isn't in ascending order */
			return ;
		}
		curr = curr->next;
	}
	ft_putstr("OK\n"); /* if all is well, output "OK" */
}
