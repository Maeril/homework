/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:50:30 by myener            #+#    #+#             */
/*   Updated: 2019/03/06 17:22:09 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        widthprinter_minus(t_data *data, int len)
{
    int i;

	len += 2;
    i = -1;
    while (i++ < (data->lngt->width_value - len))
    	ft_putchar(' ');
}

void        widthprinter_nominus(t_data *data, int len)
{
    int i;

	// printf("\n\nwidth_value = %d\n\n", data->lngt->width_value);
	// printf("\n\nprec_value = %d\n\n", data->lngt->precision_value);
	len += 1;
	// printf("\n\nln = %d\n\n", ln);
	// printf("\n\nlen = %d\n\n", len);
	i = -1;
	if (data->flag->zero)
    	while (i++ < (data->lngt->width_value - len))
    		ft_putchar('0');
	else if (!data->flag->zero)
		while (i++ < (data->lngt->width_value - len))
    		ft_putchar(' ');
	len -= 1;
}


void		precision_printer(t_data *data, int len)
{
	int	i;

	i = 0;
	while (i++ < (data->lngt->precision_value - len))
		ft_putchar('0');
}
