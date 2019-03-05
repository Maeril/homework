/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision_printer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:50:30 by myener            #+#    #+#             */
/*   Updated: 2019/03/03 19:55:03 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        widthprinter_minus(t_data *data, int len)
{
    int i;

    i = 0;
    while (i < (data->lngt->width_value - len))
    {
    	ft_putchar(' ');
    	i++;
    }
}

void        widthprinter_nominus(t_data *data, int len)
{
    int i;

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

void		precisionprint_int(t_data *data, int len)
{
	int	i;

	i = 0;
	if (len < data->lngt->precision_value)
	{
		while (i < (data->lngt->precision_value - len))
    		{
    			ft_putchar('0');
    			i++;
    		}
	}
}
