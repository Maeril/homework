/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <mpicard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:56:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/14 18:24:46 by mpicard          ###   ########.fr       */
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
		data.integer = i;
		ft_putnbr(data.integer);
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

	if (data.c)
	{
		c = va_arg(ap, int);
		data.car = c;
	}
	else if (data.s)
	{
		str = va_arg(ap, char *);
		data.str_tp = str;
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

t_data		typeis_perc(t_data data)
{
	if (data.width)
	{
		data.nb_printed = data.width;
		while (data.width > 1)
		{
			ft_putchar(' ');
			data.width--;
		}
		ft_putchar('%');
	}
	data.width = 0;
	return (data);
}

t_data		find_arg_type(va_list ap, t_data data)
{
	if (data.space && (data.d || data.i))
		ft_putchar(' '); // je  pense qu'il faudra enlever cette condition et ligne. 
	if (data.plus && !data.unsign)
	{
	}
		// Je suis en train de tester le fait d'enlever la ligne en dessous et je pense que ca va aussi etre necessaire... :) 
	//	ft_putchar('+');
//	}
//	if (data.zero)
//		ft_putnbr('0'); --> ML : je pense qu'il faut supprimer ces lignes. 

//	if (data.minus && data.width) // j'ai mis la ligne en sourdine car je pense quelle est pas finie ^^ 

	if (data.d == 1 || data.i == 1 || data.o == 1 || data.x == 1 || data.big_x == 1)
	{
		data.integer = 1;
	}
	data.car = (data.c && data.c); // est ce qu'on peut reduire cette ligne ? data.car = data.c ?
//	data.str = (data.str && (data.s || data.p)); je met en sourdine en attendant (voir ligne ci dessus)
	data.str = (data.s || data.p);
	data.unint = (data.unint && data.u);


// je teste l'affichage de o ici 
	if (data.o)
		data = print_octal(data, ap);

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
	if (data.car || data.s)
		data = typeis_char(ap, data);
	if (data.unsigncar || data.unsignsh || data.unsignlg || data.unsignlglg || data.unint)
		data = typeis_unsign(ap, data);

	if (data.pourcentage)
		data = pourcentage(data);

//	if (data.perc)
//		data = typeis_perc(data);
	return (data);
}