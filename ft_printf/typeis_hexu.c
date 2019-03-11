/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:08 by myener            #+#    #+#             */
/*   Updated: 2019/03/11 14:20:09 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_hexu(va_list ap, t_data *data)
{
	int		len;

	if (data->type->big_x)
	{
		data->type->big_x = va_arg(ap, int);
		len = ft_hexlen(data->type->big_x);
		if (data->flag->sharp)
			len++;
		// printf("\nzero = %d\n", data->flag->zero);
		// printf("\nprecision value = %d\n", data->lngt->precision_value);
		// printf("width value = %d\n\n", data->lngt->width_value);
		if ((data->lngt->precision && data->lngt->width) && (data->lngt->width_value >= data->lngt->precision_value))
			data->lngt->width_value -= data->lngt->precision_value;
		else if ((data->lngt->precision && data->lngt->width) && (data->lngt->width_value < data->lngt->precision_value))
			data->lngt->width = 0;
		// printf("\nprecision value = %d\n", data->lngt->precision_value);
		// printf("width value = %d\n\n", data->lngt->width_value);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if (data->flag->sharp)
			ft_putstr("0X");
		if (data->lngt->precision && !data->flag->sharp)
			precision_printer(data, len);
		else if (data->lngt->precision && data->flag->sharp)
			precision_printer(data, len - 1);
		ft_putnbr_base(data->type->big_x, HEXU);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
