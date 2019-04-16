/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:29:00 by myener            #+#    #+#             */
/*   Updated: 2019/04/16 18:37:39 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_parser(t_lsflag *lsflag, char *str)
{
	int		i;

	i = 1; // et pas 0, pour sauter le '-'
	while (str[i])
	{
		lsflag->R = (str[i] == 'R');
		lsflag->a = (str[i] == 'a');
		lsflag->l = (str[i] == 'l');
		lsflag->r = (str[i] == 'r');
		lsflag->t = (str[i] == 't');
		lsflag->flag = (lsflag->R || lsflag->a || lsflag->l || lsflag->r
			|| lsflag->t);
		i++;
	}
}