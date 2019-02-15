/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:48:05 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 18:32:14 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		clean_data(t_data *data)
{
		data->flag->minus = 0;
		data->flag->plus = 0;
		data->flag->zero = 0;
		data->flag->space = 0;
		data->lngt->width = 0;
		data->lngt->precision = 0;
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
		data->spec->integer = 0;
		data->spec->str = 0;
		data->spec->car = 0;
		data->spec->unint = 0;
		data->spec->signcar = 0;
		data->spec->sh = 0;
		data->spec->lg = 0;
		data->spec->lglg = 0;
		data->spec->unsigncar = 0;
		data->spec->unsignsh = 0;
		data->spec->unsignlg = 0;
		data->spec->unsignlglg = 0;
		data->tool->unsign = 0;
		data->tool->index = 0;
		data->tool->index2 = 0;
		data->tool->nb_a = 0;
}
