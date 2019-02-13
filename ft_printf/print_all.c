/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:26:34 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/13 20:35:16 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		prt_width(t_data data, char *str)
{
	int		size;
	int		space_to_add;

	space_to_add = 0;
	size = ft_strlen(str);
	if (size < data.width)
	{
		space_to_add = data.width - size;
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

	str = ft_itoa(data.integer);
	lgt = ft_strlen(str);
	if (data.minus)
	{
		ft_putnbr(data.integer);
		data = flag_minus(data, lgt);
	}
	else if (!data.minus)
	{
		prt_width(data, str);
		ft_putnbr(data.integer);
	}
	return (data);
}

t_data		prt_unint_width(t_data data)
{
	char	*str;
	int		lgt;

	str = ft_itoa(data.unint);
	lgt = ft_strlen(str);
	if (data.minus)
	{
		ft_putnbr(data.unint);
		data = flag_minus(data, lgt);
	}
	else if (!data.minus)
	{
		prt_width(data, str);
		ft_putnbr(data.unint);
	}
	return (data);
}

t_data		prt_str_width(t_data data)
{
	int		lgt;

	lgt = ft_strlen(data.str_tp);

	if (data.minus)
	{
		ft_putstr(data.str_tp);
		data = flag_minus(data, lgt);
	}
	else if (!data.minus)
	{
		prt_width(data, data.str_tp);
		ft_putstr(data.str_tp);
	}
	return (data);
}

t_data		prt_car_width(t_data data)
{
	data.width = data.width - 1;
	if (data.minus)
	{
		ft_putchar(data.car);
		data = flag_minus(data, 1);
	}
	else if (!data.minus)
	{
		while (data.width)
		{
			ft_putchar(' ');
			data.width--;
		}
		ft_putchar(data.car);
	}
	return (data);
}

t_data		print_all(t_data data)
{
	if (data.integer)
		data.width ? data = prt_int_width(data) : ft_putnbr(data.integer);
	if (data.str)
		data.width ? data = prt_str_width(data) : ft_putstr(data.str_tp);
	if (data.car)
	{
		(data.width && data.width > 1) ?
		data = prt_car_width(data) : ft_putchar(data.car);
	}
	if (data.unint)
		data.width ? data = prt_unint_width(data) : ft_putnbr(data.unint);
	if (data.signcar)
	{
		(data.width && data.width > 1) ?
		data = : ft_putchar(data.signcar);
	}
	if (data.sh)
		data.width ? data = : ft_putnbr(data.sh);
	if (data.lg)
		data.width ? data = : ft_putnbr(data.lg);
	if (data.lglg)
		data.width ? data = : ft_putnbr(data.lglg);
	if (data.unsigncar)
	{
		(data.width && data.width > 1) ?
		data = : ft_putnbr(data.unsigncar);
	}
	if (data.unsignsh)
		data.width ? data = : ft_putnbr(data.unsignsh);
	if (data.unsignlg)
		data.width ? data = : ft_putnbr(data.unsignlg);
	if (data.unsignlglg)
		data.width ? data = : ft_putnbr(data.unsignlglg);
	return (data);
}
