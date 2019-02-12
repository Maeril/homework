/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:56:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/12 16:26:53 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

t_data		typeis_int(va_list ap, t_data data)
{

	int 		i;
	short		j;
	long		k;
	long long	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;

	if (data.integer)
	{
		i = va_arg(ap, int);
		ft_putnbr(i);
	}
	else if (data.sh)
	{
		j = va_arg(ap, int);
		ft_putnbr(j);
	}
	else if (data.lg)
	{
		k = va_arg(ap, long);
		ft_putnbr(k);
	}
	else if (data.lglg)
	{
		l = va_arg(ap, long long);
		ft_putnbr(l);
	}
	return (data);
}

t_data		typeis_char(va_list ap, t_data data)
{
	char		c;
	char	*str;

	if (data.car)
	{
		c = va_arg(ap, int);
		ft_putchar(c);
	}
	else if (data.str)
	{
		str = va_arg(ap, char *);
		ft_putstr(str);
	}
	return (data);
}

t_data		typeis_unsign(va_list ap, t_data data)
{
	unsigned char 			uchar;
	unsigned short			ush;
	unsigned long			ulong;
	unsigned long long 		ulonglong;
	unsigned int			n;

	if (data.unsigncar)
	{
		data.unsign = 1;
		uchar = va_arg(ap, int);
		ft_putchar(uchar);
	}
	else if (data.unsignsh)
	{
		data.unsign = 1;
		ush = va_arg(ap, int);
		ft_putnbr(ush);
	}
	else if (data.unsignlg)
	{
		data.unsign = 1;
		ulong = va_arg(ap, unsigned long);
		ft_putnbr(ulong);
	}
	else if (data.unsignlglg)
	{
		data.unsign = 1;
		ulonglong = va_arg(ap, unsigned long long);
		ft_putnbr(ulonglong);
	}
	else if (data.unint)
	{
		data.unsign = 1;
		n = va_arg(ap, unsigned int);
		ft_putnbr(n);
	}
	return (data);
}

t_data		find_arg_type(va_list ap, t_data data)
{
	if (data.space && (data.d || data.i))
		ft_putchar(' ');
	if (data.plus && !data.unsign)
		ft_putchar('+');
	if (data.zero)
		ft_putnbr('0');
	if (data.minus && data.width)

	if (data.d || data.i || data.o || data.x || data.big_x)
		data.integer = 1;
	data.car = (data.car && data.c);
	data.str = (data.str && (data.s || data.p));
	data.unint = (data.unint && data.u);
	if (data.d || data.i)
	{
		data.signcar = (data.signcar && data.hh);
		data.sh = (data.sh && data.h);
		data.lg = (data.lg && data.l);
		data.lglg = (data.lglg && data.ll);
	}
	if (data.o || data.u || data.x || data.big_x)
	{
		data.unsigncar = (data.unsigncar && data.hh);
		data.unsignsh = (data.unsignsh && data.h);
		data.unsignlglg = (data.unsignlglg && data.ll);
		data.unsignlg = (data.unsignlg && data.l);
	}
	if (data.integer || data.sh || data.lg || data.lglg)
		data = typeis_int(ap, data);
	if (data.car || data.str)
		data = typeis_char(ap, data);
	if (data.unsigncar || data.unsignsh || data.unsignlg || data.unsignlglg || data.unint)
		data = typeis_unsign(ap, data);
	return (data);
}
