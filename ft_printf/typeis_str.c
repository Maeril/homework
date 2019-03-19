/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:38 by myener            #+#    #+#             */
/*   Updated: 2019/03/19 18:18:51 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		typeis_str(va_list ap, t_data *data)
{
	int		i;
    int     len;

	if (data->tool->str_tp || data->type->s)
	{
		data->tool->str_tp = va_arg(ap, char*);
		len = ft_strlen(data->tool->str_tp);
		if (data->lngt->width && (data->lngt->width_value <= len))
			data->lngt->width = 0;
		if ((data->lngt->prec && data->lngt->width) && (data->lngt->width_value < data->lngt->prec_value))
			data->lngt->width = 0;
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && len > 0) || len)
		{
			if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && !data->lngt->prec)
				widthprinter_nominus(data, len);
			else if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus && data->lngt->prec)
				widthprinter_nominus(data, data->lngt->prec_value);
			if (data->lngt->prec && ((data->lngt->prec_value <= len) && (data->lngt->prec_value > 1)))
			{
				i = -1;
				while (i++ < (data->lngt->prec_value - 1))
					ft_putchar(data->tool->str_tp[i]);
			}
			else if (!data->lngt->prec)
				ft_putstr(data->tool->str_tp);
			if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
				widthprinter_minus(data, len);
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return (data->lngt->width_value);
	}
	return (-1);
}
