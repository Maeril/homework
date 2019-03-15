/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:02 by myener            #+#    #+#             */
/*   Updated: 2019/03/15 17:17:01 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void typeis_hexl(va_list ap, t_data *data)
{
	int len;

	if (data->type->x)
	{
		data->type->x = va_arg(ap, unsigned long long int);
		if (data->tool->size)
		{
			if (data->size->h)
				data->type->x = ((unsigned short)data->type->x);
			else if (data->size->hh)
				data->type->x = ((unsigned char)data->type->x);
			else if (data->size->l)
				data->type->x = ((unsigned long)data->type->x);
		}
		len = ft_hexlen(data->type->x);
		if (data->flag->sharp)
			len++;
		if ((data->lngt->prec && data->lngt->width) && (data->lngt->width_value >= data->lngt->prec_value))
			data->lngt->width_value -= data->lngt->prec_value;
		else if ((data->lngt->prec && data->lngt->width) && (data->lngt->width_value < data->lngt->prec_value))
			data->lngt->width = 0;
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if (data->flag->sharp)
			ft_putstr("0x");
		if (data->lngt->prec && !data->flag->sharp)
			precision_printer(data, len);
		else if (data->lngt->prec && data->flag->sharp)
			precision_printer(data, (len - 1));
		ft_putunbr_base(data->type->x, HEXL);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
