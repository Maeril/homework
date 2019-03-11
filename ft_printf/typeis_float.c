/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:29 by myener            #+#    #+#             */
/*   Updated: 2019/03/11 17:45:54 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void        display_float(va_list ap, t_data *data, int len)
// {
//   a utiliser pour reduire la taille de la fonction ?
// }

void typeis_float(va_list ap, t_data *data)
{
    int i = 0;
    int j;
    // int           k;
    int len_prec;
    int len_width;
    long long int num;
    long long int tmp;
    char *str;

    if (data->type->f)
    {
        len_width = data->lngt->width_value;
        data->spec->flt = va_arg(ap, double);
        if (data->flag->sharp)
            len_width++;
        if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
            widthprinter_nominus(data, len_width);
        if (data->flag->space)
            ft_putchar(' ');
        if ((data->spec->flt > 0) && data->flag->plus)
            ft_putchar('+');
        num = data->spec->flt;
        if (data->lngt->precision_zero)
            return;
        if (data->spec->flt < 0)
        {
            //   	ft_putchar('-');
            data->spec->flt = -data->spec->flt;
        }
        data->spec->flt -= num;
        // data->spec->flt ? (i = 1) : (i = 0);
        len_prec = (data->lngt->precision ? (data->lngt->precision_value + 1) : 7);
        if (!(str = malloc(sizeof(char) * (len_prec + 1))))
            return;
        j = 0;
        while (data->spec->flt > 0)
        {
            data->spec->flt *= 10;
            tmp = data->spec->flt;
            str[j] = ft_itoc(tmp);
            data->spec->flt -= tmp;
            i++;
            j++;
        }
        if (str[len_prec + 1] >= '5')
        {
            tmp = (ft_atoi(str) + 1);
        }
        str[len_prec + 1] = '\0';
        // printf("\nSTRING CONTENT = %s\n", str);
        // printf("\n\n>>> flag sharp = %d\n\n", data->flag->sharp);
        ft_putnbr(num);
        ft_putchar('.');
        i = 0;
        while (i < (len_prec - 1))
        {
            ft_putchar(str[i]);
            i++;
        }
        // if (data->flag->sharp)
        //     tmp = ft_atoi(str);
        // else if (!data->flag->sharp)
        //     tmp = (ft_atoi(str) + 1);
        // printf("\nTMP CONTENT = %d\n", tmp);
        // if (data->lngt->precision && (data->lngt->precision_value > 0))
        // {
        // 	k = 0;
        //     // ft_strdel(&str);
        //     // str = ft_itoa(tmp);
        // 	while (k < (len - 1))
        //     {
        // 		ft_putchar(str[k]);
        //         k++;
        //     }
        // }
        // else if (!data->lngt->precision)
        // {
        // ft_putnbr(tmp);
        // }
        if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
            widthprinter_minus(data, len_width);
    }
}
