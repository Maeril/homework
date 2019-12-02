/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:38:48 by myener            #+#    #+#             */
/*   Updated: 2019/12/02 15:30:57 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bad_arg_check_saver(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		i++;
		if (!arg[i] || (arg[i] == '0' && !arg[i + 1]))
			ps_output(1);
		while (arg[i])
		{
			if (!(arg[i] >= '0' && arg[i] <= '9'))
				ps_output(1);
			i++;
		}
	}
	else if ((arg[i] >= '0' && arg[i] <= '9') || arg[i] == ' ')
		while (arg[i])
		{
			if ((!(arg[i] >= '0' && arg[i] <= '9')) && arg[i] != ' ')
				ps_output(1);
			i++;
		}
	return (0);
}

static char	**bad_arg_checker_special(char **tab)
{
	int		i;
	int		j;
	char	*str;
	char	**stk;

	str = ft_strdup(tab[0]);
	stk = ft_spacesplit(tab[1]);
	i = 0;
	while (stk[i])
		i++;
	if (!(tab = malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	tab[0] = ft_strdup(str);
	i = 1;
	j = 0;
	while (stk[j])
	{
		tab[i] = ft_strdup(stk[j]);
		i++;
		j++;
	}
	tab[i] = NULL;
	tab_free(stk);
	str ? free(str) : 0;
	return (tab);
}

static char	**bad_arg_checker(char **tab, t_psflag *flag)
{
	int		i;

	if (!tab[2])
		tab = bad_arg_checker_special(tab);
	if ((flag->visual = (!(ft_strcmp(tab[1], "-v")))))
		tab = visual_flag_remover(tab);
	i = 1;
	while (tab[i])
	{
		if ((tab[i][0] == '-' || tab[i][0] == '+')
			|| (tab[i][0] >= '0' && tab[i][0] <= '9'))
			(bad_arg_check_saver(tab[i]));
		else
			ps_output(1);
		i++;
	}
	return (tab);
}

int			main(int ac, char **av)
{
	const char	*str;
	t_pslist	*list;
	t_psflag	flag;

	list = NULL;
	flag_init(&flag);
	str = "/Users/myener/Desktop/homework/push_swap/push_swap";
	if (!(ac >= 2))
		return (0);
	if (((!ft_strcmp(av[1], "")) || (av[1][0] == ' ')) && !av[2])
		ps_output(1);
	av = bad_arg_checker(av, &flag);
	if ((flag.ch = (!ft_strcmp(av[0], "./checker")) && av[1]))
		checker(list, &flag, av);
	else if (((flag.ps = (!ft_strcmp(av[0], "./push_swap") || flag.visual)
	|| !ft_strcmp(av[0], str))))
		push_swap(list, &flag, av);
	else if ((flag.ch = (!ft_strcmp(av[0], "./checker")) && !av[1]))
		return (0);
	else
		ps_output(1);
	return (0);
}
