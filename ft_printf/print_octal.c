/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:27:54 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/14 14:18:44 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				measure_width_len(t_data data, int len)
{
	if (data.precision && data.precision > 0)
		data.width = data.width - data.precision;
	if (data.precision && data.zero)
	{
		data.precision = data.width; // a ameliorer 
		data.width = 0;
	}
	if (data.width && !data.precision)
		data.width = data.width - len;
	return (data.width);
}

int				measure_precision_len(t_data data, int len)
{
	if (len >= data.precision)
		data.precision = 0;
	else
		data.precision = data.precision - len;
	return (data.precision);
}


t_data			cancel_stuff(t_data data)
{
	if (data.plus)
		data.plus = 0;
	if (data.space)
		data.space = 0;
	return (data);
}

void			go_width(t_data data)
{
	if (data.width)
	{
		while (data.width)
		{
			ft_putchar(' ');
			data.width = data.width - 1;
			data.nb_a = data.nb_a + 1;
		}
	}
}

void			go_precision(t_data data)
{
	if (data.precision)
	{
		while (data.precision)
		{
			ft_putchar('0');
			data.precision = data.precision - 1;
			data.nb_a = data.nb_a + 1;
		}
	}
}

t_data			print_octal(t_data data, va_list ap)
{

	/* A finir pour terminer la conversion de o :
	 - il faut gerer le cas ou il y a une precision sans nombre (%5.o)
	 - tout verif et ce sera bon :D
	 */
	int len;

	data.o = va_arg(ap, int);
	data.o = conv_octal(data.o);
	len = ft_strlen(ft_itoa(data.o));

	if (data.width)
	{
		data.width = measure_width_len(data, len);
		if (data.zero)
		{
			data.precision = data.width;
			data.width = 0;
		}
		if (data.sharp)
		{
			if (data.precision)
				data.sharp = 0;
			else if (!data.precision)
				data.width -= 1;
		}
	}
	if (data.precision)
		data.precision = measure_precision_len(data, len);
	if (data.precision_dot && data.zero)
		data.zero = 0;
	if (data.plus || data.space)
		data = cancel_stuff(data);
	if (!data.minus)
	{
		go_width(data);
		go_precision(data);
		if (data.sharp)
		{
			ft_putchar('0');
			data.nb_a += + 1;
		}
		data.nb_a += len;
	}
	else if (data.minus)
	{
		go_precision(data);
		if (data.sharp)
			ft_putchar('0');
		go_width(data);
	}
	ft_putnbr(data.o);
	return (data);
}
