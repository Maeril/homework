/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:02 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 21:09:28 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_hexl(va_list ap, t_data *data)
{
	if (data->type->x)
	{
		data->type->x = va_arg(ap, int);
		ft_putnbr_base(data->type->x, HEXL);
	}
}
