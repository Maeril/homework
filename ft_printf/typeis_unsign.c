/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:53:22 by myener            #+#    #+#             */
/*   Updated: 2019/03/13 17:38:30 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_unsign(va_list ap, t_data *data)
{
	int		len;
	long	out;

	if (data->type->u)
	{
		out = va_arg(ap, unsigned int);
		if (!data->tool->size)
			len = ft_uintlen(out);
		else if (data->tool->size)
		{
			if (data->size->h)
				len = ft_uintlen((unsigned short)out);
			else if (data->size->hh)
				len = ft_uintlen((unsigned char)out);
			else if (data->size->l)
				len = ft_uintlen((unsigned long)out);
			else if (data->size->ll)
				len = ft_uintlen((unsigned long long)out);
		}
		if (data->lngt->prec && (data->lngt->prec_value <= len))
			data->lngt->prec = 0;
		if (data->lngt->prec && (data->lngt->prec_value >= data->lngt->width_value))
			data->lngt->width = 0;
		if (data->lngt->prec && (data->lngt->prec_value < data->lngt->width_value) && !data->tool->size)
			data->lngt->width_value -= (data->lngt->prec_value - 2);
		else if (data->lngt->prec && (data->lngt->prec_value < data->lngt->width_value) && data->tool->size)
			data->lngt->width_value -= (data->lngt->prec_value);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if (out < 0)
		{
			out = -out;
			out = (UINT_MAX - out);
		}
		if (data->lngt->prec)
			precision_printer(data, len);
		if (!data->tool->size)
			ft_putnbr_long(out);
		else if (data->tool->size)
		{
			if (data->size->h)
				ft_putnbr_long((unsigned short)out);
			else if (data->size->hh)
				ft_putnbr_long((unsigned char)out);
			else if (data->size->l)
				ft_putnbr_long((unsigned long)out);
			else if (data->size->ll)
				ft_putnbr_long((unsigned long long)out);
		}
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
