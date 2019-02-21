/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_perc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:57:23 by myener            #+#    #+#             */
/*   Updated: 2019/02/19 15:58:03 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_perc(t_lngt *lngt, t_tool *tool)
{
	if (lngt->width)
	{
		tool->nb_printed = lngt->width;
		while (lngt->width > 1)
		{
			ft_putchar(' ');
			lngt->width--;
		}
		ft_putchar('%');
	}
	lngt->width = 0;
}
