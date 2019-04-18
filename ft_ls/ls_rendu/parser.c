/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:29:00 by myener            #+#    #+#             */
/*   Updated: 2019/04/18 14:30:48 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_parser(t_lsflag *lsflag, char *str)
{
	int		i;

	i = 1; // et pas 0, pour sauter le '-'
	while ((str[i] && str[i] != ' ') || str[i])
	{
		if (str[i] == 'R')
			lsflag->R = 1;
		if (str[i] == 'a')
			lsflag->a = 1;
		if (str[i] == 'l')
			lsflag->l = 1;
		if (str[i] == 'r')
			lsflag->r = 1;
		if (str[i] == 't')
			lsflag->t = 1;
		if (lsflag->R || lsflag->a || lsflag->l || lsflag->r || lsflag->t)
			lsflag->flag = 1;
		i++;
	}
}