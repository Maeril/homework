/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:59:01 by myener            #+#    #+#             */
/*   Updated: 2019/03/19 17:53:25 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		typeis_octal(va_list ap, t_data *data)
{
	int 		len;

	if (data->type->o)
	{
		data->type->o = va_arg(ap, int);
		if (!data->tool->size)
			data->type->o = ((unsigned int)data->type->o);
		else if (data->tool->size)
		{
			if (data->size->h)
				data->type->o = ((unsigned short int)data->type->o);
			else if (data->size->hh)
				data->type->o = ((unsigned char)data->type->o);
			else if (data->size->l)
				data->type->o = ((unsigned long int)data->type->o);
		}
		len = ft_octlen(data->type->o);
		if (data->flag->sharp)
			len++;
		if (data->lngt->prec && (data->lngt->prec_value <= len))
			data->lngt->prec = 0;
		// if (data->lngt->prec && (data->lngt->prec_value >= data->lngt->width_value))
		// 	data->lngt->width = 0;
		if (data->lngt->width && (data->lngt->width_value <= len))
			data->lngt->width = 0;
		if ((data->lngt->prec && data->lngt->width) && (data->lngt->width_value < data->lngt->prec_value))
			data->lngt->width = 0;
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && data->type->o > 0) || data->type->o)
		{
			if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && !data->lngt->prec)
				widthprinter_nominus(data, len);
			else if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && data->lngt->prec)
				widthprinter_nominus(data, data->lngt->prec_value);
			if (data->flag->sharp)
				ft_putchar('0');
			if (data->lngt->prec)
				precision_printer(data, len);
			ft_putunbr_base(data->type->o, OCT);
			if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
				widthprinter_minus(data, len);
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return(data->lngt->width_value);
	}
	return (-1);
}
