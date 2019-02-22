/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:47 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 21:34:43 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_int(va_list ap, t_data *data)
{
	int 		i;

	if (data->spec->integer || data->spec->sh)
	{
		i = va_arg(ap, int);
		ft_putnbr(i);
	}
	else if (data->spec->lg || data->spec->lglg)
	{
		data->spec->lg ? (i = va_arg(ap, long)) : (i = va_arg(ap, long long));
		ft_putnbr(i);
	}
}
