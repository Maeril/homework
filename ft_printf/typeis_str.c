/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:38 by myener            #+#    #+#             */
/*   Updated: 2019/02/19 16:57:34 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		typeis_str(va_list ap, t_data *data)
{

	if (data->tool->str_tp || data->type->s)
	{
		data->tool->str_tp = va_arg(ap, char*);
		ft_putstr(data->tool->str_tp);
	}
}
