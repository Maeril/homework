/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/08/16 16:41:19 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			max_min_checker(char **argv)
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

	i = 1;
	*nb = 0;
	list = node_fill(list, ft_atoll(argv[i]));
	head = list;
	tmp = list;
	i++;
	while (argv[i])
	{
		list->next = node_fill(list->next, ft_atoll(argv[i]));
		list = list->next;
		list->prev = tmp;
		tmp = list;
		i++;
		(*nb)++;
	}
	list->next = NULL;
	return (head);
}

char		**get_instruct(t_pslist *l, t_psflag *f, char **av, char **inst)
{
	int		i;
	int		j;
	int		r;
	int		len;
	char	**output;

	output = push_swap(l, f, av);
	i = 0;
	len = output ? 1 : 4;
	if (output)
	{
		while (output[i])
		{
			if (ft_strcmp(output[i], "na"))
				len++;
			i++;
		}
		tab_free(output);
		free(output);
	}
	i = 0;
	if (!(inst = malloc(sizeof(char*) * (len + 1))))
		exit(0);
	i = 0;
	r = 1;
	while (r != 0)
	{
		if (!(inst[i] = malloc(sizeof(char) * (4 + 1))))
			exit(0);
		ft_bzero(inst[i], 5);
		r = read(0, inst[i], 5);
		j = 0;
		if (inst[i][j] == '\0' && inst[i][j + 1])
			ps_output(1);
		i++;
	}
	inst[i] = NULL;
	return (inst);
}

t_pslist	*apply_instruct(char **inst, t_pslist *head_a, t_psflag *flag)
{
	int			i;
	int			pa_pb_balance;
	t_pslist	*head_b;

	i = 0;
	pa_pb_balance = 0;
	head_b = NULL;
	while (inst[i])
	{
		if (!(ft_strcmp(inst[i], "sa\n")) || !(ft_strcmp(inst[i], "ss\n")))
			swap(head_a, head_a->next, flag);
		if (!(ft_strcmp(inst[i], "sb\n")) || !(ft_strcmp(inst[i], "ss\n")))
			swap(head_b, head_b->next, flag);
		if (!(ft_strcmp(inst[i], "pa\n")))
			pa_pb_balance += push(&head_b, &head_a, flag);
		if (!(ft_strcmp(inst[i], "pb\n")))
			pa_pb_balance -= push(&head_a, &head_b, flag);
		if (!(ft_strcmp(inst[i], "ra\n")) || !(ft_strcmp(inst[i], "rr\n")))
			rotate(&head_a, 1, flag);
		if (!(ft_strcmp(inst[i], "rb\n")) || !(ft_strcmp(inst[i], "rr\n")))
			rotate(&head_b, 1, flag);
		if (!(ft_strcmp(inst[i], "rra\n")) || !(ft_strcmp(inst[i], "rrr\n")))
			rrotate(&head_a, 1, flag);
		if (!(ft_strcmp(inst[i], "rrb\n")) || !(ft_strcmp(inst[i], "rrr\n")))
			rrotate(&head_b, 1, flag);
		i++;
	}
	(pa_pb_balance < 0) ? ps_output(2) : 0;
	if (pa_pb_balance < 0)
		return (NULL);
	return (head_a);
}

void		checker(t_pslist *list, t_psflag *flag, char **argv)
{
	int		nb;
	char	**instructions;

	list = convertto_list(argv, list, &nb);
	if (max_min_checker(argv) || duplicate_finder(list))
	{
		list_free(list);
		ps_output(1);
	}
	instructions = NULL;
	instructions = get_instruct(list, flag, argv, instructions);
	if (bad_instructions(instructions))
	{
		list_free(list);
		ps_output(1);
	}
	if (instructions)
	{
		list = apply_instruct(instructions, list, flag);
		tab_free(instructions);
	}
	if (list)
	{
		if (check_list(list))
			ps_output(2);
		else
			ps_output(3);
	}
	list_free(list);
	if (flag->instruc)
		free(flag->instruc);
	exit(0);
}
