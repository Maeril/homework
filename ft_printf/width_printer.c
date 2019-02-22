/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:55:16 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 22:06:35 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    get_arg_len(va_list ap, t_data *data)
{
    int     i;

    if (data->spec->integer || data->spec->sh)
	{
		i = va_arg(ap, int);
		data->lngt->arg_len = ft_intlen(i);
	}
	else if (data->spec->lg || data->spec->lglg)
	{
		data->spec->lg ? (i = va_arg(ap, long int)) : (i = va_arg(ap, long long int));
		data->lngt->arg_len = ft_intlen(i);
	}
    else if (data->type->o)
	{
		i = va_arg(ap, int);
		data->lngt->arg_len = ft_octlen(i);
	}
    else if (data->type->u)
    {
        i = va_arg(ap, unsigned int);
        data->lngt->arg_len = ft_uintlen(i);
    }
    else if (data->type->x || data->type->big_x)
    {
        i = va_arg(ap, int);
        data->lngt->arg_len = ft_hexlen(i);
    }
    else if (data->type->c || data->tool->perc)
    {
        i = va_arg(ap, int);
        data->lngt->arg_len = 1;
    }
    else if (data->type->s)
    {
        i = va_arg(ap, int);
        ft_itoa(i);
        data->lngt->arg_len = ft_strlen(i);
    }
    else if (data->type->p)
    {
        i = va_arg(ap, int);
        data->lngt->arg_len = (ft_hexlen(i) + 4);
    }
}

void    width_printer(va_list ap, t_data *data)
{
    int     i;

    if (data->lngt->width)
    {
        if (data->lngt->arg_len < data->lngt->width)
        {
            if (data->flag->minus)
            {
                while (i < data->lngt->width);
            }
        }
    }
}
