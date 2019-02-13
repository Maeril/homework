/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:40:00 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/13 14:42:38 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		parse_type(char *instruc, t_data data, int i)
{
	data.c = (instruc[i] == 'c');
	data.s = (instruc[i] == 's');
	data.p = (instruc[i] == 'p');
	data.d = (instruc[i] == 'd');
	data.i = (instruc[i] == 'i');
	data.o = (instruc[i] == 'o');
	data.u = (instruc[i] == 'u');
	data.x = (instruc[i] == 'x');
	data.big_x = (instruc[i] == 'X');
	data.perc = (instruc[i] == '%');

	return (data);
}

t_data		parse_size(char *instruc, t_data data, int i)
{
	if (data.l == (instruc[i] == 'l'))
		data.ll = (instruc[++i] == 'l');
	else if ((data.h = (instruc[i] == 'h')))
		data.hh = (instruc[++i] == 'h');
	i++;
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
	int		len;
	int		start;
	char	*width_ins;

	len = 0;
	start = i;
	while (instruc[i] >= '0' && instruc[i] <= '9')
	{
		data.width = 1;
		len++;
		i++;
	}
	data.index = i;
	width_ins = ft_strsub(instruc, start, len);
	data.width = ft_atoi(width_ins);
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
			data = parse_flags(instruc, data, i);
		if (instruc[i] >= '0' && instruc[i] <= '9')
		{
			data.index = i;
			data = parse_width(instruc, data, i);
			i = data.index;
		}
		if (instruc[i] == '.')
			data = parse_precision(instruc, data, i);
		if (instruc[i] == 'h' || instruc[i] == 'l')
			data = parse_size(instruc, data, i);
		if (instruc[i] == 'c' || instruc[i] == 's' || instruc[i] == 'p' ||
			instruc[i] == 'd' || instruc[i] == 'i' || instruc[i] == 'o' ||
			instruc[i] == 'u' || instruc[i] == 'x' || instruc[i] == 'X' || instruc[i] == '%')
			data = parse_type(instruc, data, i);
		i++;
	}
	return (data);
}
