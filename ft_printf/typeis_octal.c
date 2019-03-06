/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:59:01 by myener            #+#    #+#             */
/*   Updated: 2019/03/06 18:02:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_octal(va_list ap, t_data *data)
{
    int     len;

	if (data->type->o)
	{
		data->type->o = va_arg(ap, int);
		len = ((ft_octlen(data->type->o) <= 1) ? ft_octlen(data->type->o) + 1 :
			ft_octlen(data->type->o));
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			printer_nominus(data, len);
		if (data->flag->sharp && data->type->o)
			ft_putchar('0');
		ft_putnbr_base(data->type->o, OCT);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			printer_minus(data, len);
	}
}
