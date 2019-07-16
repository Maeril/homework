/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/07/16 17:31:39 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*convertto_list(char **argv, t_pslist *list, int *nb)
{
	int			i;
	t_pslist	*head;
	t_pslist	*tmp;

	/* first interation OUTSIDE THE LOOP to attach head effectively */
	i = 1; // 1 et pas 0 pour sauter l'executable
	*nb = 0;
	list = node_fill(list, ft_atoi(argv[i])); /* fill every node with each argument as an int */
	head = list;
	tmp = list; // stock list in tmp
	i++;
	while (argv[i]) /* while we go through the proof-read arguments*/
	{
		list->next = node_fill(list->next, ft_atoi(argv[i])); /* fill every node with each argument as an int */
		list = list->next; // move current node to next
		list->prev = tmp; // "pour" tmp into prev
		tmp = list; // stock list in tmp
		i++;
		(*nb)++;
	}
	list->next = NULL;
	// printf("\n");
	return (head); /* return the filled-up list */
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
	int		nb; // nb indicate the list's ending point, it isn't needed for checker
	char	**instructions;

	instructions = NULL;
	list = convertto_list(argv, list, &nb); /* put all the arguments in chained list nodes */
	if (check_list(list, flag)) /* if the list is unsorted (if it's sorted "OK" was already outputed), */
	{
		instructions = get_instruct(instructions);
		list = apply_instruct(instructions, list);
		if (check_list(list, flag))  /* if the list is STILL unsorted (if it's sorted "OK" was already outputed), */
			ps_output(2); /* then output "KO" */
	}
}
