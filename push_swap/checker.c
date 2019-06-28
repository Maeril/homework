/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/06/28 21:56:36 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*convertto_list(char **argv, t_pslist *list)
{
	int			i;

	i = 0;
	while (argv[i]) /* while we go through the proof-read arguments*/
	{
		list = listfill(list, ft_atoi(argv[i])); /* fill every node with each argument as an int */
		i++;
	}
	list->next = NULL; /* end the chained list accordingly once it's out of the loop */
	return (list); /* return the filled-up list */
}

char		**get_instruct(char	**instructions)
{
    int read;

	read = 0;
	while (read != EOF)
    	read = get_next_line(0, instructions);
    if (read != -1) /*if there was no error*/
        ft_putstr(*instructions); /* not needed in push_swap, to be deleted */
    else
        ft_printf("No line read...\n");
    return (instructions);
}

t_pslist	*apply_instruct(char **inst, t_pslist *list)
{
	int i;

	i = 0;
	while (inst[i] != NULL)
	{
		if (!(ft_strcmp(inst[i], "sa")) || !(ft_strcmp(inst[i], "ss"))) // swap a ou swap a & b
		if (!(ft_strcmp(inst[i], "sb")) || !(ft_strcmp(inst[i], "ss"))) // swap b ou swap a & b
		if (!(ft_strcmp(inst[i], "pa"))) // push a
		if (!(ft_strcmp(inst[i], "pb"))) // push b
		if (!(ft_strcmp(inst[i], "ra")) || !(ft_strcmp(inst[i], "rr"))) // rotate a ou rotate a & b
		if (!(ft_strcmp(inst[i], "rb")) || !(ft_strcmp(inst[i], "rr"))) // rotate b ou rotate a & b
		if (!(ft_strcmp(inst[i], "rra")) || !(ft_strcmp(inst[i], "rrr"))) // reverse rotate a ou reverse rotate a & b
		if (!(ft_strcmp(inst[i], "rrb")) || !(ft_strcmp(inst[i], "rrr"))) // reverse rotate b ou reverse rotate a & b
		i++;
	}
	return (list);
}

void		checker(t_pslist *list, t_psflag *flag, char **argv)
{
	char	**instructions;

	instructions = NULL;
	list = convertto_list(argv, list); /* put all the arguments in chained list nodes */
	if (check_list(list, flag)) /* if the list is unsorted (if it's sorted "OK" was already outputed), */
	{
		instructions = get_instruct(instructions);
		list = apply_instruct(instructions, list);
		if (check_list(list, flag))  /* if the list is STILL unsorted (if it's sorted "OK" was already outputed), */
			ps_output(2); /* then output "KO" */
	}
}
