/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/07/30 16:09:59 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max_min_checker(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) > MAX_INT || ft_atoll(argv[i]) < MIN_INT)
			return (1);
		i++;
	}
	return (0);
}

t_pslist	*convertto_list(char **argv, t_pslist *list, int *nb)
{
	int			i;
	t_pslist	*head;
	t_pslist	*tmp;

	/* first interation OUTSIDE THE LOOP to attach head effectively */
	i = 1; // 1 et pas 0 pour sauter l'executable
	*nb = 0;
	list = node_fill(list, ft_atoll(argv[i])); /* fill every node with each argument as an int */
	head = list;
	tmp = list; // stock list in tmp
	i++;
	while (argv[i]) /* while we go through the proof-read arguments*/
	{
		list->next = node_fill(list->next, ft_atoll(argv[i])); /* fill every node with each argument as an int */
		list = list->next; // move current node to next
		list->prev = tmp; // "pour" tmp into prev
		tmp = list; // stock list in tmp
		i++;
		(*nb)++;
	}
	list->next = NULL;
	return (head); /* return the filled-up list */
}

char		**get_instruct(t_pslist *list, t_psflag *flag, char **av, char	**instructions)
{
	int		i;
    int 	r;
    int 	len;
	char	**output;

	output = push_swap(list, flag, av);
	i = 0;
	len = 0;
	while (output[i])
	{
		if (ft_strcmp(output[i], "na"))
			len++;
		i++;
	}
	tab_free(output);
	i = 0;
	if (!(instructions = malloc(sizeof(char*) * (len + 1)))) // trouver un moyen d'avoir le bon nombre d'instructions au depart car c'est de la que vient le + gros leak !!
		return (NULL);
    i = 0;
	r = 1;
	while (r != 0 && r != -1)
	{
		if (!(instructions[i] = malloc(sizeof(char) * (4 + 1))))
			return (NULL);
		ft_bzero(instructions[i], 5);
        r = read(0, instructions[i], 5);
		i++;
	}
	return (instructions);
}

t_pslist	*apply_instruct(char **inst, t_pslist *head_a, t_psflag *flag)
{
	int 		i;
	t_pslist	*head_b;

	i = 0;
	head_b = NULL;
	while (inst[i])
	{
		if (!(ft_strcmp(inst[i], "sa\n")) || !(ft_strcmp(inst[i], "ss\n"))) // swap a ou swap a & b
			swap(head_a, head_a->next, flag);
		if (!(ft_strcmp(inst[i], "sb\n")) || !(ft_strcmp(inst[i], "ss\n"))) // swap b ou swap a & b
			swap(head_b, head_b->next, flag);
		if (!(ft_strcmp(inst[i], "pa\n"))) // push a
			push(&head_b, &head_a, flag);
		if (!(ft_strcmp(inst[i], "pb\n"))) // push b
			push(&head_a, &head_b, flag);
		if (!(ft_strcmp(inst[i], "ra\n")) || !(ft_strcmp(inst[i], "rr\n"))) // rotate a ou rotate a & b
			rotate(&head_a, 1, flag);
		if (!(ft_strcmp(inst[i], "rb\n")) || !(ft_strcmp(inst[i], "rr\n"))) // rotate b ou rotate a & b
			rotate(&head_b, 1, flag);
		if (!(ft_strcmp(inst[i], "rra\n")) || !(ft_strcmp(inst[i], "rrr\n"))) // reverse rotate a ou reverse rotate a & b
			rrotate(&head_a, 1, flag);
		if (!(ft_strcmp(inst[i], "rrb\n")) || !(ft_strcmp(inst[i], "rrr\n"))) // reverse rotate b ou reverse rotate a & b
			rrotate(&head_b, 1, flag);
		i++;
	}
	return (head_a);
}

void		checker(t_pslist *list, t_psflag *flag, char **argv)
{
	int		nb; // nb indicate the list's ending point, it isn't needed for checker
	char	**instructions;

	list = convertto_list(argv, list, &nb); /* put all the arguments in chained list nodes */
	if (max_min_checker(argv) || duplicate_finder(list)) // if there's a duplicate,
	{
		list_free(list);
		ps_output(1); // output "Error\n"
		exit (0); // and quit
	}
	instructions = NULL;
	if (check_list(list, flag)) /* if the list is unsorted (if it's sorted "OK" was already outputed), */
	{
		instructions = get_instruct(list, flag, argv, instructions);
		if (bad_instructions(instructions))
		{
			ps_output(1); // output "Error\n"
			exit (0); // and quit
		}
		if (instructions)
		{
			list = apply_instruct(instructions, list, flag);
			tab_free(instructions);
		}
		if (check_list(list, flag))  /* if the list is STILL unsorted (if it's sorted "OK" was already outputed), */
			ps_output(2); /* then output "KO" */
	}
	list_free(list);
	free(flag->instruc);
	exit (0);
}
