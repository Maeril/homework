/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:42 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 21:59:27 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_char(va_list ap, t_data *data)
{
	char		c;

	if (data->type->c)
	{
		c = va_arg(ap, int);
		data->spec->car = c;
		ft_putchar(data->spec->car);
	}
}