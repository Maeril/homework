/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:08 by myener            #+#    #+#             */
/*   Updated: 2019/03/19 18:06:41 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		typeis_hexu(va_list ap, t_data *data)
{
	int		len;

	if (data->type->big_x)
	{
		data->type->big_x = va_arg(ap, unsigned long long int);
		if (!data->tool->size)
			data->type->big_x = ((unsigned int)data->type->big_x);
		else if (data->tool->size)
		{
			if (data->size->h)
				data->type->big_x = ((unsigned short int)data->type->big_x);
			else if (data->size->hh)
				data->type->big_x = ((unsigned char)data->type->big_x);
			else if (data->size->l)
				data->type->big_x = ((unsigned long int)data->type->big_x);
		}
		len = ft_hexlen(data->type->big_x);
		if (data->flag->sharp)
			len++;
		if (data->lngt->width && (data->lngt->width_value <= len))
			data->lngt->width = 0;
		if ((data->lngt->prec && data->lngt->width) && (data->lngt->width_value < data->lngt->prec_value))
			data->lngt->width = 0;
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && data->type->big_x > 0) || data->type->big_x)
		{
		// printf("width = %d, len = %d", data->lngt->width_value, len);
			if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && !data->lngt->prec)
				widthprinter_nominus(data, len);
			else if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && data->lngt->prec)
				widthprinter_nominus(data, data->lngt->prec_value);
			if (data->flag->sharp)
				ft_putstr("0X");
			if (data->lngt->prec && !data->flag->sharp && (data->lngt->prec_value >= len))
				precision_printer(data, len);
			else if (data->lngt->prec && data->flag->sharp && (data->lngt->prec_value >= len))
				precision_printer(data, len - 1);
			ft_putunbr_base(data->type->big_x, HEXU);
			if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
				widthprinter_minus(data, len);
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return (data->lngt->width_value);
	}
	return (-1);
}
