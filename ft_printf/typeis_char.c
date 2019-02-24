/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:42 by myener            #+#    #+#             */
/*   Updated: 2019/02/24 22:48:59 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_char(va_list ap, t_data *data)
{
	char	c;
	int   	i;
    int     len;

	len = 1;
	if (data->type->c)
	{
		if ((data->lngt->width && data->lngt->width_value > 0) && !data->flag->minus)
		{
			i = 0;
        	while (i < (data->lngt->width_value - len))
      		{
          		ft_putchar(' ');
            	i++;
        	}
		}
		c = va_arg(ap, int);
		data->spec->car = c;
		ft_putchar(data->spec->car);
		if ((data->lngt->width && data->lngt->width_value > 0) && data->flag->minus)
		{
			i = 0;
        	while (i < (data->lngt->width_value - len))
      		{
          		ft_putchar(' ');
            	i++;
        	}
		}
	}
}