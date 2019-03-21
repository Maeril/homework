/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:47 by myener            #+#    #+#             */
/*   Updated: 2019/03/21 16:28:25 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int typeis_int(va_list ap, t_data *data)
{
	long long int nb;
	int len;

	if (data->type->d || data->type->i)
	{
		nb = va_arg(ap, long long int);
		if ((((int)nb) < 0) && !data->tool->size)
			nb = (((int)nb));
		if (data->tool->size)
		{
			if (data->size->h)
				nb = ((short)nb);
			else if (data->size->hh)
				nb = ((char)nb);
			else if (data->size->l)
				nb = ((long)nb);
		}
		len = ((nb < 0) ? (ft_intlen(nb) + 1) : ft_intlen(nb));
		if ((data->flag->plus && (nb > 0) && data->flag->zero) || (data->flag->plus && nb >= 0))
		{
			len++;
			if (data->lngt->prec)
				data->lngt->prec_value++;
		}
		if (nb < 0  && data->lngt->prec)
				data->lngt->prec_value++;
		data->flag->space = (data->flag->space && (nb >= 0));
		if (data->lngt->width && (data->lngt->width_value <= len))
			data->lngt->width = 0;
		if ((data->lngt->prec && data->lngt->width) && (data->lngt->width_value < data->lngt->prec_value))
			data->lngt->width = 0;
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && nb > 0) || nb == 0 || nb)
		{
			if (!data->flag->zero)
			{
				if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && !data->lngt->prec)
					widthprinter_nominus(data, len);
				else if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && data->lngt->prec)
					widthprinter_nominus(data, data->lngt->prec_value);
			}
			if (nb < 0)
			{
				ft_putchar('-');
				nb = -nb;
			}
			else if (data->flag->plus && (nb >= 0))
				ft_putchar('+');
			if (data->flag->space && !data->flag->plus && !data->lngt->width)
				ft_putchar(' ');
			if (data->flag->zero)
			{
				if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && !data->lngt->prec)
					widthprinter_nominus(data, len);
				else if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && data->lngt->prec)
					widthprinter_nominus(data, data->lngt->prec_value);
			}
			if (data->lngt->prec)
				precision_printer(data, len);
			if (nb != 0 || (nb == 0 && !data->lngt->prec_zero && !data->lngt->prec_rien))
				ft_putnbr_long(nb);
			if ((data->lngt->width && (data->lngt->width_value > 0))
				&& data->flag->minus)
			{
				if (nb == 0 && data->lngt->prec)
					data->lngt->width_value--;
				widthprinter_minus(data, len);
			}
			if (data->lngt->prec_value && (data->lngt->prec_value > data->lngt->width_value))
				data->lngt->width_value += data->lngt->prec_value;
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return (data->lngt->width_value);
	}
	return (-1);
}
