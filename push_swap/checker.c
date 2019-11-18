/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/11/18 17:30:18 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist		*convertto_list(char **argv, t_pslist *list, int *nb)
{
	int			i;
	t_pslist	*head;
	t_pslist	*tmp;

	i = 1;
	*nb = 0;
	list = node_fill(list, ft_atoll(argv[i]));
	head = list;
	tmp = NULL;
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

static char		**append_return(char **in)
{
	int	i;

	i = 0;
	while (in[i])
	{
		in[i] = ft_free_join(in[i], "\n");
		i++;
	}
	return (in);
}

static char		**get_instruct(char **inst)
{
	int		i;
	char	*tmp;
	char	*line;
	char	*stock;

	i = 0;
	stock = ft_strnew(1);
	while (get_next_line(0, &line))
	{
		tmp = line;
		stock = ft_free_join(stock, line);
		stock = ft_free_join(stock, "\n");
		free(tmp);
		i++;
	}
	i = 0;
	while (stock[i])
	{
		(stock[i] == '\n' && stock[i + 1] == '\n') ? ps_output(1) : 0;
		i++;
	}
	inst = ft_strsplit(stock, '\n');
	inst = append_return(inst);
	ft_strdel(&stock);
	return (inst);
}

static t_pslist	*apply_instruct(char **in, t_pslist *h_a, t_psflag *f)
{
	int			i;
	int			pa_pb;
	t_pslist	*h_b;

	i = 0;
	pa_pb = 0;
	h_b = NULL;
	while (in[i])
	{
		if (!h_b && (cmp(in[i], "rrr\n") || cmp(in[i], "rr\n")
		|| cmp(in[i], "ss\n")))
			break ;
		cmp(in[i], "sa\n") || cmp(in[i], "ss\n") ? swap(h_a, h_a->next, f) : 0;
		cmp(in[i], "sb\n") || cmp(in[i], "ss\n") ? swap(h_b, h_b->next, f) : 0;
		pa_pb += (!(ft_strcmp(in[i], "pa\n"))) ? push(&h_b, &h_a, f) : 0;
		pa_pb -= (!(ft_strcmp(in[i], "pb\n"))) ? push(&h_a, &h_b, f) : 0;
		cmp(in[i], "ra\n") || cmp(in[i], "rr\n") ? rot(&h_a, 1, f) : 0;
		cmp(in[i], "rb\n") || cmp(in[i], "rr\n") ? rot(&h_b, 1, f) : 0;
		cmp(in[i], "rra\n") || cmp(in[i], "rrr\n") ? rrot(&h_a, 1, f) : 0;
		cmp(in[i], "rrb\n") || cmp(in[i], "rrr\n") ? rrot(&h_b, 1, f) : 0;
		i++;
	}
	pa_pb < 0 ? ps_output(2) : 0;
	return (pa_pb < 0 ? NULL : h_a);
}

void			checker(t_pslist *list, t_psflag *flag, char **argv)
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
	instructions = get_instruct(instructions);
	if (bad_instructions(instructions))
	{
		list_free(list);
		instructions ? tab_free(instructions) : 0;
		ps_output(1);
	}
	if (instructions)
		list = apply_instruct(instructions, list, flag);
	instructions ? tab_free(instructions) : 0;
	if (list)
		check_list(list) ? ps_output(2) : ps_output(3);
	list_free(list);
	(flag->instruc) ? free(flag->instruc) : 0;
	exit(0);
}
