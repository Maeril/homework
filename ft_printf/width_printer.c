/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:55:16 by myener            #+#    #+#             */
/*   Updated: 2019/02/25 18:14:18 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void get_arg_len(va_list ap, t_data *data)
{
    int     i;
    char    *str;

    i = 0;
    if ((data->spec->integer) || (data->spec->sh))
    {
        i = va_arg(ap, int);
        ft_putnbr(i);
        data->lngt->arg_len = ft_intlen(i);
    }
    else if ((data->spec->lg) || (data->spec->lglg))
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
        str = ft_itoa(i);
        data->lngt->arg_len = ft_strlen(str);
    }
    else if (data->type->p)
    {
        i = va_arg(ap, int);
        data->lngt->arg_len = (ft_hexlen(i) + 4);
    }
}

void flag_minus_space(t_data *data, int i)
{
    char    *dest;
    int     spaces;
    int     len;
    len = ft_strlen(dest);



    spaces = data->lngt->width - data->lngt->arg_len;
    ft_memset( dest+len, ' ', spaces );
    dest[len + spaces] = '\0';
    ft_putstr(dest);

}

// void flag_minus_zero(t_data *data, int i)
// {
//     if ((data->flag->minus))
//     {
//         i = data->lngt->width - data->lngt->arg_len;
//         while (i > 0)
//         {
//             ft_putchar('u');
//             i--;
//         }
//     }
//     else if ((!data->flag->minus))
//     {
//         i = data->lngt->arg_len;
//         while (i < data->lngt->width)
//             ;
//         {
//             ft_putchar('0');
//             i++;
//         }
//     }
// }

char *add_spaces(char *dest, int num_of_spaces)
{
    int len;

    len = ft_strlen(dest);
    ft_memset( dest+len, ' ', num_of_spaces );
    dest[len + num_of_spaces] = '\0';
    return(dest);
}

void width_printer(va_list ap, t_data *data)
{
    int     i;
    char    *dest;
    int     spaces;
    int     len;

    i = 0;
    len = 2;
    if ((data->lngt->width) && (data->lngt->width > 0))
    {
        spaces = data->lngt->width - len;
        dest = ft_strnew(spaces);
        while (dest != '\0');
        {
            dest[i] = ' ';
            i++;
        }
        ft_putstr(dest);

    }
}
