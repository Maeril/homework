/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:29 by myener            #+#    #+#             */
/*   Updated: 2019/03/07 14:46:46 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void        display_float(va_list ap, t_data *data, int len)
// {
//   a utiliser pour reduire la taille de la fonction ?
// }

void        typeis_float(va_list ap, t_data *data)
{
    int         i;
    int         j;
    // int         k;
    int         len;
    int   	    num;
	int         tmp;
    char        *str;


    if (data->type->f)
    {
        data->spec->flt = va_arg(ap, double);
        len = (data->lngt->precision ? (data->lngt->precision_value + 1) : 7);
        if (data->flag->sharp || data->flag->space)
			len++;
        if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
        if ((data->spec->flt > 0) && data->flag->plus)
            ft_putchar('+');
    	num = data->spec->flt;
  	    ft_putnbr(num);
        if (data->lngt->precision_zero)
            return ;
	    ft_putchar('.');
        if (data->spec->flt < 0)
    	{
          	ft_putchar('-');
    	    data->spec->flt = -data->spec->flt;
 	    }
        data->spec->flt -= num;
	    data->spec->flt ? (i = 1) : (i = 0);
        if (!(str = malloc(sizeof(char) * (len + 1))))
            return ;
        j = 0;
        while(i != 0 && i < len && data->spec->flt != 0 && data->spec->flt < 10)
        {
        	data->spec->flt *= 10;
        	tmp = data->spec->flt;
            str[j] = ft_itoc(tmp);
        	data->spec->flt -= tmp;
        	i++;
            j++;
        }
        str[j] = '\0';
        // printf("\nSTRING CONTENT = %s\n", str);
		// printf("\n\n>>> flag sharp = %d\n\n", data->flag->sharp);
	    tmp = (data->flag->sharp ? ft_atoi(str) : (ft_atoi(str) + 1));
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
            ft_putnbr(tmp);
        // }
        if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
    }
}
