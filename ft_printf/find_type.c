/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:56:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/11 14:45:08 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
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

	if (data.integer == 1)
	{
		i = va_arg(ap, int);
		ft_putnbr(i);
	}
	else if (data.sh == 1)
	{
		j = va_arg(ap, int);
		ft_putnbr(j);
	}
	else if (data.lg == 1)
	{
		k = va_arg(ap, long);
		ft_putnbr(k);
	}
	else if (data.lglg == 1)
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

	if (data.car == 1)
	{
		c = va_arg(ap, int);
		ft_putchar(c);
	}
	else if (data.str == 1)
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

	if (data.unsigncar == 1)
	{
		uchar = va_arg(ap, int);
		ft_putchar(uchar);
	}
	else if (data.unsignsh == 1)
	{
		ush = va_arg(ap, int);
		ft_putnbr(ush);
	}
	else if (data.unsignlg == 1)
	{
		ulong = va_arg(ap, unsigned long);
		ft_putnbr(ulong);
	}
	else if (data.unsignlglg == 1)
	{
		ulonglong = va_arg(ap, unsigned long long);
		ft_putnbr(ulonglong);
	}
	else if (data.unint == 1)
	{
		n = va_arg(ap, unsigned int);
		ft_putnbr(n);
	}
	return (data);
}

t_data		find_arg_type(va_list ap, t_data data, char *instruc, int i)
{
	if (data.d == 1 || data.i == 1 || data.o == 1 || data.x == 1
		|| data.big_x == 1)
		data.integer = 1;
	data.c == 1 ? data.car = 1 : 0;
	(data.s == 1 || data.p == 1) ? data.str = 1 : 0;
	data.u == 1 ? data.unint = 1 : 0;
	if (data.d == 1 || data.i == 1)
	{
		data.hh == 1 ? data.signcar = 1 : 0;
		data.h == 1 ? data.sh = 1 : 0;
		data.l == 1 ? data.lg = 1 : 0;
		data.ll == 1 ? data.lglg = 1 : 0;
	}
	if (data.o == 1 || data.u == 1 || data.x == 1 || data.big_x == 1)
	{
		data.hh == 1 ? data.unsigncar = 1 : 0;
		data.h == 1 ? data.unsignsh = 1 : 0;
		data.ll == 1 ? data.unsignlglg = 1 : 0;
		data.l == 1 ? data.unsignlg = 1 : 0;
	}
//	printf("a la fin de find arg type, data.integer = %d\n", data.integer);
	if (data.integer == 1 || data.sh == 1 || data.lg == 1 || data.lglg == 1)
		data = typeis_int(ap, data);
	if (data.car == 1 || data.str == 1)
		data = typeis_char(ap, data);
	if (data.unsigncar == 1 || data.unsignsh == 1 || data.unsignlg == 1 ||
			data.unsignlglg == 1 || data.unint == 1)
		data = typeis_unsign(ap, data);
	return (data);
}
