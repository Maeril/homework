/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:14:03 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/11 14:57:27 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

t_data		check_zero(t_data data)
{
	if (data.d == 1 || data.i == 1 || data.o == 1 || data.u == 1 || data.x == 1 ||
			data.big_x == 1)
		data.zero = 0;
	return(data);
}

t_data		check_sharp(t_data data)
{
	if (data.d == 1 || data.c == 1 || data.s == 1 || data.u == 1 || data.i == 1)
		data.sharp = 0;
	return (data);
}

t_data		check_unsigned(t_data data)
{
	if ((data.u == 1) || (data.o == 1 && (data.h == 1 || data.hh == 1 ||
		data.l == 1 || data.ll == 1)) || (data.x == 1 && (data.h == 1 ||
		data.hh == 1 || data.l == 1 || data.ll == 1)) || (data.big_x == 1
		&& (data.h == 1 || data.hh == 1 || data.l == 1 || data.ll == 1)))
		data.unsign = 1;
	return (data);
}

t_data		spec_instructions(t_data data)
{
	data.unsign == 1 ? data.plus == 0 : 0;
	data.plus == 1 ? data.space = 0 : 0;
	data.minus == 1 ? data.zero = 0 : 0;
	(data.d != 1 || data.i != 1) ? data.space = 0 : 0;
	data.c == 1 ? data.precision = 0 : 0;
	if (data.precision == 1 && (data.d == 1 || data.i == 1 || data.o == 1 ||
		data.u == 1 || data.x == 1 || data.big_x == 1))
		data.zero = 0;
	if (data.sharp == 1 && (data.d == 1 || data.c == 1 || data.s == 1 ||
		data.u == 1 || data.i == 1))
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
