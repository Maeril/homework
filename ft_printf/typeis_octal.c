/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:59:01 by myener            #+#    #+#             */
/*   Updated: 2019/03/07 16:34:17 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void typeis_octal(va_list ap, t_data *data)
{
	int len;

	if (data->type->o)
	{
		data->type->o = va_arg(ap, int);
		len = ft_octlen(data->type->o);
		if (data->flag->sharp)
			len++;
		if (data->lngt->precision && (data->lngt->precision_value <= len))
			data->lngt->precision = 0;
		if (data->lngt->precision && (data->lngt->precision_value >= data->lngt->width_value))
			data->lngt->width = 0;
		if (data->lngt->precision && (data->lngt->precision_value < data->lngt->width_value) && !data->flag->sharp)
			data->lngt->width_value -= (data->lngt->precision_value - 2);
		else if (data->lngt->precision && (data->lngt->precision_value < data->lngt->width_value) && data->flag->sharp)
			data->lngt->width_value -= (data->lngt->precision_value - 3);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if (data->flag->sharp)
			ft_putchar('0');
		if (data->lngt->precision)
			precision_printer(data, len);
		ft_putnbr_base(data->type->o, OCT);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
