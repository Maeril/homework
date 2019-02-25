/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:51:23 by myener            #+#    #+#             */
/*   Updated: 2019/02/25 23:39:05 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    finalizer(t_data *data)
{
    // printf("\nAVANT FINALIZER: valeur de zero = %i, valeur de minus = % i\n", data->flag->zero, data->flag->minus);
	data->spec->integer = (data->type->d || data->type->i);
	data->spec->ouxx = (data->type->o || data->type-> u || data->type->x || data->type->big_x);
	data->flag->plus = (data->flag->plus && !data->tool->unsign);
	data->flag->space = (data->flag->space && !data->flag->plus);
	data->flag->zero = (data->flag->zero && !data->flag->minus);
	data->flag->space = (data->flag->space && (data->type->d || data->type->i));
    data->flag->sharp = (data->flag->sharp && (data->type->d || data->type->c
        || data->type->s || data->type->u || data->type->i));
	data->spec->sh = (data->spec->integer && data->size->h);
	data->spec->lg = (data->spec->integer && data->size->l);
	data->spec->lglg = (data->spec->integer && data->size->ll);
	data->spec->unsignsh = (data->spec->ouxx && data->size->h);
	data->spec->unsignlg = (data->spec->ouxx && data->size->l);
	data->spec->unsignlglg = (data->spec->ouxx && data->size->ll);
    // printf("\nAPRES FINALIZER: valeur de zero = %i, valeur de minus = % i\n", data->flag->zero, data->flag->minus);
    // _____________________________
	// check zero
	// if (data->type->d || data->type->i || data->type->o || data->type->u || data->type->x || data->type->big_x)
	// 	data->flag->zero = 0;
	// // check sharp
	// if (data->type->d || data->type->c || data->type->s || data->type->u || data->type->i)
	// 	data->flag->sharp = 0;
	// //check unsign
	// if (data->type->u || (data->type->o && (data->size->h || data->size->hh || data->size->l || data->size->ll))
	// 	|| (data->type->x && (data->size->h || data->size->hh || data->size->l || data->size->ll )) || (data->type->big_x
	// 	&& (data->size->h || data->size->hh || data->size->l || data->size->ll )))
	// 	data->tool->unsign = 1;
}
