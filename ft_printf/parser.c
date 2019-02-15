/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:40:00 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/14 22:13:30 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_type(char *instruc, t_data *data, int i)
{
	data->c = (instruc[i] == 'c');
	data->s = (instruc[i] == 's');
	data->p = (instruc[i] == 'p');
	data->d = (instruc[i] == 'd');
	data->i = (instruc[i] == 'i');
	data->o = (instruc[i] == 'o');
	data->u = (instruc[i] == 'u');
	data->x = (instruc[i] == 'x');
	data->big_x = (instruc[i] == 'X');
	data->perc = (instruc[i] == '%');
}

void		parse_size(char *instruc, t_data *data, int i)
{
	if (data->l == (instruc[i] == 'l'))
		data->ll = (instruc[++i] == 'l');
	else if ((data->h = (instruc[i] == 'h')))
		data->hh = (instruc[++i] == 'h');
	i++;
}


void		parse_precision(char *instruc, t_data *data, int i)
{
	int len;
	int start;
	char *precision_ins;

	len = 0;
	i++;
	start = i;
	if (instruc[i] == '0')
	{
		data->precision_zero = 1;
		i++;
	}
	while (instruc[i] >= '0' && instruc[i] <= '9')
	{
		data->precision = 1;
		len++;
		i++;
	}
	if (len == 0)
		data->precision_dot = 1;;
	data->index2 = i;
	precision_ins = ft_strsub(instruc, start, len);
	data->precision = ft_atoi(precision_ins);
}

// j'ai refait cette fonction ci dessous. J'ai l'impression qu'elle fonctionne
// mieux. Si ca te va, on supprime la fonction mise en sourdine ci dessous :) 
//t_data		parse_precision(char *instruc, t_data data, int i)
//{
//	if (instruc[i - 1] && instruc[i - 1] >= '0' && instruc[i - 1] <= '9')
//		data.width = 1;
//	if (instruc[i + 1] >= '0' && instruc[i + 1] <= '9')
//		data.precision = 1;
//	while (instruc[i + 1] >= '0' && instruc[i + 1] <= '9')
//		i++;
//	return (data);
//}

void		parse_width(char *instruc, t_data *data, int i)
{
	int		len;
	int		start;
	char	*width_ins;

	if (instruc[i - 1] == '.')
		return ;
	len = 0;
	start = i;
	while (instruc[i] >= '0' && instruc[i] <= '9')
	{
		data->width = 1;
		len++;
		i++;
	}
	data->index = i;
	width_ins = ft_strsub(instruc, start, len);
	data->width = ft_atoi(width_ins);
}

void		parse_flags(char *instruc, t_data *data, int i)
{
	while (instruc[i] == '-' || instruc[i] == '+' ||
			instruc[i] == '0' || instruc[i] == ' ' ||
			instruc[i] == '#')
	{
	/*	data.minus = (instruc[i] == '-');  J'ai eu un bug avec cette ligne... du coup jai mis celle en dessous
	en attendant de comprendre pourquoi y a eu un probleme */
		if (instruc[i] == '-')
			data->minus = 1;
		data->plus = (instruc[i] == '+');
		data->zero = (instruc[i] == '0');
		data->space = (instruc[i] == ' ');
		data->sharp = (instruc[i] == '#');
		i++;
	}
}

void		parse_instructions(char *instruc, t_data *data)
{
	int i;

	i = 0;
	while (instruc[i])
	{
		if (instruc[i] == '-' || instruc[i] == '+' ||
				instruc[i] == '0' || instruc[i] == ' ' ||
				instruc[i] == '#')
			parse_flags(instruc, data, i);
		if (instruc[i] >= '0' && instruc[i] <= '9')
		{
			data->index = i;
			parse_width(instruc, data, i);
			i = data->index;
		}
		if (instruc[i] == '.')
			parse_precision(instruc, data, i);
		if (instruc[i] == 'h' || instruc[i] == 'l')
			parse_size(instruc, data, i);
		if (instruc[i] == 'c' || instruc[i] == 's' || instruc[i] == 'p' ||
			instruc[i] == 'd' || instruc[i] == 'i' || instruc[i] == 'o' ||
			instruc[i] == 'u' || instruc[i] == 'x' || instruc[i] == 'X' || instruc[i] == '%')
			parse_type(instruc, data, i);
		if (instruc[i] == '%')
			data->pourcentage = 1;
		i++;
	}
}
