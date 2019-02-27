/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:32 by myener            #+#    #+#             */
/*   Updated: 2019/02/27 17:59:57 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_ptr(va_list ap, t_data *data)
{
    int     len;

	if (data->type->p)
	{
		data->type->p = va_arg(ap, int);
		len = (ft_hexlen(data->type->p) + 4);
		if ((data->lngt->width && data->lngt->width_value > 0) && !data->flag->minus)
			widthprinter_nominus(data, len);
        ft_putstr("0x10");
		ft_putnbr_base(data->type->p, HEXL);
		if ((data->lngt->width && data->lngt->width_value > 0) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
