/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:14:03 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/13 18:23:20 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		check_zero(t_data data)
{
	if (data.d || data.i || data.o || data.u || data.x || data.big_x)
		data.zero = 0;
	return(data);
}

t_data		check_sharp(t_data data)
{
	if (data.d || data.c || data.s || data.u || data.i)
		data.sharp = 0;
	return (data);
}

t_data		check_unsigned(t_data data)
{
	if (data.u || (data.o && (data.h || data.hh || data.l || data.ll))
		|| (data.x && (data.h || data.hh || data.l || data.ll )) || (data.big_x
		&& (data.h || data.hh || data.l || data.ll )))
		data.unsign = 1;
	return (data);
}

t_data		finalize_instructions(t_data data)
{
	data.plus = (data.plus && !data.unsign);
	data.space = (data.space && !data.plus);/*ecriture super-simplifiee. dis moi si tu comprends pas ! -mae*/
	data.zero = (data.zero && !data.minus);
	data.space = (data.space && (data.d || data.i));
//	data.precision = (data.precision && !data.c); > pb avec cette phrase :( elle met precision a 1.... -ML
	if (data.precision && (data.d || data.i || data.o || data.u || data.x
		|| data.big_x))
		data.zero = 0;
	if (data.sharp && (data.d || data.c || data.s || data.u || data.i))
		data.sharp = 0;
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
