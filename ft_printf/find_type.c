/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:56:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 19:57:21 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void		typeis_int(va_list ap, t_spec *spec)
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
}

void		typeis_char(va_list ap, t_data *data)
{
	char		c;
	char	*str;

	if (data->type->c)
	{
		c = va_arg(ap, int);
		data->spec->car = c;
	}
	else if (data->type->s)
	{
		str = va_arg(ap, char *);
		data->tool->str_tp = str;
	}
}

void		typeis_unsign(va_list ap, t_tool *tool, t_spec *spec)
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
}

void		typeis_perc(t_lngt *lngt, t_tool *tool)
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
}

void		find_arg_type(va_list ap, t_data *data)
{
	if (data->flag->space && (data->type->d || data->type->i))
		ft_putchar(' '); // je  pense qu'il faudra enlever cette condition et ligne
	if (data->flag->plus && !data->tool->unsign)
	{
	}
		// Je suis en train de tester le fait d'enlever la ligne en dessous et je pense que ca va aussi etre necessaire->->-> :) 
	//	ft_putchar('+');
//	}
//	if (data->flag->zero)
//		ft_putnbr('0'); --> ML : je pense qu'il faut supprimer ces lignes

//	if (data->flag->minus && data->lngt->width) // j'ai mis la ligne en sourdine car je pense quelle est pas finie ^^ 

	if (data->type->d == 1 || data->type->i == 1 || data->type->o == 1
		|| data->type->x == 1 || data->type->big_x == 1)
	{
		data->spec->integer = 1;
	}
	data->spec->car = (data->spec->car && data->type->c); // est ce qu'on peut reduire cette ligne ? data->car = data->c ?
//	data->spec->str = (data->spec->str && (data->type->s || data->type->p)); je met en sourdine en attendant (voir ligne ci dessus)
	data->spec->str = (data->type->s || data->type->p);
	data->spec->unint = (data->spec->unint && data->type->u);


// je teste l'affichage de o ici
	if (data->type->o)
		print_octal(data, ap);

	if (data->type->d || data->type->i)
	{
		data->spec->signcar = (data->spec->signcar && data->size->hh);
		data->spec->sh = (data->spec->sh && data->size->h);
		data->spec->lg = (data->spec->lg && data->size->l);
		data->spec->lglg = (data->spec->lglg && data->size->ll);
	}
	if (data->type->o || data->type->u || data->type->x || data->type->big_x)
	{
		data->spec->unsigncar = (data->spec->unsigncar && data->size->hh);
		data->spec->unsignsh = (data->spec->unsignsh && data->size->h);
		data->spec->unsignlglg = (data->spec->unsignlglg && data->size->ll);
		data->spec->unsignlg = (data->spec->unsignlg && data->size->l);
	}
	if (data->spec->integer || data->spec->sh || data->spec->lg || data->spec->lglg)
		typeis_int(ap, data->spec);
	if (data->spec->car || data->type->s)
		typeis_char(ap, data);
	if (data->spec->unsigncar || data->spec->unsignsh || data->spec->unsignlg
		|| data->spec->unsignlglg || data->spec->unint)
		typeis_unsign(ap, data->tool, data->spec);
	if (data->type->pourcentage)
		pourcentage(data);
//	if (data->tool->perc)
//		typeis_perc(data);
}