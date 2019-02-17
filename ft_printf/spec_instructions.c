/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:14:03 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/17 23:48:28 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_zero(t_type *type, t_flag *flag)
{
	if (type->d || type->i || type->o || type->u || type->x || type->big_x)
		flag->zero = 0;
}

void		check_sharp(t_type *type, t_flag *flag)
{
	if (type->d || type->c || type->s || type->u || type->i)
		flag->sharp = 0;
}

void		check_unsigned(t_type *type, t_size *size, t_tool *tool)
{
	if (type->u || (type->o && (size->h || size->hh || size->l || size->ll))
		|| (type->x && (size->h || size->hh || size->l || size->ll )) || (type->big_x
		&& (size->h || size->hh || size->l || size->ll )))
		tool->unsign = 1;
}

void		finalize_instructions(t_data *data)
{
	data->flag->plus = (data->flag->plus && !data->tool->unsign);
	data->flag->space = (data->flag->space && !data->flag->plus);
	data->flag->zero = (data->flag->zero && !data->flag->minus);
	data->flag->space = (data->flag->space && (data->type->d
						|| data->type->i));
/*	lngt->precision = (lngt->precision && !type->c); > pb avec cette phrase :( elle met precision a 1. */
	if (data->lngt->precision && (data->type->d || data->type->i
		|| data->type->o || data->type->u || data->type->x
		|| data->type->big_x))
		data->flag->zero = 0;
	if (data->flag->sharp && (data->type->d || data->type->c || data->type->s
		|| data->type->u || data->type->i))
		data->flag->sharp = 0;
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
