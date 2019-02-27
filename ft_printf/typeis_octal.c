/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:59:01 by myener            #+#    #+#             */
/*   Updated: 2019/02/27 17:58:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_octal(va_list ap, t_data *data)
{
    int     len;

	if (data->type->o)
	{
		data->type->o = va_arg(ap, int);
		len = ft_octlen(data->type->o);
		if ((data->lngt->width && data->lngt->width_value > 0) && !data->flag->minus)
			widthprinter_nominus(data, len);
		ft_putnbr_base(data->type->o, OCT);
		if ((data->lngt->width && data->lngt->width_value > 0) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
