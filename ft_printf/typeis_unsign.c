/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:53:22 by myener            #+#    #+#             */
/*   Updated: 2019/02/28 16:27:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_unsign(va_list ap, t_data *data)
{
	int		len;
	long	out;

	if (data->type->u)
	{
		out = va_arg(ap, unsigned int);
		len = ft_uintlen(out);
		if (data->lngt->precision)
			precisionprint_int(data, len);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if (out < 0)
		{
			out = -out;
			out = (UINT_MAX - out);
			ft_putnbr_long(out);
		}
		else if (out >= 0)
			ft_putnbr_long(out);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
