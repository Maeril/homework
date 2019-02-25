/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:08 by myener            #+#    #+#             */
/*   Updated: 2019/02/25 18:08:23 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_hexu(va_list ap, t_data *data)
{
	int		i;
	int		len;

	if (data->type->big_x)
	{
		data->type->big_x = va_arg(ap, int);
		len = ft_hexlen(data->type->big_x);
		if ((data->lngt->width && data->lngt->width_value > 0) && !data->flag->minus)
		{
			i = 0;
			if (data->flag->zero)
			{
        		while (i < (data->lngt->width_value - len))
      			{
          			ft_putchar('0');
            		i++;
        		}
			}
			else if (!data->flag->zero)
			{
				while (i < (data->lngt->width_value - len))
      			{
          			ft_putchar(' ');
            		i++;
        		}
			}
		}
		ft_putnbr_base(data->type->big_x, HEXU);
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
