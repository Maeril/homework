/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:14:03 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/25 14:58:51 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		finalize_instructions(t_data *data)
{
	data->flag->plus = (data->flag->plus && !data->tool->unsign);
	data->flag->space = (data->flag->space && !data->flag->plus);
	data->flag->zero = (data->flag->zero && !data->flag->minus);
	data->flag->space = (data->flag->space && (data->type->d
						|| data->type->i));
	if (data->lngt->precision && (data->type->d || data->type->i
		|| data->type->o || data->type->u || data->type->x
		|| data->type->big_x))
		data->flag->zero = 0;
	if (data->flag->sharp && (data->type->d || data->type->c || data->type->s
		|| data->type->u || data->type->i))
		data->flag->sharp = 0;
	// check zero
	if (data->type->d || data->type->i || data->type->o || data->type->u || data->type->x || data->type->big_x)
		data->flag->zero = 0;
	// check sharp
	if (data->type->d || data->type->c || data->type->s || data->type->u || data->type->i)
		data->flag->sharp = 0;
	//check unsign
	if (data->type->u || (data->type->o && (data->size->h || data->size->hh || data->size->l || data->size->ll))
		|| (data->type->x && (data->size->h || data->size->hh || data->size->l || data->size->ll )) || (data->type->big_x
		&& (data->size->h || data->size->hh || data->size->l || data->size->ll )))
		data->tool->unsign = 1;
}

/* ELEMENTS A STOCKER DANS LA STRUCTURE
 	- precision
 	- ce qu'il y a dans va_arg ?
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
