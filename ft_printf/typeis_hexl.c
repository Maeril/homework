/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:02 by myener            #+#    #+#             */
/*   Updated: 2019/03/19 17:48:16 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int typeis_hexl(va_list ap, t_data *data)
{
	int len;

	if (data->type->x)
	{
		data->type->x = va_arg(ap, unsigned long long int);
		if (!data->tool->size)
			data->type->x = ((unsigned int)data->type->x);
		else if (data->tool->size)
		{
			if (data->size->h)
				data->type->x = ((unsigned short int)data->type->x);
			else if (data->size->hh)
				data->type->x = ((unsigned char)data->type->x);
			else if (data->size->l)
				data->type->x = ((unsigned long int)data->type->x);
		}
		len = ft_hexlen(data->type->x);
		if (data->flag->sharp)
			len++;
		if (data->lngt->width && (data->lngt->width_value <= len))
			data->lngt->width = 0;
		if ((data->lngt->prec && data->lngt->width) && (data->lngt->width_value < data->lngt->prec_value))
			data->lngt->width = 0;
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && (data->type->x > 0)) || data->type->x)
		{
			if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && !data->lngt->prec)
				widthprinter_nominus(data, len);
			else if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && data->lngt->prec)
				widthprinter_nominus(data, data->lngt->prec_value);
			if (data->flag->sharp)
				ft_putstr("0x");
			if (data->lngt->prec && !data->flag->sharp)
				precision_printer(data, len);
			else if (data->lngt->prec && data->flag->sharp)
				precision_printer(data, (len - 1));
			ft_putunbr_base(data->type->x, HEXL);
			if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
				widthprinter_minus(data, len);
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return(data->lngt->width_value);
	}
	return (-1);
}
