/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:38:48 by myener            #+#    #+#             */
/*   Updated: 2019/10/07 21:37:41 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sign(char *arg, int i)
{
	return ((arg[i] == '-' || arg[i] == '+') ? 1 : 0);
}

int		is_digit(char *arg, int i)
{
	return ((arg[i] >= '0' && arg[i] <= '9') ? 1 : 0);
}

int		bad_arg_check_saver(char *arg)
{
	int	i;

	i = 0;
	if (is_sign(arg, i))
	{
		i++;
		if (!arg[i] || (arg[i] == '0' && !arg[i + 1]))
			ps_output(1);
		while (arg[i])
		{
			if (!is_digit(arg, i))
				ps_output(1);
			i++;
		}
	}
	else if (is_digit(arg, i))
	{
		while (arg[i])
		{
			if (!is_digit(arg, i))
				ps_output(1);
			i++;
		}
	}
	return (0);
}

int		bad_arg_checker(char **tab)
{
	int i;

	i = 1;
	while (tab[i])
	{
		if ((tab[i][0] == '-' || tab[i][0] == '+')
			|| (tab[i][0] >= '0' && tab[i][0] <= '9'))
			(bad_arg_check_saver(tab[i]));
		if ((tab[i][0] != '-' && tab[i][0] != '+')
			&& (tab[i][0] <= '0' && tab[i][0] >= '9'))
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	const char	*str;
	t_pslist	list;
	t_psflag	flag;

	list.data = 0;
	flag_init(&flag);
	str = "/Users/myener/Desktop/homework/push_swap/push_swap";
	if (!(ac >= 2))
		return (0);
	if ((bad_arg_checker(av)) == 1)
		ps_output(1);
	else if ((bad_arg_checker(av)) == 0)
	{
		if ((flag.ch = (!ft_strcmp(av[0], "./checker"))))
			checker(&list, &flag, av);
		else if ((flag.ps = (!ft_strcmp(av[0], "./push_swap")
		|| !ft_strcmp(av[0], str))))
			push_swap(&list, &flag, av);
		else
			ps_output(1);
	}
	return (0);
}
