/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_min_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:37:35 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/13 15:24:11 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	put_letter_min(int res)
{
	char c;

	printf("res = %d\n", res);
	if (res == 10)
		c = 'a';
	if (res == 11)
		c = 'b';
	if (res == 12)
		c = 'c';
	if (res == 13)
		c = 'd';
	if (res == 14)
		c = 'e';
	if (res == 15)
		c = 'f';
	printf("c = %c\n", c);
	return (c);
}

char	*conv_min_hexa(int i)
{
	int res;
	int tmp;
	char *str;
	int index;
	char	c;

	index = 0;
	tmp = i;
	while (i > 15)
	{
		i = i / 16;
		index++;
	}
	index++;
	if (!(str = malloc(sizeof(char) * (index + 1))))
		return (0);
	str[index] = '\0';
	i = tmp;
	index--;
	while (i > 15)
	{
		tmp = i / 16;
		res = i - tmp * 16;
		if (res < 10)
			str[index] = res + '0';
		if (res > 9)
			str[index] = put_letter_min(res);
		printf("str[index] = %c\n", str[index]);
		index--;
		i = tmp;
	}
	if (i > 9)
	{
		str[index] = put_letter_min(i);
	}
	else
	{
		str[index] = i + '0';
	}
	return (str);
}






