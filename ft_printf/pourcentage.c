/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <mpicard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:49:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/14 18:19:38 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// rajouter dans ft_printf.h un int pourcentage avec la gestion des types;

t_data          clean_pourcentage(t_data data)
{
    if (data.l)
        data.l = 0;
    if (data.ll)
        data.ll = 0;
    if (data.h)
        data.h = 0;
    if (data.hh)
        data.hh = 0;
    if (data.space)
        data.space = 0;
    if (data.precision)
        data.precision = 0;
    return (data);
}

t_data          printf_perc(t_data data)
{
    if (data.width && data.zero)
    {
        while (data.width)
        {
            ft_putchar('0');
            data.width = data.width - 1;
            data.nb_a++;
        }
    }
    if (data.width && !data.zero)
    {
        while (data.width)
        {
            ft_putchar(' ');
            data.width = data.width - 1;
            data.nb_a++;
        }
    }
    return (data);
}

t_data          pourcentage(t_data data)
{

    if (data.l || data.ll || data.h || data.hh || data.space || data.precision)
        data = clean_pourcentage(data);

    if (data.precision_zero)
        data.precision_zero = 0;

    if (!data.width && data.zero)
        data.zero = 0;

    if (data.sharp)
        data.sharp = 0;

    if (data.plus)
        data.plus = 0;

    if (data.width)
        data.width = data.width - 1;

    if (data.minus)
        ft_putchar('%');
    data = printf_perc(data);
    if (!data.minus)
        ft_putchar('%');
    data.nb_a++;
    return (data);
}