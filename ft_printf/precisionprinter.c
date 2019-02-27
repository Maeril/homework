/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisionprinter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:58:14 by myener            #+#    #+#             */
/*   Updated: 2019/02/27 18:14:21 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		precisionprinter(t_data *data)
{
	while (data->lngt->precision)
	{
		ft_putchar('0');
		data->lngt->precision = data->lngt->precision - 1;
	}
	if (data->flag->minus)
		return ;
	else
		ft_putnbr(data->spec->integer);
}