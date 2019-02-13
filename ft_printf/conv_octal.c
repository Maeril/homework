/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:22:59 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/13 15:24:43 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv_octal(int i)
{
	int		res;
	int		tmp;
	char	*str;
	int 	index;

	index = 0;
	tmp = i;
	while (i > 7)
	{
		i = i / 8;
		index++;
	}
	index++;
	if (!(str = malloc(sizeof(char) * (index + 1))))
		return (0);
	str[index] = '\0';
	i = tmp;
	index--;
	while (i > 7)
	{
		tmp = i / 8;
		res = i - tmp * 8;
		str[index] = res + '0';
		index--;
		i = tmp;
	}
	str[index] = i + '0';
	res = ft_atoi(str);
	return (res);
}

