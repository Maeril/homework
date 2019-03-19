/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:42 by myener            #+#    #+#             */
/*   Updated: 2019/03/18 15:55:49 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		typeis_char(va_list ap, t_data *data)
{
    int     len;

	if (data->type->c)
	{
		data->spec->car = va_arg(ap, int);
		len = 1;
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		ft_putchar(data->spec->car);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
		return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
	}
	return (-1);
}