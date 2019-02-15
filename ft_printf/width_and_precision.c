/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:58:14 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 15:24:58 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf->h"


t_data		prt_precision(t_data data)
{
	while (data->precision)
	{
		ft_putchar('0');
		data->precision = data->precision - 1;
	}
	if (data->minus)
		return(data);
	else
		ft_putnbr(data->integer);
	return (data);
}

t_data		width_and_precision(t_data data)
{
	if (data->width <= data->precision)
		data->width = 0;
	if (data->width > data->precision)
		data->width = data->precision - data->width;
	return (data);
}
