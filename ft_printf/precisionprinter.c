/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisionprinter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:58:14 by myener            #+#    #+#             */
/*   Updated: 2019/02/28 16:26:50 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		precisionprint_int(t_data *data, int len)
{
	int	i;

	i = 0;
	if (len < data->lngt->precision)
	{
		while (i < (data->lngt->precision - len))
    		{
    			ft_putchar('0');
    			i++;
    		}
	}
}