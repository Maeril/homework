/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:38 by myener            #+#    #+#             */
/*   Updated: 2019/03/06 17:58:49 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_str(va_list ap, t_data *data)
{
	int		i;
    int     len;

	if (data->tool->str_tp || data->type->s)
	{
		data->tool->str_tp = va_arg(ap, char*);
		len = ft_strlen(data->tool->str_tp);
		if ((data->lngt->width && data->lngt->width_value) && (!data->flag->minus))
			printer_nominus(data, len);
		if (data->lngt->precision)
		{
			i = -1;
			while (i++ < (data->lngt->precision - 1))
				ft_putchar(data->tool->str_tp[i]);
		}
		else if (!data->lngt->precision)
			ft_putstr(data->tool->str_tp);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			printer_minus(data, len);
	}
}
