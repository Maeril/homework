/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:49:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 16:38:53 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// rajouter dans ft_printf.h un int pourcentage avec la gestion des types;

t_data          clean_pourcentage(t_data data)
{
    if (size->l)
        size->l = 0;
    if (size->ll)
        size->ll = 0;
    if (size->h)
        size->h = 0;
    if (size->hh)
        size->hh = 0;
    if (flag->space)
        flag->space = 0;
    if (lngt->precision)
        lngt->precision = 0;
    return (data);
}

t_data          printf_perc(t_data data)
{
    if (lngt->width && flag->zero)
    {
        while (lngt->width)
        {
            ft_putchar('0');
            lngt->width = lngt->width - 1;
            tool->nb_a++;
        }
    }
    if (lngt->width && !flag->zero)
    {
        while (lngt->width)
        {
            ft_putchar(' ');
            lngt->width = lngt->width - 1;
            tool->nb_a++;
        }
    }
    return (data);
}

t_data          pourcentage(t_data data)
{

    if (size->l || size->ll || size->h || size->hh || flag->space || lngt->precision)
        data = clean_pourcentage(data);

    if (lngt->precision_zero)
        data->precision_zero = 0;
    if (!lngt->width && flag->zero)
        flag->zero = 0;
    if (flag->sharp)
        flag->sharp = 0;
    if (flag->plus)
        flag->plus = 0;
    if (lngt->width)
        lngt->width = lngt->width - 1;
    if (flag->minus)
        ft_putchar('%');
    data = printf_perc(data);
    if (!flag->minus)
        ft_putchar('%');
    tool->nb_a++;
    return (data);
}