/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:07:20 by myener            #+#    #+#             */
/*   Updated: 2019/03/23 18:23:14 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putnbr_rec(int nb)
{
	if (nb)
	{
		ft_putnbr_rec(nb / 10);
		ft_putchar('0' + ft_abs(nb % 10));
	}
}

void		ft_putnbr(int nb)
{
	if (nb >= 0)
		nb = -nb;
	if (nb > -10)
		ft_putchar('0' + ft_abs(nb % 10));
	else
		ft_putnbr_rec(nb);
}
