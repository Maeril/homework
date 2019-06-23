/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/06/23 20:38:04 by myener           ###   ########.fr       */
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

char		**get_instruct(char	**instructions)
{
	return (instructions);
}

t_pslist	*apply_instruct(char **instructions, t_pslist *list)
{
	return (list);
}

void		checker(t_pslist *list, char **argv)
{
	char	**instructions;

	list = convertto_list(argv, list); /* put all the arguments in chained list nodes */
	if (check_list(list)) /* if the list is unsorted (if it's sorted "OK" was already outputed), */
	{
		instructions = get_instruct(instructions);
		list = apply_instruct(instructions, list);
		if (check_list(list))  /* if the list is STILL unsorted (if it's sorted "OK" was already outputed), */
			ps_output(2); /* then output "KO" */
	}
}
