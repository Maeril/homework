/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:02 by myener            #+#    #+#             */
/*   Updated: 2019/03/13 17:39:40 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void typeis_hexl(va_list ap, t_data *data)
{
	int len;

	if (data->type->x)
	{
		data->type->x = va_arg(ap, int);
		if (!data->tool->size)
			len = ft_hexlen(data->type->x);
		else if (data->tool->size)
		{
			if (data->size->h)
				len = ft_hexlen((unsigned short)data->type->x);
			else if (data->size->hh)
				len = ft_hexlen((unsigned char)data->type->x);
			else if (data->size->l)
				len = ft_hexlen((unsigned long)data->type->x);
			else if (data->size->ll)
				len = ft_hexlen((unsigned long long)data->type->x);
		}
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
			precision_printer(data, len - 1);
		if (!data->tool->size)
			ft_putnbr_base(data->type->x, HEXL);
		else if (data->tool->size)
		{
			if (data->size->h)
				ft_putnbr_base(((unsigned short)data->type->x), HEXL);
			else if (data->size->hh)
				ft_putnbr_base(((unsigned char)data->type->x), HEXL);
			else if (data->size->l)
				ft_putnbr_base(((unsigned long)data->type->x), HEXL);
			else if (data->size->ll)
				ft_putnbr_base(data->type->x, HEXL);
		}
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
