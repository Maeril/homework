/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:58:14 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 17:27:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void		prt_precision(t_lngt *lngt, t_flag *flag, t_spec *spec)
{
	while (lngt->precision)
	{
		ft_putchar('0');
		lngt->precision = lngt->precision - 1;
	}
	if (flag->minus)
		return ;
	else
		ft_putnbr(spec->integer);
}

void		width_and_precision(t_lngt *lngt)
{
	if (lngt->width <= lngt->precision)
		lngt->width = 0;
	if (lngt->width > lngt->precision)
		lngt->width = lngt->precision - lngt->width;
}
