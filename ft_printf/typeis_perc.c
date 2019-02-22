/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_perc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:57:23 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 21:09:40 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_perc(va_list ap, t_data *data)
{
	char	c;

	if (data->tool->perc)
	{
		c = va_arg(ap, int);
		data->tool->perc = c;
		ft_putchar('%');
	}
}
