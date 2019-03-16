/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:08 by myener            #+#    #+#             */
/*   Updated: 2019/03/16 18:04:57 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_hexu(va_list ap, t_data *data)
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
		if ((data->lngt->prec && data->lngt->width) && (data->lngt->width_value >= data->lngt->prec_value))
			data->lngt->width_value -= data->lngt->prec_value;
		else if ((data->lngt->prec && data->lngt->width) && (data->lngt->width_value < data->lngt->prec_value))
			data->lngt->width = 0;
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if (data->flag->sharp)
			ft_putstr("0X");
		if (data->lngt->prec && !data->flag->sharp)
			precision_printer(data, len);
		else if (data->lngt->prec && data->flag->sharp)
			precision_printer(data, len - 1);
		ft_putunbr_base(data->type->big_x, HEXU);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
