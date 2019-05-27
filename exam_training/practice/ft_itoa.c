/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:12:51 by myener            #+#    #+#             */
/*   Updated: 2019/05/27 17:34:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strrev(char *str)
{
	int		min;
	int		max;
	char	temp;

	min = 0;
	max = ft_strlen(str);
	max--;
	while (min < max)
	{
		temp = str[min];
		str[min] = str[max];
		str[max] = temp;
		min++;
		max--;
	}
	return (str);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		neg;
	int		i;

	neg = nbr < 0 ? 1 : 0;
	nbr = neg ? -nbr : nbr;
	if (!(str = malloc(sizeof(char) * 12 + 1)))
		return (NULL);
	if (str == NULL || nbr == 0)
		return (nbr == 0 ? "0" : NULL);
	if (nbr == -2147483648)
		return ("-2147483648");
	i = 0;
	while (nbr)
	{
		str[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (neg)
		str[i] = '-';
	return (ft_strrev(str));
}

// int		main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("result = %s\n", ft_itoa(atoi(argv[1])));
// 	}
// 	return (0);
// }
