/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:26:34 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 19:50:05 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		prt_width(t_lngt *lngt, char *str)
{
	int		size;
	int		space_to_add;

	space_to_add = 0;
	size = ft_strlen(str);
	if (size < lngt->width)
	{
		space_to_add = lngt->width - size;
		while (space_to_add)
		{
			ft_putchar(' ');
			space_to_add--;
		}
	}
}

void		prt_int_width(t_spec *spec, t_lngt *lngt, t_flag *flag)
{ /* bon modele a reproduire */
	char	*str;
	int		lgt;

	str = ft_itoa(spec->integer);
	lgt = ft_strlen(str);
	if (flag->minus)
	{
		ft_putnbr(spec->integer);
		flag_minus(lngt, lgt);
	}
	else if (!flag->minus)
	{
		prt_width(lngt, str);
		ft_putnbr(spec->integer);
	}
}

void		prt_unint_width(t_spec *spec, t_lngt *lngt, t_flag *flag)
{
	char	*str;
	int		lgt;

	str = ft_itoa(spec->unint);
	lgt = ft_strlen(str);
	if (flag->minus)
	{
		ft_putnbr(spec->unint);
		flag_minus(lngt, lgt);
	}
	else if (!flag->minus)
	{
		prt_width(lngt, str);
		ft_putnbr(spec->unint);
	}
}

void		prt_str_width(t_tool *tool, t_lngt *lngt, t_flag *flag)
{
	int		lgt;

	lgt = ft_strlen(tool->str_tp);

	if (flag->minus)
	{
		ft_putstr(tool->str_tp);
		flag_minus(lngt, lgt);
	}
	else if (!flag->minus)
	{
		prt_width(lngt, tool->str_tp);
		ft_putstr(tool->str_tp);
	}
}

void		prt_car_width(t_spec *spec, t_lngt *lngt, t_flag *flag)
{
	lngt->width = lngt->width - 1;
	if (flag->minus)
	{
		ft_putchar(spec->car);
		flag_minus(lngt, 1);
	}
	else if (!flag->minus)
	{
		while (lngt->width)
		{
			ft_putchar(' ');
			lngt->width--;
		}
		ft_putchar(spec->car);
	}
}

void		print_all(t_data *data)
{
	if (data->spec->integer)
		data->lngt->width ? prt_int_width(data->spec, data->lngt, data->flag) : ft_putnbr(data->spec->integer);
	if (data->spec->str)
		data->lngt->width ? prt_str_width(data->tool, data->lngt, data->flag) : ft_putstr(data->tool->str_tp);
	if (data->spec->car)
	{
		(data->spec->car && data->lngt->width > 1) ?
		prt_car_width(data->spec, data->lngt, data->flag) : ft_putchar(data->spec->car);
	}
	if (data->spec->unint)
		data->lngt->width ? prt_unint_width(data->spec, data->lngt, data->flag) : ft_putnbr(data->spec->unint);
	/*if (data->spec->signcar)
	{
		(data->spec->signcar && data->lngt->width > 1) ?
		data->spec = : ft_putchar(data->spec->signcar);
	}
	if (data->spec->sh)
		data->lngt->width ? : ft_putnbr(data->spec->sh);
	if (data->spec->lg)
		data->lngt->width ? : ft_putnbr(data->spec->lg);
	if (data->spec->lglg)
		data->lngt->width ? : ft_putnbr(data->spec->lglg);
	if (data->spec->unsigncar)
	{
		(data->spec->unsigncar && data->lngt->width > 1) ?
		data->spec = : ft_putnbr(data->unsigncar);
	}
	if (data->spec->unsignsh)
		data->lngt->width ? : ft_putnbr(data->spec->unsignsh);
	if (data->spec->unsignlg)
		data->lngt->width ? : ft_putnbr(data->spec->unsignlg);
	if (data->spec->unsignlglg)
		data->lngt->width ? : ft_putnbr(data->spec->unsignlglg);*/
}
