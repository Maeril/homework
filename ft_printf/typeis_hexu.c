/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:08 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 21:09:34 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_hexu(va_list ap, t_data *data)
{
	if (data->type->big_x)
	{
		data->type->big_x = va_arg(ap, int);
		ft_putnbr_base(data->type->big_x, HEXU);
	}
}
