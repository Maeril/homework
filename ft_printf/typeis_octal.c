/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:59:01 by myener            #+#    #+#             */
/*   Updated: 2019/03/15 17:18:29 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void typeis_octal(va_list ap, t_data *data)
{
	int 		len;

	if (data->type->o)
	{
		data->type->o = va_arg(ap, int);
		if (data->tool->size)
		{
			if (data->size->h)
				data->type->o = ((unsigned short)data->type->o);
			else if (data->size->hh)
				data->type->o = ((unsigned char)data->type->o);
			else if (data->size->l)
				data->type->o = ((unsigned long)data->type->o);
		}
		len = ft_octlen(data->type->o);
		if (data->flag->sharp)
			len++;
		if (data->lngt->prec && (data->lngt->prec_value <= len))
			data->lngt->prec = 0;
		if (data->lngt->prec && (data->lngt->prec_value >= data->lngt->width_value))
			data->lngt->width = 0;
		if (data->lngt->prec && (data->lngt->prec_value < data->lngt->width_value) && !data->flag->sharp)
			data->lngt->width_value -= data->lngt->prec_value;
		else if (data->lngt->prec && (data->lngt->prec_value < data->lngt->width_value) && data->flag->sharp)
			data->lngt->width_value -= (data->lngt->prec_value - 3);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if (data->flag->sharp)
			ft_putchar('0');
		if (data->lngt->prec)
			precision_printer(data, len);
		ft_putunbr_base(data->type->o, OCT);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
