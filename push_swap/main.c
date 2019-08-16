/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:38:48 by myener            #+#    #+#             */
/*   Updated: 2019/08/16 15:54:14 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sign(char **av, int i, int j)
{
	return ((av[i][j] == '-' || av[i][j] == '+') ? 1 : 0);
}

int		is_digit(char **av, int i, int j)
{
	return ((av[i][j] >= '0' && av[i][j] <= '9') ? 1 : 0);
}

int		bad_arg_check_saver(char **av, int i, int j)
{
	if (is_sign(av, i, j))
	{
		j++;
		if (!av[i][j])
			return (1);
		while (av[i][j])
		{
			if (!is_digit(av, i, j))
				return (1);
			j++;
		}
	}
	else if (is_digit(av, i, j))
		while (av[i][j])
		{
			if (av[i][j + 1] && !is_digit(av, i, j + 1))
				return (1);
			j++;
		}
	return (0);
}

int		bad_arg_checker(char **av)
{
	int i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (is_sign(av, i, j) || is_digit(av, i, j))
				return (bad_arg_check_saver(av, i, j));
			else if (!is_sign(av, i, j) && !is_digit(av, i, j))
				return (1);
			j++;
		}
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
	flag.ch = 0;
	flag.ps = 0;
	flag.instruc = NULL;
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
