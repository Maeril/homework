/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:47 by myener            #+#    #+#             */
/*   Updated: 2019/02/19 17:23:59 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
