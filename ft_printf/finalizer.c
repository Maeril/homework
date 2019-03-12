/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:51:23 by myener            #+#    #+#             */
/*   Updated: 2019/03/12 15:48:52 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    finalizer(t_data *data)
{
	if (data->type->u || (data->type->o && (data->size->h || data->size->hh || data->size->l || data->size->ll))
		|| (data->type->x && (data->size->h || data->size->hh || data->size->l || data->size->ll )) || (data->type->big_x
		&& (data->size->h || data->size->hh || data->size->l || data->size->ll )))
		data->tool->unsign = 1;
	data->spec->integer = (data->type->d || data->type->i);
	data->flag->plus = (data->flag->plus && !data->tool->unsign);
	data->flag->space = (data->flag->space && !data->flag->plus);
	data->flag->zero = (data->flag->zero && !data->flag->minus);
	if (data->flag->zero && data->lngt->prec && (data->type->d || data->type->i || data->type->o
		|| data->type->u || data->type->x || data->type->big_x))
			data->flag->zero = 0;
	data->flag->space = (data->flag->space && (data->type->d || data->type->i || data->type->f));
    data->flag->sharp = (data->flag->sharp && (data->type->o || data->type->x
        || data->type->big_x || data->type->f));
	data->spec->sh = (data->spec->integer && data->size->h);
	data->spec->lg = (data->spec->integer && data->size->l);
	data->spec->lglg = (data->spec->integer && data->size->ll);
	// data->lngt->width = (data->lngt->width && (!(data->lngt->width <= data->lngt->prec)));
	// if (data->lngt->width > data->lngt->prec)
	// 	data->lngt->width = data->lngt->prec - data->lngt->width;

	// check zero
	// if (data->type->d || data->type->i || data->type->o || data->type->u || data->type->x || data->type->big_x)
	// 	data->flag->zero = 0;
	// // check sharp
	// if (data->type->d || data->type->c || data->type->s || data->type->u || data->type->i)
	// 	data->flag->sharp = 0;
}
