/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uhexl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:51:54 by myener            #+#    #+#             */
/*   Updated: 2019/02/18 22:20:24 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_uhexl(va_list ap, t_data *data)
{
	int		nb;

	nb = data->typ;
	ft_putnbr_base(nb, HEXL);
    return (nb);
}
