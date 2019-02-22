/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:53:22 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 21:49:47 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_unsign(va_list ap, t_data *data)
{
	long	out;

	if (data->type->u)
	{
		out = va_arg(ap, unsigned int);
		if (out < 0)
		{
			out = -out;
			out = (UINT_MAX - out);
			ft_putnbr_long(out);
		}
		else if (out >= 0)
			ft_putnbr_long(out);
	}
}
