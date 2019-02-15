/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:26:34 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 16:40:22 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		prt_width(t_data data, char *str)
{
	int		size;
	int		space_to_add;

	space_to_add = 0;
	size = ft_strlen(str);
	if (size < lngt->width)
	{
		space_to_add = lngt->width - size;
		while (space_to_add)
		{
			ft_putchar(' ');
			space_to_add--;
		}
	}
	return (data);
}

t_data		prt_int_width(t_data data) /* bon modele a reproduire */
{
	char	*str;
	int		lgt;

	str = ft_itoa(spec->integer);
	lgt = ft_strlen(str);
	if (flag->minus)
	{
		ft_putnbr(spec->integer);
		data = flag_minus(data, lgt);
	}
	else if (!flag->minus)
	{
		prt_width(data, str);
		ft_putnbr(spec->integer);
	}
	return (data);
}

t_data		prt_unint_width(t_data data)
{
	char	*str;
	int		lgt;

	str = ft_itoa(spec->unint);
	lgt = ft_strlen(str);
	if (flag->minus)
	{
		ft_putnbr(spec->unint);
		data = flag_minus(data, lgt);
	}
	else if (!flag->minus)
	{
		prt_width(data, str);
		ft_putnbr(spec->unint);
	}
	return (data);
}

t_data		prt_str_width(t_data data)
{
	int		lgt;

	lgt = ft_strlen(tool->str_tp);

	if (flag->minus)
	{
		ft_putstr(tool->str_tp);
		data = flag_minus(data, lgt);
	}
	else if (!flag->minus)
	{
		prt_width(data, tool->str_tp);
		ft_putstr(tool->str_tp);
	}
	return (data);
}

t_data		prt_car_width(t_data data)
{
	lngt->width = lngt->width - 1;
	if (flag->minus)
	{
		ft_putchar(spec->car);
		data = flag_minus(data, 1);
	}
	else if (!flag->minus)
	{
		while (lngt->width)
		{
			ft_putchar(' ');
			lngt->width--;
		}
		ft_putchar(spec->car);
	}
	return (data);
}

t_data		print_all(t_data data)
{
	if (spec->integer)
		lngt->width ? data = prt_int_width(data) : ft_putnbr(spec->integer);
	if (spec->str)
		lngt->width ? data = prt_str_width(data) : ft_putstr(tool->str_tp);
	if (spec->car)
	{
		(spec->width && data->width > 1) ?
		spec = prt_car_width(data) : ft_putchar(spec->car);
	}
	if (spec->unint)
		lngt->width ? data = prt_unint_width(data) : ft_putnbr(spec->unint);
	if (spec->signcar)
	{
		(spec->width && lngt->width > 1) ?
		spec = : ft_putchar(spec->signcar);
	}
	if (spec->sh)
		lngt->width ? data = : ft_putnbr(spec->sh);
	if (spec->lg)
		lngt->width ? data = : ft_putnbr(spec->lg);
	if (spec->lglg)
		lngt->width ? data = : ft_putnbr(spec->lglg);
	if (spec->unsigncar)
	{
		(spec->width && data->width > 1) ?
		spec = : ft_putnbr(data->unsigncar);
	}
	if (spec->unsignsh)
		lngt->width ? data = : ft_putnbr(spec->unsignsh);
	if (spec->unsignlg)
		lngt->width ? data = : ft_putnbr(spec->unsignlg);
	if (spec->unsignlglg)
		lngt->width ? data = : ft_putnbr(spec->unsignlglg);
	return (data);
}
