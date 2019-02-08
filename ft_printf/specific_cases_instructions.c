/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_cases_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:14:03 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 17:39:03 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

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
	printf("a la fin de find arg type, data.integer = %d\n", data.integer);
	if (data.integer == 1)
		data = ft_typeis_int(ap, data);
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

t_data		finalize_instructions(t_data data)
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

/*ELEMENTS A STOCKER DANS LA STRUCTURE
 - width
 - precision
 - ce qu'il y a dans va_arg ?
   - FAIT : si le flag '+' est utilise avec un unsigned, on a un warning et
	le resultat n'affiche pas le signe. (unsigned = u, et hh, ll, l, h avec
	o,u,x,X)
   - FAIT : s'il y a un flag 0 ET une precision ET un type ENTIER (diouxX),
   alors le 0 est ignore.
	- A FAIRE AVEC LE FLAG ESPACE :
		- FAIT : le flag marche avec un d ou un i.
		- FAIT : le flag espace est ignore si c'est avec un plus ou un moins
		- le flag ne marche pas si le resultat est negatif
   - les DIESES # :
   - FAIT le diese est ignore quand il est utilise avec d, c et s, u et i.
   - avec un o => le # met un 0 devant le resultat
   - avec un x => le # met un 0x devant le resultat
   - avec un X => le # met un 0X devant le resultat
   - WIDTH ne provoque JAMAIS de troncature du resultat.
   - la PRECISION provoque une troncature du resultat
   - on met des espaces pour le surplus (width - precision) et le reste en
   zero.
   - si width est inferieur a precision ?
   - on met des zero a la pace des espaces.
   - la precision :
   		- FAIT : c : la precision n'a pas d'effet
		- RIEN A FAIRE : diouxXX : precision ne tronque pas le resultat.
		met des zero (ras quoi)
		- s : tronque si le resultat plus long que precision.

*/
