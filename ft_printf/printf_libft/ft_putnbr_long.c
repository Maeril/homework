/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:08:08 by myener            #+#    #+#             */
/*   Updated: 2019/03/23 18:20:54 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putnbr_long_rec(long long int nb)
{
	if (nb)
	{
		ft_putnbr_long_rec(nb / 10);
		ft_putchar('0' + ft_abs(nb % 10));
	}
}

void		ft_putnbr_long(long long int nb)
{
	if (nb >= 0)
		nb = -nb;
	if (nb > -10)
		ft_putchar('0' + ft_abs(nb % 10));
	else
		ft_putnbr_long_rec(nb);
}
