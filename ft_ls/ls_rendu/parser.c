/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:29:00 by myener            #+#    #+#             */
/*   Updated: 2019/04/25 17:19:37 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_parser(t_lsflag *lsflag, char *str)
{
	int		i;

	i = 1;
	while ((str[i] && str[i] != ' ') || str[i])
	{
		if (str[i] == 'R')
			lsflag->big_r = 1;
		if (str[i] == 'a')
			lsflag->a = 1;
		if (str[i] == 'l')
			lsflag->l = 1;
		if (str[i] == 'r')
			lsflag->r = 1;
		if (str[i] == 't')
			lsflag->t = 1;
		if (lsflag->big_r || lsflag->a || lsflag->l || lsflag->r || lsflag->t)
			lsflag->flag = 1;
		if (lsflag->r && lsflag->t)
		{
			lsflag->r = 0;
			lsflag->t = 0;
		}
		i++;
	}
}
