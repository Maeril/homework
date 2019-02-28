/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:38 by myener            #+#    #+#             */
/*   Updated: 2019/02/28 00:55:52 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_str(va_list ap, t_data *data)
{
    int     len;

	if (data->tool->str_tp || data->type->s)
	{
		data->tool->str_tp = va_arg(ap, char*);
		len = ft_strlen(data->tool->str_tp);
		// printf("minus = %d, width = %d, width_value = %d\n", data->flag->minus, data->lngt->width, data->lngt->width_value);
		if ((data->lngt->width && data->lngt->width_value) && (!data->flag->minus))
			widthprinter_nominus(data, len);
		ft_putstr(data->tool->str_tp);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
