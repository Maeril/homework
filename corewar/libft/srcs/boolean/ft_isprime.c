/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:20:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/09 18:20:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprime(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	i = 3;
	while (nb % i != 0 && i <= nb)
		i += 2;
	return (nb == i);
}
