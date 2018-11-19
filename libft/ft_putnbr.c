/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 14:07:20 by myener            #+#    #+#             */
/*   Updated: 2018/11/18 14:10:15 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.c"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (0);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * (-1);
	}
	else if (nb >= 0 && nb <= 9)
		ft_putchar (nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
