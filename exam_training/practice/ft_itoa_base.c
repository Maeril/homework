/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:33:51 by myener            #+#    #+#             */
/*   Updated: 2019/05/27 17:59:33 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*str;
	int		stock;
	int		neg;

	neg = (value < 0 && base == 10) ? 1 : 0;
	i = 0;
	stock = value;
	while ((value % base) >= 1)
	{
		value /= base;
		i++;
	}
	if (!(str = malloc(sizeof(char) * i + neg + 1)))
		return (NULL);
	value = stock;
	if (neg)
		str[0] = '-';
	while (i > 0)
	{
		if (base <= 10)
			str[i--] = (value % base) + '0';
		else if (base > 10)
			str[i--] = (value % base) + 'A' - 10;
		value /= base;
	}
	return (str);
}
