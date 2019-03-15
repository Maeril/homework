/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:53:22 by myener            #+#    #+#             */
/*   Updated: 2019/03/15 17:20:50 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_unsign(va_list ap, t_data *data)
{
	int				len;

	if (data->type->u)
	{
		data->type->u = va_arg(ap, unsigned long long int);
		if (data->tool->size)
		{
			if (data->size->h)
				data->type->u = ((unsigned short)data->type->u);
			else if (data->size->hh)
				data->type->u = ((unsigned char)data->type->u);
			else if (data->size->l)
				data->type->u = ((unsigned long)data->type->u);
		}
		len = ft_uintlen(data->type->u);
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
		// if (data->type->u < 0)
		// {
		// 	data->type->u = -data->type->u;
		// 	data->type->u = (UINT_MAX - data->type->u);
		// }
		if (data->lngt->prec)
			precision_printer(data, len);
		ft_putunbr_long(data->type->u);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
