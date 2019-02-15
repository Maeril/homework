/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_maj_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:21:18 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/13 20:10:09 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
char	put_letter_maj(int res)
{
	char c;

	if (res == 10)
		c = 'A';
	if (res == 11)
		c = 'B';
	if (res == 12)
		c = 'C';
	if (res == 13)
		c = 'D';
	if (res == 14)
		c = 'E';
	if (res == 15)
		c = 'F';
	return (c);
}

char    *conv_maj_hexa(int i)
{
	int res;
	int tmp;
	char *str;
	int index;
	char    c;

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
			str[index] = put_letter_maj(res);
		index--;
		i = tmp;
	}
	if (i > 9)
	{
		str[index] = put_letter_maj(i);
	}
	else
	{
		str[index] = i + '0';
	}
	return (str);
}

