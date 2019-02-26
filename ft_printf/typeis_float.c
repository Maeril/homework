/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:29 by myener            #+#    #+#             */
/*   Updated: 2019/02/26 17:27:58 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        typeis_float(va_list ap, t_data *data)
{
    double     nb;

    https://www.developpez.net/forums/d234854/c-cpp/c/double-float/
    if (data->type->f)
    {
        nb = va_arg(ap, double);
        ft_putnbr(nb);
    }

}