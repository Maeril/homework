/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_perc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:57:23 by myener            #+#    #+#             */
/*   Updated: 2019/03/06 17:58:23 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_perc(va_list ap, t_data *data)
{
	int	len;

	if (data->tool->perc)
	{
		data->tool->perc = va_arg(ap, int);
		len = 1;
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			printer_nominus(data, len);
		ft_putchar('%');
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			printer_minus(data, len);
	}
}
