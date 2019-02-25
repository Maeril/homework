/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 13:40:00 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/25 18:14:17 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		parse_flags(char *instruc, t_flag *flag, int i)
{
	// printf("entre dans parse_flags, valeur de instruc[i] = %c\n", instruc[i]);
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

void		parse_width(char *instruc, t_lngt *lngt, t_tool *tool, int i)
{
	int		j;
	char	*width_value;

	width_value = ft_strnew(ft_strlen(instruc));
	if (instruc[i - 1] == '.')
		return ;
	j = 0;
	lngt->width = 1;
	while ((instruc[i] >= '0' && instruc[i] <= '9') && instruc[i])
	{
		width_value[j] = instruc[i];
		i++;
		j++;
	}
	lngt->width_value = ft_atoi(width_value);
	tool->index = i;

}

void		parse_precision(char *instruc, t_lngt *lngt, t_tool *tool, int i)
{
	int len;
	int start;
	char *precision_ins;

/* a fortement simplifier en se basant sur le man; ne pas oublier les undefined behavior*/
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
	tool->perc = (instruc[i] == '%');
}

void		parser(char *instruc, t_data *data)
{
	int i;

	i = 0;
	while (instruc[i])
	{
		// printf("I, valeur de i = %i", i);
		// printf("I, contenu de instruc[i] = %c", instruc[i]);
		if ((instruc[i] == '-' || instruc[i] == '+' || instruc[i] == '0'
			|| instruc[i] == ' ' || instruc[i] == '#'))
		{
			// printf("II, valeur de i = %i", i);
			// printf("II, contenu de instruc[i] = %c", instruc[i]);
			parse_flags(instruc, data->flag, i);
		}
		if ((instruc[i] >= '0' && instruc[i] <= '9') && !(instruc[i - 1] >= '0' && instruc[i - 1] <= '9')) /*|| (instruc[i] >= 0 && instruc[i] <= 9) && (instruc[i - 1] == '%' || instruc[i - 1] == '-' || instruc[i - 1] == '+'))*/
		{
			// printf("valeur de i - 1 = %c", instruc[i - 1]);
			parse_width(instruc, data->lngt, data->tool, i);
		}
		if (instruc[i] == '.')
		{
			if ((instruc[i - 1] > '0' && instruc[i] <= '9')
				&& (instruc[i + 1] > '0' && instruc[i + 1] <= '9'))
					data->type->f = 1;
			parse_precision(instruc, data->lngt, data->tool, i);
		}
		if (instruc[i] == 'h' || instruc[i] == 'l')
			parse_size(instruc, data->size, i);
		if (instruc[i] == 'c' || instruc[i] == 's' || instruc[i] == 'p' ||
			instruc[i] == 'd' || instruc[i] == 'i' || instruc[i] == 'o' ||
			instruc[i] == 'u' || instruc[i] == 'x' || instruc[i] == 'X' || instruc[i] == '%')
			parse_type(instruc, data->type, data->tool, i);
		if (instruc[i] == '%')
			data->type->pourcentage = 1;
		i++;
	}
}
