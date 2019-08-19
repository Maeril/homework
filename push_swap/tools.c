/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:21:03 by myener            #+#    #+#             */
/*   Updated: 2019/08/19 14:16:11 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		flag_init(t_psflag *flag)
{
	flag->ch = 0;
	flag->instruc = NULL;
	flag->np = 0;
	flag->nr = 0;
	flag->pivot = 0;
	flag->ps = 0;
}

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

void		ps_displayer(char **out)
{
	int	i;

	i = 0;
	while (out[i])
	{
		if (ft_strcmp(out[i], "na"))
			ft_putendl(out[i]);
		free(out[i]);
		i++;
	}
}

int			ps_output(int i)
{
	if (i == 1)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	else if (i == 2)
		write(1, "KO\n", 3);
	else if (i == 3)
		write(1, "OK\n", 3);
	return (0);
}

int			push_swap_saver(int i, int nb, t_pslist *list, t_psflag *flag)
{
	int		qs;

	qs = 0;
	(i = check_length(list)) == 0 ? list_free(list) : 0;
	(i = check_length(list)) == 0 ? exit(0) : 0;
	(i = check_length(list)) > 4 && (i <= 6) ? ps_bubblesort(&list, flag)
	: ps_quicksort(&list, 0, nb, flag);
	if (!((i = check_length(list)) > 4 && (i <= 6)))
		qs = 1;
	return (qs);
}
