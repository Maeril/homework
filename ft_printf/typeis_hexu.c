/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:08 by myener            #+#    #+#             */
/*   Updated: 2019/02/27 17:58:03 by myener           ###   ########.fr       */
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
		if ((data->lngt->width && data->lngt->width_value > 0) && !data->flag->minus)
			widthprinter_nominus(data, len);
		ft_putnbr_base(data->type->big_x, HEXU);
		if ((data->lngt->width && data->lngt->width_value > 0) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
