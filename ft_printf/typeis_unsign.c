/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:53:22 by myener            #+#    #+#             */
/*   Updated: 2019/03/19 17:55:09 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		typeis_unsign(va_list ap, t_data *data)
{
	int				len;

	if (data->type->u)
	{
		data->type->u = va_arg(ap, int);
		if (!data->tool->size)
			data->type->u = ((unsigned int)data->type->u);
		else if (data->tool->size)
		{
			if (data->size->h)
				data->type->u = ((unsigned short int)data->type->u);
			else if (data->size->hh)
				data->type->u = ((unsigned char)data->type->u);
			else if (data->size->l)
				data->type->u = ((unsigned long int)data->type->u);
		}
		len = ft_uintlen(data->type->u);
		if (data->lngt->prec && (data->lngt->prec_value <= len))
			data->lngt->prec = 0;
		if (data->lngt->prec && (data->lngt->prec_value >= data->lngt->width_value))
			data->lngt->width = 0;
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && data->type->u > 0) || data->type->u)
		{
			if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && !data->lngt->prec)
				widthprinter_nominus(data, len);
			else if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && data->lngt->prec)
				widthprinter_nominus(data, data->lngt->prec_value);
			if (data->lngt->prec)
				precision_printer(data, len);
			ft_putunbr_long(data->type->u);
			if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
				widthprinter_minus(data, len);
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return(data->lngt->width_value);
	}
	return (-1);
}
