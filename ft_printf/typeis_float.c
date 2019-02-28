/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:29 by myener            #+#    #+#             */
/*   Updated: 2019/02/27 23:37:15 by myener           ###   ########.fr       */
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
    int         len;
    int   	    num;
	int	        tmp;
    char        *str;


    if (data->type->f)
    {
        data->spec->flt = va_arg(ap, double);
        len = (data->lngt->precision ? data->lngt->precision : 7);
        if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
    	num = data->spec->flt;
  	    ft_putnbr(num);
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
        // printf("contenu de str: %s", str);
	    tmp = ft_atoi(str) + 1;
        ft_putnbr(tmp);
        if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
    }
}
