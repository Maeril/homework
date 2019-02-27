/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:02 by myener            #+#    #+#             */
/*   Updated: 2019/02/27 17:58:00 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_hexl(va_list ap, t_data *data)
{
    int     len;

	if (data->type->x)
	{
		data->type->x = va_arg(ap, int);
		len = ft_hexlen(data->type->x);
		if ((data->lngt->width && data->lngt->width_value > 0) && !data->flag->minus)
			widthprinter_nominus(data, len);
		ft_putnbr_base(data->type->x, HEXL);
		if ((data->lngt->width && data->lngt->width_value > 0) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
