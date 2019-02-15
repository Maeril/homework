/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pourcentage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:49:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 18:44:27 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// rajouter dans ft_printf.h un int pourcentage avec la gestion des types;

void          clean_pourcentage(t_size *size, t_flag *flag, t_lngt *lngt)
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
}

void          printf_perc(t_tool *tool, t_flag *flag, t_lngt *lngt)
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
}

void          pourcentage(t_data *data)
{
    if (data->size->l || data->size->ll || data->size->h || data->size->hh
        || data->flag->space || data->lngt->precision)
        clean_pourcentage(data->size, data->flag, data->lngt);
    if (data->lngt->precision_zero)
        data->lngt->precision_zero = 0;
    if (!data->lngt->width && data->flag->zero)
        data->flag->zero = 0;
    if (data->flag->sharp)
        data->flag->sharp = 0;
    if (data->flag->plus)
        data->flag->plus = 0;
    if (data->lngt->width)
        data->lngt->width = data->lngt->width - 1;
    if (data->flag->minus)
        ft_putchar('%');
        printf_perc(data->tool, data->flag, data->lngt);
    if (!data->flag->minus)
        ft_putchar('%');
    data->tool->nb_a++;
}