/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:40:00 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 16:37:09 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_type(char *instruc, t_type *type, int i)
{
	type->c = (instruc[i] == 'c');
	type->s = (instruc[i] == 's');
	type->p = (instruc[i] == 'p');
	type->d = (instruc[i] == 'd');
	type->i = (instruc[i] == 'i');
	type->o = (instruc[i] == 'o');
	type->u = (instruc[i] == 'u');
	type->x = (instruc[i] == 'x');
	type->big_x = (instruc[i] == 'X');
	tool->perc = (instruc[i] == '%');
}

void		parse_size(char *instruc, t_data *data, int i)
{
	if (size->l == (instruc[i] == 'l'))
		size->ll = (instruc[++i] == 'l');
	else if ((size->h = (instruc[i] == 'h')))
		size->hh = (instruc[++i] == 'h');
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
		lngt->precision_zero = 1;
		i++;
	}
	while (instruc[i] >= '0' && instruc[i] <= '9')
	{
		lngt->precision = 1;
		len++;
		i++;
	}
	if (len == 0)
		lngt->precision_dot = 1;;
	tool->index2 = i;
	precision_ins = ft_strsub(instruc, start, len);
	lngt->precision = ft_atoi(precision_ins);
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
		lngt->width = 1;
		len++;
		i++;
	}
	tool->index = i;
	width_ins = ft_strsub(instruc, start, len);
	lngt->width = ft_atoi(width_ins);
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
			flag->minus = 1;
		flag->plus = (instruc[i] == '+');
		flag->zero = (instruc[i] == '0');
		flag->space = (instruc[i] == ' ');
		flag->sharp = (instruc[i] == '#');
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
			tool->index = i;
			parse_width(instruc, data, i);
			i = tool->index;
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
			type->pourcentage = 1;
		i++;
	}
}
