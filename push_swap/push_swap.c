/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:52:32 by myener            #+#    #+#             */
/*   Updated: 2020/01/06 19:04:38 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_displayer(char **out)
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

static t_pslist	*push_swap_saver(int i, int nb, t_pslist *list, t_psflag *flag)
{
	if ((i = check_length(list)) == 0)
	{
		list_free(list);
		exit(0);
	}
	flag->t = nb + 1;
	if (i == 5)
		insertion_sort(&list, 5, flag);
	else
		ps_quicksort(&list, 0, nb, flag);
	return (list);
}

char			**push_swap(t_pslist *list, t_psflag *flag, char **argv)
{
	int			i;
	int			nb;
	int			ret;
	char		**output;

	list = convertto_list(argv, list, &nb, flag);
	((ret = duplicate_finder(list))) && flag->ps ? list_free(list) : 0;
	ret && flag->ps ? ps_output(1) : 0;
	i = check_list(list);
	if (i == 1 || (i == 0 && flag->ps))
	{
		list = (i == 1) ? push_swap_saver(0, nb, list, flag) : list;
		list_free(list);
		(i == 0 && flag->ps) ? exit(0) : 0;
	}
	output = flag->instruc ? ft_spacesplit(flag->instruc) : NULL;
	output && ft_strlen(flag->instruc) > 4 ? papb_cleaner(output) : 0;
	output && ft_strlen(flag->instruc) > 4 ? rotate_cleaner(output, flag) : 0;
	if (flag->ch)
		return (flag->instruc ? output : NULL);
	flag->ps ? ps_displayer(output) : 0;
	free(output);
	free(flag->instruc);
	return (NULL);
}
