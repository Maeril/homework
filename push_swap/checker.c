/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2020/01/08 21:01:29 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void		pile_size_checker(char **in, t_pslist *ha, t_psflag *f)
{
	int		i;
	int		pa;
	int		pb;

	i = 0;
	pa = 0;
	pb = 0;
	while (in[i])
	{
		pa += (cmp(in[i], "pa\n")) ? 1 : 0;
		pb -= (cmp(in[i], "pa\n")) ? 1 : 0;
		pb += (cmp(in[i], "pb\n")) ? 1 : 0;
		pa -= (cmp(in[i], "pb\n")) ? 1 : 0;
		if (pa > 1 || pb > 1 || cmp(in[i], "rrr\n") || cmp(in[i], "rr\n")
		|| cmp(in[i], "ss\n") || cmp(in[i], "rb\n")
		|| cmp(in[i], "rrb\n") || cmp(in[i], "sb\n")
		|| cmp(in[i], "rra\n") || cmp(in[i], "sa\n"))
		{
			list_free(ha);
			in ? tab_free(in) : 0;
			(f->instruc) ? free(f->instruc) : 0;
			ps_output(1);
		}
		i++;
	}
}

static t_pslist	*apply_instruct(char **n, t_pslist *ha, t_psflag *f)
{
	int			i;
	int			pa_pb;
	t_pslist	*hb;

	i = 0;
	pa_pb = 0;
	hb = NULL;
	while (n[i])
	{
		f->t == 1 ? pile_size_checker(n, ha, f) : 0;
		if (!hb && (cmp(n[i], "ss\n") || cmp(n[i], "rr\n") || cmp(n[i], "rb\n")
		|| cmp(n[i], "sb\n") || cmp(n[i], "rrb\n") || cmp(n[i], "rrr\n")))
			break ;
		cmp(n[i], "sb\n") || cmp(n[i], "ss\n") ? swap(hb, hb->next, f) : 0;
		cmp(n[i], "sa\n") || cmp(n[i], "ss\n") ? swap(ha, ha->next, f) : 0;
		pa_pb += (!(ft_strcmp(n[i], "pa\n"))) ? push(&hb, &ha, f) : 0;
		pa_pb -= (!(ft_strcmp(n[i], "pb\n"))) ? push(&ha, &hb, f) : 0;
		cmp(n[i], "ra\n") || cmp(n[i], "rr\n") ? rot(&ha, 1, f) : 0;
		cmp(n[i], "rb\n") || cmp(n[i], "rr\n") ? rot(&hb, 1, f) : 0;
		cmp(n[i], "rra\n") || cmp(n[i], "rrr\n") ? rrot(&ha, 1, f) : 0;
		cmp(n[i], "rrb\n") || cmp(n[i], "rrr\n") ? rrot(&hb, 1, f) : 0;
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
	flag->t = nb + 1;
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
	list = instructions ? apply_instruct(instructions, list, flag) : list;
	instructions ? tab_free(instructions) : 0;
	if (list)
		check_list(list) ? ps_output(2) : ps_output(3);
	list_free(list);
	(flag->instruc) ? free(flag->instruc) : 0;
}
