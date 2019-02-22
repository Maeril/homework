/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:59:01 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 21:09:26 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_octal(va_list ap, t_data *data)
{
	if (data->type->o)
	{
		data->type->o = va_arg(ap, int);
		ft_putnbr_base(data->type->o, OCT);
	}
}
