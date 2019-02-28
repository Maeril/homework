/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:40:00 by myener            #+#    #+#             */
/*   Updated: 2019/02/28 17:21:05 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flags(char *instruc, t_flag *flag, int i)
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

void		parse_width(char *instruc, t_data *data, int i)
{
	int		j;
	char	*width_value;

	width_value = ft_strnew(ft_strlen(instruc));
	data->lngt->width = 1;
	if (instruc[i - 1] == '.')
		return ;
	j = 0;
	while ((instruc[i] >= '0' && instruc[i] <= '9') && instruc[i])
	{
		width_value[j] = instruc[i];
		i++;
		j++;
	}
	data->lngt->width_value = ft_atoi(width_value);
	data->tool->index = i;

}

void		parse_precision(char *instruc, t_lngt *lngt, t_tool *tool, int i)
{
	int len;
	int start;
	char *precision_ins;

	len = 0;
	i++;
	start = i;
	while (instruc[i] > '0' && instruc[i] <= '9')
	{
		lngt->precision = 1;
		len++;
		i++;
	}
	precision_ins = ft_strsub(instruc, start, len);
	lngt->precision = ft_atoi(precision_ins);
	if ((instruc[start] == '0' && !lngt->precision) || len == 0)
		lngt->precision_zero = 1;
	tool->index2 = i;
}

void		parse_size(char *instruc, t_size *size, int i)
{
	if (size->l == (instruc[i] == 'l'))
		size->ll = (instruc[++i] == 'l');
	else if ((size->h = (instruc[i] == 'h')))
		size->hh = (instruc[++i] == 'h');
	i++;
}

void		parse_type(char *instruc, t_type *type, t_tool *tool, int i)
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

void		parser(char *instruc, t_data *data)
{
	int i;

	i = 0;
	while (instruc[i])
	{
		if ((instruc[i] == '-' || instruc[i] == '+' || instruc[i] == '0'
			|| instruc[i] == ' ' || instruc[i] == '#'))
			parse_flags(instruc, data->flag, i);
		if ((instruc[i] >= '0' && instruc[i] <= '9') && !(instruc[i - 1] >= '0' && instruc[i - 1] <= '9') && (instruc[i - 1] != '.')) /*|| (instruc[i] >= 0 && instruc[i] <= 9) && (instruc[i - 1] == '%' || instruc[i - 1] == '-' || instruc[i - 1] == '+'))*/
			parse_width(instruc, data, i);
		if (instruc[i] == '.')
			parse_precision(instruc, data->lngt, data->tool, i);
		if (instruc[i] == 'h' || instruc[i] == 'l')
			parse_size(instruc, data->size, i);
		if (instruc[i] == 'c' || instruc[i] == 's' || instruc[i] == 'p' ||
			instruc[i] == 'd' || instruc[i] == 'i' || instruc[i] == 'o' || instruc[i] == 'f' ||
			instruc[i] == 'u' || instruc[i] == 'x' || instruc[i] == 'X' || instruc[i] == '%')
			parse_type(instruc, data->type, data->tool, i);
		if (instruc[i] == '%')
			data->type->pourcentage = 1;
		i++;
	}
}
