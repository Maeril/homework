/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/12/03 12:57:55 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist		*convertto_list(char **av, t_pslist *list, int *nb, t_psflag *f)
{
	int			i;
	t_pslist	*head;
	t_pslist	*tmp;

	i = f->visual ? 0 : 1;
	*nb = 0;
	list = node_fill(list, ft_atoll(av[i]));
	head = list;
	tmp = list;
	i++;
	while (av[i])
	{
		list->next = node_fill(list->next, ft_atoll(av[i]));
		list = list->next;
		list->prev = tmp;
		tmp = list;
		i++;
		(*nb)++;
	}
	list->next = NULL;
	return (head);
}

static char		**append_return(char **in, t_pslist *list)
{
	int		i;
	int		j;
	int		len;
	char	**out;

	i = 0;
	j = 0;
	len = 0;
	out = NULL;
	while (in[i])
	{
		in[i] = ft_free_join(in[i], "\n");
		i++;
	}
	if (i == 0)
	{
		in ? tab_free(in) : 0;
		check_list(list) ? ps_output(2) : ps_output(3);
		list_free(list);
		exit(0);
	}
	if (in[0][1] == '[' && in[0][2] == '1' && in[0][3] == ';')
		out = trim_comments(in, i);
	return (out ? out : in);
}

static char		**get_instruct(char **inst, t_pslist *list)
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
	ft_strdel(&stock);
	inst = append_return(inst, list);
	return (inst);
}

static t_pslist	*apply_instruct(char **in, t_pslist *ha, t_psflag *f)
{
	int			i;
	int			pa_pb;
	t_pslist	*hb;

	i = 0;
	pa_pb = 0;
	hb = NULL;
	while (in[i])
	{
		if (!hb && (cmp(in[i], "rrr\n") || cmp(in[i], "rr\n")
		|| cmp(in[i], "ss\n") || cmp(in[i], "rb\n")
		|| cmp(in[i], "rrb\n") || cmp(in[i], "sb\n")))
			break ;
		cmp(in[i], "sa\n") || cmp(in[i], "ss\n") ? swap(ha, ha->next, f) : 0;
		cmp(in[i], "sb\n") || cmp(in[i], "ss\n") ? swap(hb, hb->next, f) : 0;
		pa_pb += (!(ft_strcmp(in[i], "pa\n"))) ? push(&hb, &ha, f) : 0;
		pa_pb -= (!(ft_strcmp(in[i], "pb\n"))) ? push(&ha, &hb, f) : 0;
		cmp(in[i], "ra\n") || cmp(in[i], "rr\n") ? rot(&ha, 1, f) : 0;
		cmp(in[i], "rb\n") || cmp(in[i], "rr\n") ? rot(&hb, 1, f) : 0;
		cmp(in[i], "rra\n") || cmp(in[i], "rrr\n") ? rrot(&ha, 1, f) : 0;
		cmp(in[i], "rrb\n") || cmp(in[i], "rrr\n") ? rrot(&hb, 1, f) : 0;
		i++;
	}
	pa_pb < 0 ? ps_output(2) : 0;
	return (pa_pb < 0 ? NULL : ha);
}

void			checker(t_pslist *list, t_psflag *flag, char **argv)
{
	int		nb;
	char	**instructions;

	list = convertto_list(argv, list, &nb, flag);
	if (max_min_checker(argv) || duplicate_finder(list))
	{
		list_free(list);
		ps_output(1);
	}
	instructions = NULL;
	instructions_displayer(1, 0);
	instructions = get_instruct(instructions, list);
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
}
