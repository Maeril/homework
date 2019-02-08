/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:40:00 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 17:40:37 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

t_data		parse_size(char *instruc, t_data data, unsigned int i)
{
	if ((data.l = (instruc[i] == 'l')))
		data.ll = (instruc[++i] == 'l');
	else if ((data.h = (instruc[i] == 'h')))
		data.hh = (instruc[++i] == 'h');
	i++;
	printf("data.ll = %d\n", data.ll);
	return (data);
}

t_data		parse_precision(char *instruc, t_data data, int i)
{
	if (instruc[i - 1] && instruc[i - 1] >= '0' && instruc[i - 1] <= '9')
		data.width = 1;
	if (instruc[i + 1] >= '0' && instruc[i + 1] <= '9')
		data.precision = 1;
	while (instruc[i + 1] >= '0' && instruc[i + 1] <= '9')
		i++;
	return (data);
}

t_data		parse_width(char *instruc, t_data data, int i)
{
	while (instruc[i] >= '0' && instruc[i] <= '9')
	{
		data.width = 1;
		i++;
	}
	return (data);
}

t_data		parse_flags(char *instruc, t_data data, int i)
{
	while (instruc[i] == '-' || instruc[i] == '+' ||
			instruc[i] == '0' || instruc[i] == ' ' ||
			instruc[i] == '#')
	{
		data.minus = (instruc[i] == '-');
		data.plus = (instruc[i] == '+');
		data.zero = (instruc[i] == '0');
		data.space = (instruc[i] == ' ');
		data.sharp = (instruc[i] == '#');
		i++;
	}
	return (data);
}

t_data		parse_instructions(char *instruc, t_data data)
{
	int i;

	i = 0;
	while (instruc[i])
	{
		if (instruc[i] == '-' || instruc[i] == '+' ||
				instruc[i] == '0' || instruc[i] == ' ' ||
				instruc[i] == '#')
			data = parse_flags(instruc, data, i);/*i est sur le dernier'flag'*/
		i++;
		if (instruc[i] >= '0' && instruc[i] <= '9')
			data = parse_width(instruc, data, i);
		i++;
		if (instruc[i] == '.')
			data = parse_precision(instruc, data, i);
		if (instruc[i] == 'h' || instruc[i] == 'l')
			data = parse_size(instruc, data, i);
	}
	return (data);
}
