/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:40:00 by myener            #+#    #+#             */
/*   Updated: 2019/04/04 14:17:58 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		parse_flags(char *instruc, t_flag *flag, int i)
{
	while (instruc[i])
	{
		if (instruc[i] == '-')
			flag->minus = 1;
		if (instruc[i] == '+')
			flag->plus = 1;
		if (instruc[i] == '0' && !(instruc[i - 1] >= '0'
			&& instruc[i - 1] <= '9'))
			flag->zero = 1;
		if (instruc[i] == ' ')
			flag->space = 1;
		if (instruc[i] == '#')
			flag->sharp = 1;
		i++;
	}
}

static void		parse_size(char *instruc, t_size *size, int i)
{
	size->l = (instruc[i] == 'l' && !(instruc[i - 1] == 'l'
	|| instruc[i + 1] == 'l'));
	size->h = (instruc[i] == 'h' && !(instruc[i - 1] == 'h'
	|| instruc[i + 1] == 'h'));
	size->ll = (instruc[i] == 'l' && (instruc[i + 1] == 'l'
	|| instruc[i - 1] == 'l'));
	size->hh = (instruc[i] == 'h' && (instruc[i + 1] == 'h'
	|| instruc[i - 1] == 'h'));
	i++;
}

static void		parse_type(char *instruc, t_type *type, t_tool *tool, int i)
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
	type->f = (instruc[i] == 'f');
	tool->perc = (instruc[i] == '%');
}

void			parser(char *instruc, t_data *data)
{
	int i;

	i = 0;
	while (instruc[i])
	{
		if ((instruc[i] == '-' || instruc[i] == '+' || instruc[i] == '0'
			|| instruc[i] == ' ' || instruc[i] == '#'))
			parse_flags(instruc, data->flag, i);
		if ((instruc[i] >= '0' && instruc[i] <= '9') && !(instruc[i - 1] >= '0'
			&& instruc[i - 1] <= '9') && (instruc[i - 1] != '.'))
			parse_width(instruc, data, i);
		if (instruc[i] == '.')
			parse_prec(instruc, data->lngt, data->tool, i);
		if (instruc[i] == 'h' || instruc[i] == 'l')
		{
			data->tool->size = 1;
			parse_size(instruc, data->size, i);
		}
		if (instruc[i] == 'c' || instruc[i] == 's' || instruc[i] == 'p' ||
			instruc[i] == 'd' || instruc[i] == 'i' || instruc[i] == 'o' ||
			instruc[i] == 'f' || instruc[i] == 'u' || instruc[i] == 'x' ||
			instruc[i] == 'X' || instruc[i] == '%')
			parse_type(instruc, data->type, data->tool, i);
		i++;
	}
}
