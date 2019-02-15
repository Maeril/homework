/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:14:03 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 16:51:19 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		check_zero(t_data data)
{
	if (type->d || type->i || type->o || type->u || type->x || type->big_x)
		flag->zero = 0;
	return(data);
}

t_data		check_sharp(t_data data)
{
	if (type->d || type->c || type->s || type->u || type->i)
		flag->sharp = 0;
	return (data);
}

t_data		check_unsigned(t_data data)
{
	if (type->u || (type->o && (size->h || size->hh || size->l || size->ll))
		|| (type->x && (size->h || size->hh || size->l || size->ll )) || (type->big_x
		&& (size->h || size->hh || size->l || size->ll )))
		tool->unsign = 1;
	return (data);
}

t_data		finalize_instructions(t_data data)
{
	flag->plus = (flag->plus && !tool->unsign);
	flag->space = (flag->space && !flag->plus);/*ecriture super-simplifiee. dis moi si tu comprends pas ! -mae*/
	flag->zero = (flag->zero && !flag->minus);
	flag->space = (flag->space && (type->d || type->i));
//	data->precision = (data->precision && !data->c); > pb avec cette phrase :( elle met precision a 1... -ML
	if (lngt->precision && (type->d || type->i || type->o || data->u || data->x
		|| data->big_x))
		data->zero = 0;
	if (data->sharp && (data->d || data->c || data->s || data->u || data->i))
		data->sharp = 0;
	return (data);
}

/* ELEMENTS A STOCKER DANS LA STRUCTURE
 - width
 - precision
 - ce qu'il y a dans va_arg ?
	- A FAIRE AVEC LE FLAG ESPACE :
		- le flag ne marche pas si le resultat est negatif
   - les DIESES # :
   - avec un o => le # met un 0 devant le resultat
   - avec un x => le # met un 0x devant le resultat
   - avec un X => le # met un 0X devant le resultat
   - WIDTH ne provoque JAMAIS de troncature du resultat.
   - la PRECISION provoque une troncature du resultat
   - si width + precision ? zero ou espace ?
   - il y aura des zero (precision > width).
   - si width est superieur a precision ?
   - on met des espaces pour le surplus (width - precision) et le reste en zero.
   - si width est inferieur a precision ?
   - on met des zero a la pace des espaces.
   - la precision :
		- s : tronque si le resultat plus long que precision.
	- A FAIRE : gerer le flag 0 avec les types s et c
*/
