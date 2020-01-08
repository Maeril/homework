/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:21:03 by myener            #+#    #+#             */
/*   Updated: 2020/01/08 20:52:26 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*convertto_list(char **av, t_pslist *list, int *nb, t_psflag *f)
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

void		flag_init(t_psflag *flag)
{
	flag->ch = 0;
	flag->instruc = NULL;
	flag->np = 0;
	flag->nr = 0;
	flag->pivot = 0;
	flag->ps = 0;
	flag->t = 0;
	flag->visual = 0;
}

int			max_min_checker(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) > MAX_INT || ft_atoll(argv[i]) < MIN_INT
			|| (ft_atoll(argv[i]) > 0 && ft_strlen(argv[i]) > 10)
			|| (ft_atoll(argv[i]) < 0 && ft_strlen(argv[i]) > 11))
			return (1);
		i++;
	}
	return (0);
}

int			same_data(t_pslist *curr, int fin)
{
	int	i;

	i = 0;
	while (curr && i < fin)
	{
		if (!curr->next)
			break ;
		if (curr->data != curr->next->data)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

int			ps_output(int i)
{
	ft_putstr("\e[4m\033[1;37mResult\e[0m:\n\033[0m");
	if (i == 1)
	{
		ft_putstr("\033[1;31m");
		write(2, "Error\n", 6);
		exit(0);
	}
	else if (i == 2)
	{
		ft_putstr("\033[1;33m");
		write(1, "KO\n", 3);
	}
	else if (i == 3)
	{
		ft_putstr("\033[1;32m");
		write(1, "OK\n", 3);
	}
	ft_putstr("\033[0m");
	return (0);
}
