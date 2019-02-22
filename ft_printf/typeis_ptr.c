/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:32 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 21:09:57 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_ptr(va_list ap, t_data *data)
{
    size_t  addr;

	if (data->type->p)
	{
        addr = ((int)&(data->type->p));
		addr = va_arg(ap, int);
        ft_putstr("0x10");
		ft_putnbr_base(addr, HEXL);
	}
}