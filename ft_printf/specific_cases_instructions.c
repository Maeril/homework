/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_cases_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:14:03 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 13:15:13 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

t_data		check_plus_flag(t_data data)
{
	if (data.plus == 1)
	{
		if (data.u == 1)
		{
			data.plus = 0;
			return (data);
		}
		if (data.o == 1 && (data.h == 1 || data.hh == 1 ||
					data.l == 1 || data.ll == 1))
		{
			data.plus = 0;
			return (data);
		}
		if (data.x == 1 && (data.h == 1 || data.hh == 1 ||
					data.l == 1 || data.ll == 1))
		{
			data.plus = 0;
			return (data);
		}
		if (data.X == 1 && (data.h == 1 || data.hh == 1 ||
					data.l == 1 || data.ll == 1))
		{
			data.plus = 0;
			return (data);
		}
	}
	return (data);
	// le but de cette fonction : enlever le flag '+' lorsque nous avons un type unsigned
	//  (y compris avec les hh/h/ll/l)
}


t_data		check_zero(t_data data)
{
	if (data.d == 1 || data.i == 1 || data.o == 1 || data.u == 1 || data.x == 1 ||
			data.X == 1)
		data.zero = 0;
	return(data);
}

t_data		check_sharp(t_data data)
{
	if (data.d == 1 || data.c == 1 || data.s == 1 || data.u == 1 || data.i == 1)
		data.sharp = 0;
	return (data);
}

t_data      finalize_instructions(t_data data)
{
	if (data.plus == 1)
		data = check_plus_flag(data);
	if (data.zero == 1 && data.minus == 1)
		data.minus = 0; // permet d'ignorer le flag '-' si on a deja un flag '0' 
	if (data.zero == 1 && data.precision == 1)
		data = check_zero(data);
	if (data.space == 1 && (data.d != 1 || data.i != 1))
		data.space = 0; // le flag 'espace' ne marche qu'avec un entier signe.
	if (data.space == 1 && (data.plus == 1 || data.minus == 1))
		data.space = 0;
	if (data.sharp == 1)
		data = check_sharp(data);
	if (data.precision == 1 && data.c == 1)
		data.precision = 0;

	return (data);

}

/* ELEMENTS A STOCKER DANS LA STRUCTURE 
 - width
 - precision
 - ce qu'il y a dans va_arg ? 

	

*/



/*

   - FAIT : si le flag '+' est utilise avec un unsigned, on a un warning et le resultat 
   n'affiche pas le signe. (unsigned = u, et hh, ll, l, h avec o,u,x,X)

   - FAIT : s'il y a a la fois les flags 0 et -, alors le flag - est totalement ignore. 

   - FAIT : s'il y a un flag 0 ET une precision ET un type ENTIER (diouxX), alors le 0 est ignore. 

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

   - si width + precision ? zero ou espace ? 
   - il y aura des zero (precision > width). 
   - si width est superieur a precision ? 
   - on met des espaces pour le surplus (width - precision) et le reste en zero. 
   - si width est inferieur a precision ? 
   - on met des zero a la pace des espaces.  

   - la precision :
   		- FAIT : c : la precision n'a pas d'effet 
		- RIEN A FAIRE : diouxXX : precision ne tronque pas le resultat. met des zero (ras quoi)
		- s : tronque si le resultat plus long que precision. 


	- A FAIRE : gerer le flag 0 avec les types s et c 

*/
