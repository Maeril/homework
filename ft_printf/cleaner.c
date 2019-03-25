/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:48:05 by myener            #+#    #+#             */
/*   Updated: 2019/03/25 18:26:03 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cleaner(t_data *data)
{
		data->flag->minus = 0;
		data->flag->plus = 0;
		data->flag->zero = 0;
		data->flag->space = 0;
		data->flag->sharp = 0;
		data->lngt->width = 0;
		data->lngt->width_value = 0;
		data->lngt->prec = 0;
		data->lngt->prec_value = 0;
		data->lngt->prec_zero = 0;
		data->lngt->prec_rien = 0;
		data->size->h = 0;
		data->size->ll = 0;
		data->size->l = 0;
		data->size->hh = 0;
		data->type->c = 0;
		data->type->s = 0;
		data->type->p = 0;
		data->type->d = 0;
		data->type->i = 0;
		data->type->o = 0;
		data->type->u = 0;
		data->type->x = 0;
		data->type->big_x = 0;
		data->type->f = 0;
		data->spec->integer = 0;
		data->spec->str = 0;
		data->spec->car = 0;
		data->spec->flt = 0;
		data->spec->unint = 0;
		data->spec->signcar = 0;
		data->spec->sh = 0;
		data->spec->lg = 0;
		data->spec->lglg = 0;
		data->tool->perc = 0;
		data->tool->unsign = 0;
		data->tool->index = 0;
		data->tool->index2 = 0;
		data->tool->ret = 0;
		data->tool->str_tp = NULL;
}
