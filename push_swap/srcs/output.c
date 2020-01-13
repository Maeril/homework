/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:20:59 by myener            #+#    #+#             */
/*   Updated: 2020/01/13 19:45:50 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		**get_instruct(char **inst, t_pslist *list)
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

void		ps_displayer(char **out)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	instructions_displayer(2, 0);
	while (out[i])
	{
		if (ft_strcmp(out[i], "na"))
		{
			ft_putendl(out[i]);
			nb++;
		}
		free(out[i]);
		i++;
	}
	instructions_displayer(3, nb);
}
