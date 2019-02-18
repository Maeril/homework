/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uoctal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:53:03 by myener            #+#    #+#             */
/*   Updated: 2019/02/18 22:20:29 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_uoctal(va_list ap, t_data *data)
{
	int		nb;

	nb = data->typ;
	ft_putnbr_base(nb, OCT);
    return (nb);
}