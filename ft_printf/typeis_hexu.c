/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:08 by myener            #+#    #+#             */
/*   Updated: 2019/03/06 18:01:25 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_hexu(va_list ap, t_data *data)
{
	int		len;

	if (data->type->big_x)
	{
		data->type->big_x = va_arg(ap, int);
		len = (data->flag->sharp ? (ft_hexlen(data->type->big_x) + 2) : ft_hexlen(data->type->big_x));
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			printer_nominus(data, len);
		if (data->flag->sharp && data->type->big_x)
			ft_putstr("0X");
		ft_putnbr_base(data->type->big_x, HEXU);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			printer_minus(data, len);
	}
}
