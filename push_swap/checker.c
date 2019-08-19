/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/08/19 13:22:12 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char		**instruct_reader(char **inst)
{
	int		i;
	int		j;
	int		r;

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

char		**get_instruct(t_pslist *l, t_psflag *f, char **av, char **inst)
{
	int		i;
	int		len;
	char	**output;

	output = push_swap(l, f, av);
	i = 0;
	len = output ? 1 : 4;
	if (output)
		while (output[i])
		{
			if (ft_strcmp(output[i], "na"))
				len++;
			i++;
		}
	output ? tab_free(output) : 0;
	output ? free(output) : 0;
	if (!(inst = malloc(sizeof(char*) * (len + 1))))
		exit(0);
	return (instruct_reader(inst));
}

t_pslist	*apply_instruct(char **in, t_pslist *h_a, t_psflag *f)
{
	int			i;
	int			pa_pb;
	t_pslist	*h_b;

	i = 0;
	pa_pb = 0;
	h_b = NULL;
	while (in[i])
	{
		if (cmp(in[i], "sa\n") || cmp(in[i], "ss\n"))
			swap(h_a, h_a->next, f);
		if (cmp(in[i], "sb\n") || cmp(in[i], "ss\n"))
			swap(h_b, h_b->next, f);
		pa_pb += (!(ft_strcmp(in[i], "pa\n"))) ? push(&h_b, &h_a, f) : 0;
		pa_pb -= (!(ft_strcmp(in[i], "pb\n"))) ? push(&h_a, &h_b, f) : 0;
		cmp(in[i], "ra\n") || cmp(in[i], "rr\n") ? rot(&h_a, 1, f) : 0;
		cmp(in[i], "rb\n") || cmp(in[i], "rr\n") ? rot(&h_b, 1, f) : 0;
		cmp(in[i], "rra\n") || cmp(in[i], "rrr\n") ? rrot(&h_a, 1, f) : 0;
		cmp(in[i], "rrb\n") || cmp(in[i], "rrr\n") ? rrot(&h_b, 1, f) : 0;
		i++;
	}
	(pa_pb < 0) ? ps_output(2) : 0;
	if (pa_pb < 0)
		return (NULL);
	return (h_a);
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
		list = apply_instruct(instructions, list, flag);
	instructions ? tab_free(instructions) : 0;
	if (list)
		check_list(list) ? ps_output(2) : ps_output(3);
	list_free(list);
	if (flag->instruc)
		free(flag->instruc);
	exit(0);
}
