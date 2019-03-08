/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:47 by myener            #+#    #+#             */
/*   Updated: 2019/03/08 15:10:04 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void typeis_int(va_list ap, t_data *data)
{
	int nb;
	int len;

	if (data->spec->integer || data->spec->sh)
	{
		nb = va_arg(ap, int);
		len = ((nb < 0) ? (ft_intlen(nb) + 2) : ft_intlen(nb));
		len = ((data->flag->plus && nb > 0) || (data->flag->space && nb > 0)
			|| (data->flag->plus && data->flag->space && nb > 0) ?
			(len + 1) : len);
		if (data->lngt->precision && (data->lngt->precision_value <= len))
			data->lngt->precision = 0;
		if (data->lngt->precision && (data->lngt->precision_value >= data->lngt->width_value))
			data->lngt->width = 0;
		if (data->lngt->precision && (data->lngt->precision_value < data->lngt->width_value))
			data->lngt->width_value -= (data->lngt->precision_value - 2);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if ((nb > 0) && data->flag->plus)
			ft_putchar('+');
		if ((nb > 0) && data->flag->space)
			ft_putchar(' ');
		if (data->lngt->precision)
			precision_printer(data, len);
		ft_putnbr(nb);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
	else if (data->spec->lg || data->spec->lglg)
	{
		data->spec->lg ? (nb = va_arg(ap, long)) : (nb = va_arg(ap, long long));
		len = ((nb < 0) ? (ft_intlen(nb) + 2) : ft_intlen(nb));
		len = ((data->flag->plus && nb > 0) || (data->flag->space && nb > 0)
			|| (data->flag->plus && data->flag->space && nb > 0) ?
			(len + 1) : len);
		if (data->lngt->precision && (data->lngt->precision_value <= len))
			data->lngt->precision = 0;
		if (data->lngt->precision && (data->lngt->precision_value >= data->lngt->width_value))
			data->lngt->width = 0;
		if (data->lngt->precision && (data->lngt->precision_value < data->lngt->width_value))
			data->lngt->width_value -= (data->lngt->precision_value - 2);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if ((nb > 0) && data->flag->plus)
			ft_putchar('+');
		if ((nb > 0) && data->flag->space && !data->flag->plus)
			ft_putchar(' ');
		if (data->lngt->precision)
			precision_printer(data, len);
		ft_putnbr(nb);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
