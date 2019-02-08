/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:40:00 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 15:18:02 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

/*J'ai simplifie l'ecriture ici: */
t_data		parse_size(char *instructions, t_data data, unsigned int i)
{
	if ((data.l = (instructions[i] == 'l')))
		data.ll = (instructions[++i] == 'l');
	else if ((data.h = (instructions[i] == 'h')))
		data.hh = (instructions[++i] == 'h');
	i++;
	printf("data.ll = %d\n", data.ll);
	return (data);
}

t_data		parse_precision(char *instructions, t_data data, int i)
{
//	printf("instructions[i] == . ? %c\n", instructions[i]);
//	printf("instructions[i -1] == 5 ? %c\n", instructions[i - 1]);
	if (instructions[i - 1] && instructions[i - 1] >= '0' && instructions[i - 1] <= '9')
	{
//		printf("OUI J ENTRE ICI LIGNE 70\n\n");
		data.width = 1;
//		printf("data.width = 1 ? %d\n", data.width);
	}
	if (instructions[i + 1] >= '0' && instructions[i + 1] <= '9')
		data.precision = 1;
	while (instructions[i + 1] >= '0' && instructions[i + 1] <= '9')
        i++;
	return (data);
}

t_data		parse_width(char *instructions, t_data data, int i)
{
	while (instructions[i] >= '0' && instructions[i] <= '9')
	{
		data.width = 1;
		i++;
	}
	return (data);
}

t_data		parse_flags(char *instructions, t_data data, int i)
{
	/*J'ai simplifie l'ecriture ici: */
	while (instructions[i] == '-' || instructions[i] == '+' ||
			instructions[i] == '0' || instructions[i] == ' ' ||
			instructions[i] == '#')
	{
		data.minus = (instructions[i] == '-');
		data.plus = (instructions[i] == '+');
		data.zero = (instructions[i] == '0');
		data.space = (instructions[i] == ' ');
		data.sharp = (instructions[i] == '#');
		i++;
	}
	return (data);
}

t_data		parse_instructions(char *instructions, t_data data)
{
	int i;

	i = 0;
	while (instructions[i])
	{
		if (instructions[i] == '-' || instructions[i] == '+' ||
				instructions[i] == '0' || instructions[i] == ' ' ||
				instructions[i] == '#')
			data = parse_flags(instructions, data, i);// i est sur le dernier'flag'
		i++;
		if (instructions[i] >= '0' && instructions[i] <= '9')
			data = parse_width(instructions, data, i);
		i++;
		if (instructions[i] == '.')
			data = parse_precision(instructions, data, i);
		if (instructions[i] == 'h' || instructions[i] == 'l')
			data = parse_size(instructions, data, i);
	}
	return (data);
}