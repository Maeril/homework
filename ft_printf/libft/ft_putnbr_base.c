/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:41:32 by myener            #+#    #+#             */
/*   Updated: 2019/03/17 23:00:51 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_base(long long int nb, const char *base)
{
	int		bl;

	bl = ft_strlen(base);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= bl)
		ft_putnbr_base((nb / bl), base);
	ft_putchar(base[nb % bl]);
}
