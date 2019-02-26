/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:29 by myener            #+#    #+#             */
/*   Updated: 2019/02/26 23:14:29 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        typeis_float(va_list ap, t_data *data)
{
    int     i;
    int     j;
    int   	num;
	int		tmp;
    int     len;
    char    str[649];
    double  nb;

    if (data->type->f)
    {
        len = (data->lngt->precision ? data->lngt->precision : 7);
        nb = va_arg(ap, double);
	    if (nb < 0)
    	{
          	ft_putchar('-');
    	    nb = -nb;
 	    }
    	num = nb;
  	    ft_putnbr(num);
	    nb -= num;
	    nb > 0 ? (i = 1) : (i = 0);
	    ft_putchar('.');
        j = 0;
        while(i != 0 && i < len && nb != 0 && nb < 10 && str[j])
        {
        	nb *= 10;
        	tmp = ((int)nb);
            str[j] = *ft_itoa(tmp);
        	nb -= tmp;
        	i++;
            j++;
        }
         str[j] = '\0';
	    tmp = ft_atoi(str) + 1;
         ft_putnbr(tmp);
    }
}
