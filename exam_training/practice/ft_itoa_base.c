/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 17:33:51 by myener            #+#    #+#             */
/*   Updated: 2019/05/27 20:32:16 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*str;
	int		stock;
	int		neg;

	neg = (value < 0 && base == 10) ? 1 : 0;
	value = neg ? -value : value;
	i = 1;
	stock = value;
	while ((stock /= base) >= 1)
		i++;
	if (!(str = malloc(sizeof(char) * i + neg + 1)))
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (value % base < 10)
			str[i + neg] = (value % base) + '0';
		else
			str[i + neg] = (value % base) + 'A' - 10;
		value /= base;
		i--;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		printf("resultat = %s\n", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
