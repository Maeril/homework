/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:53:22 by myener            #+#    #+#             */
/*   Updated: 2019/02/19 15:56:02 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
