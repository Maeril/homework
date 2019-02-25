/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:38 by myener            #+#    #+#             */
/*   Updated: 2019/02/25 16:49:37 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_str(va_list ap, t_data *data)
{
	int   	i;
    int     len;

	if (data->tool->str_tp || data->type->s)
	{
		data->tool->str_tp = va_arg(ap, char*);
		len = ft_strlen(data->tool->str_tp);
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
		ft_putstr(data->tool->str_tp);
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
