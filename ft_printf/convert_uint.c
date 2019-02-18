/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:52:36 by myener            #+#    #+#             */
/*   Updated: 2019/02/18 22:19:08 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_uint(va_list ap, t_data *data)
{
	int		nb;

	nb = data->typ;
	ft_putnbr_base(nb, DECI);
    return (nb);
}