/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:27:54 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 16:48:31 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				measure_width_len(t_data data, int len)
{
	if (lngt->precision && lngt->precision > 0)
		lngt->width = lngt->width - lngt->precision;
	if (lngt->precision && data->zero)
	{
		lngt->precision = lngt->width; // a ameliorer
		lngt->width = 0;
	}
	if (lngt->width && !lngt->precision)
		lngt->width = lngt->width - len;
	return (lngt->width);
}

int				measure_precision_len(t_data data, int len)
{
	if (len >= lngt->precision)
		lngt->precision = 0;
	else
		lngt->precision = lngt->precision - len;
	return (lngt->precision);
}


t_data			cancel_stuff(t_data data)
{
	if (flag->plus)
		flag->plus = 0;
	if (flag->space)
		flag->space = 0;
	return (data);
}

void			go_width(t_data data)
{
	if (lngt->width)
	{
		while (lngt->width)
		{
			ft_putchar(' ');
			lngt->width = lngt->width - 1;
			tool->nb_a = tool->nb_a + 1;
		}
	}
}

void			go_precision(t_data data)
{
	if (lngt->precision)
	{
		while (lngt->precision)
		{
			ft_putchar('0');
			lngt->precision = lngt->precision - 1;
			tool->nb_a = tool->nb_a + 1;
		}
	}
}

t_data			print_octal(t_data data, va_list ap)
{

	/* A finir pour terminer la conversion de o :
	 - il faut gerer le cas ou il y a une precision sans nombre (%5->o)
	 - tout verif et ce sera bon :D
	 */
	int len;

	type->o = va_arg(ap, int);
	type->o = conv_octal(type->o);
	len = ft_strlen(ft_itoa(type->o));

	if (lngt->width)
	{
		lngt->width = measure_width_len(data, len);
		if (flag->zero)
		{
			lngt->precision = lngt->width;
			lngt->width = 0;
		}
		if (flag->sharp)
		{
			if (lngt->precision)
				flag->sharp = 0;
			else if (!lngt->precision)
				lngt->width -= 1;
		}
	}
	if (lngt->precision)
		lngt->precision = measure_precision_len(data, len);
	if (lngt->precision_dot && flag->zero)
		flag->zero = 0;
	if (flag->plus || flag->space)
		data = cancel_stuff(data);
	if (!flag->minus)
	{
		go_width(data);
		go_precision(data);
		if (flag->sharp)
		{
			ft_putchar('0');
			tool->nb_a += 1;
		}
		tool->nb_a += len;
	}
	else if (flag->minus)
	{
		go_precision(data);
		if (flag->sharp)
			ft_putchar('0');
		go_width(data);
	}
	ft_putnbr(type->o);
	return (data);
}
