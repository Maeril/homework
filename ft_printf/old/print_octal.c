/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:27:54 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 19:57:24 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				measure_width_len(t_lngt *lngt, t_flag *flag, int len)
{
	if (lngt->precision && lngt->precision > 0)
		lngt->width = lngt->width - lngt->precision;
	if (lngt->precision && flag->zero)
	{
		lngt->precision = lngt->width; // a ameliorer
		lngt->width = 0;
	}
	if (lngt->width && !lngt->precision)
		lngt->width = lngt->width - len;
	return (lngt->width);
}

int				measure_precision_len(t_lngt *lngt, int len)
{
	if (len >= lngt->precision)
		lngt->precision = 0;
	else
		lngt->precision = lngt->precision - len;
	return (lngt->precision);
}


void			cancel_stuff(t_flag *flag)
{
	if (flag->plus)
		flag->plus = 0;
	if (flag->space)
		flag->space = 0;
}

void			go_width(t_lngt *lngt, t_tool *tool)
{
	if (lngt->width)
		while (lngt->width)
		{
			ft_putchar(' ');
			lngt->width = lngt->width - 1;
			tool->nb_a = tool->nb_a + 1;
		}
}

void			go_precision(t_lngt *lngt, t_tool *tool)
{
	if (lngt->precision)
		while (lngt->precision)
		{
			ft_putchar('0');
			lngt->precision = lngt->precision - 1;
			tool->nb_a = tool->nb_a + 1;
		}
}

void			print_octal(t_data *data, va_list ap)
{

	/* A finir pour terminer la conversion de o :
	 - il faut gerer le cas ou il y a une precision sans nombre (%5->o)
	 - tout verif et ce sera bon :D
	 */
	int len;

	data->type->o = va_arg(ap, int);
	data->type->o = conv_octal(data->type->o);
	len = ft_strlen(ft_itoa(data->type->o));

	if (data->lngt->width)
	{
		data->lngt->width = measure_width_len(data->lngt, data->flag, len);
		if (data->flag->zero)
		{
			data->lngt->precision = data->lngt->width;
			data->lngt->width = 0;
		}
		if (data->flag->sharp)
		{
			if (data->lngt->precision)
				data->flag->sharp = 0;
			else if (!data->lngt->precision)
				data->lngt->width -= 1;
		}
	}
	if (data->lngt->precision)
		measure_precision_len(data->lngt, len);
	if (data->lngt->precision_dot && data->flag->zero)
		data->flag->zero = 0;
	if (data->flag->plus || data->flag->space)
		cancel_stuff(data->flag);
	if (!data->flag->minus)
	{
		go_width(data->lngt, data->tool);
		go_precision(data->lngt, data->tool);
		if (data->flag->sharp)
		{
			ft_putchar('0');
			data->tool->nb_a += 1;
		}
		data->tool->nb_a += len;
	}
	else if (data->flag->minus)
	{
		go_precision(data->lngt, data->tool);
		if (data->flag->sharp)
			ft_putchar('0');
		go_width(data->lngt, data->tool);
	}
	ft_putnbr(data->type->o);
}
