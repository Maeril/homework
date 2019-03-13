/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:56:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/13 14:22:02 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		dispatcher(va_list ap, t_data *data)
{
	if (data->type->d || data->type->i)
		typeis_int(ap, data);
	else if (data->type->c)
		typeis_char(ap, data);
	else if (data->type->s)
		typeis_str(ap, data);
	else if (data->type->p)
		typeis_ptr(ap, data);
	else if (data->type->o)
		typeis_octal(ap, data);
	else if (data->type->u)
		typeis_unsign(ap, data);
	else if (data->type->x)
		typeis_hexl(ap, data);
	else if (data->type->big_x)
		typeis_hexu(ap, data);
	else if (data->type->f)
		typeis_float(ap, data);
	else if (data->tool->perc)
		typeis_perc(ap, data);
}