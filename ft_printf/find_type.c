/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:56:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 16:33:58 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

t_data		typeis_int(va_list ap, t_spec spec)
{

	int 		i;
	short		j;
	long		k;
	long long	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;

	if (spec->integer)
	{
		i = va_arg(ap, int);
		spec->integer = i;
		ft_putnbr(spec->integer);
	}
	else if (spec->sh)
	{
		j = va_arg(ap, int);
		ft_putnbr(j);
	}
	else if (spec->lg)
	{
		k = va_arg(ap, long);
		ft_putnbr(k);
	}
	else if (spec->lglg)
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

	if (type->c)
	{
		c = va_arg(ap, int);
		spec->car = c;
	}
	else if (type->s)
	{
		str = va_arg(ap, char *);
		tool->str_tp = str;
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

	if (spec->unsigncar)
	{
		tool->unsign = 1;
		uchar = va_arg(ap, int);
		ft_putchar(uchar);
	}
	else if (spec->unsignsh)
	{
		tool->unsign = 1;
		ush = va_arg(ap, int);
		ft_putnbr(ush);
	}
	else if (spec->unsignlg)
	{
		tool->unsign = 1;
		ulong = va_arg(ap, unsigned long);
		ft_putnbr(ulong);
	}
	else if (spec->unsignlglg)
	{
		tool->unsign = 1;
		ulonglong = va_arg(ap, unsigned long long);
		ft_putnbr(ulonglong);
	}
	else if (spec->unint)
	{
		tool->unsign = 1;
		n = va_arg(ap, unsigned int);
		ft_putnbr(n);
	}
	return (data);
}

t_data		typeis_perc(t_data data)
{
	if (lngt->width)
	{
		tool->nb_printed = lngt->width;
		while (lngt->width > 1)
		{
			ft_putchar(' ');
			lngt->width--;
		}
		ft_putchar('%');
	}
	lngt->width = 0;
	return (data);
}

t_data		find_arg_type(va_list ap, t_data data)
{
	if (flag->space && (type->d || type->i))
		ft_putchar(' '); // je  pense qu'il faudra enlever cette condition et ligne-> 
	if (flag->plus && !tool->unsign)
	{
	}
		// Je suis en train de tester le fait d'enlever la ligne en dessous et je pense que ca va aussi etre necessaire->->-> :) 
	//	ft_putchar('+');
//	}
//	if (data->zero)
//		ft_putnbr('0'); --> ML : je pense qu'il faut supprimer ces lignes-> 

//	if (data->minus && data->width) // j'ai mis la ligne en sourdine car je pense quelle est pas finie ^^ 

	if (type->d == 1 || type->i == 1 || type->o == 1 || type->x == 1 || type->big_x == 1)
	{
		spec->integer = 1;
	}
	spec->car = (type->c && type->c); // est ce qu'on peut reduire cette ligne ? data->car = data->c ?
//	data->str = (data->str && (data->s || data->p)); je met en sourdine en attendant (voir ligne ci dessus)
	spec->str = (type->s || type->p);
	spec->unint = (spec->unint && type->u);


// je teste l'affichage de o ici
	if (type->o)
		data = print_octal(data, ap);

	if (type->d || type->i)
	{
		spec->signcar = (spec->signcar && size->hh);
		spec->sh = (spec->sh && size->h);
		spec->lg = (spec->lg && size->l);
		spec->lglg = (spec->lglg && size->ll);
	}
	if (type->o || type->u || type->x || type->big_x)
	{
		spec->unsigncar = (spec->unsigncar && size->hh);
		spec->unsignsh = (spec->unsignsh && size->h);
		spec->unsignlglg = (spec->unsignlglg && size->ll);
		spec->unsignlg = (spec->unsignlg && size->l);
	}
	if (spec->integer || spec->sh || spec->lg || spec->lglg)
		data = typeis_int(ap, data);
	if (spec->car || type->s)
		data = typeis_char(ap, data);
	if (spec->unsigncar || spec->unsignsh || spec->unsignlg || spec->unsignlglg || spec->unint)
		data = typeis_unsign(ap, data);

	if (type->pourcentage)
		data = pourcentage(data);

//	if (data->perc)
//		data = typeis_perc(data);
	return (data);
}