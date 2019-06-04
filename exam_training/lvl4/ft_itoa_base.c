/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 13:47:53 by myener            #+#    #+#             */
/*   Updated: 2019/05/27 20:26:37 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	int		i = 1;
	int		tmp = 0;
	int		neg = 0;
	char	*str;

	if (base == 10 && value < 0)
	{
		neg = 1;
		value = -value;
	}
	tmp = value;
	while ((tmp /= base) >= 1)
		i++;
	if (!(str = malloc(sizeof(char) * i + neg + 1)))
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		if ((value % base) < 10)
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