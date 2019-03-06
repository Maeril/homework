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

void        printer_minus(t_data *data, int len)
{
    int i;
	int	ln;

	ln = (data->lngt->precision ? ((data->lngt->width_value - data->lngt->precision_value) + 3) : len + 2);
    i = -1;
    while (i++ < (data->lngt->width_value - len))
    	ft_putchar(' ');
}

void        printer_nominus(t_data *data, int len)
{
    int i;
	int	ln;

	// printf("\n\nwidth_value = %d\n\n", data->lngt->width_value);
	// printf("\n\nprec_value = %d\n\n", data->lngt->precision_value);
	ln = (data->lngt->precision ? (data->lngt->precision_value + 1): len + 1);
	if (data->lngt->precision && (data->type->x || data->type->big_x))
		ln += 2;
	// printf("\n\nln = %d\n\n", ln);
	// printf("\n\nlen = %d\n\n", len);
	i = -1;
	if (data->flag->zero)
    	while (i++ < (data->lngt->width_value - ln))
    		ft_putchar('0');
	else if (!data->flag->zero)
		while (i++ < (data->lngt->width_value - ln))
    		ft_putchar(' ');
	if ((data->type->x || data->type->big_x) && data->flag->sharp)
	{
		ft_putstr("0x");
		if (data->lngt->precision)
			len += 1;
	}
	if (data->flag->sharp && data->type->o && !data->lngt->precision)
		ft_putchar('0');
	i = -1;
	if (data->lngt->precision)
		while (i++ < (data->lngt->precision_value - len))
			ft_putchar('0');

}
