/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:47 by myener            #+#    #+#             */
/*   Updated: 2019/03/13 18:47:05 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void typeis_int(va_list ap, t_data *data)
{
	long long int nb;
	int len;

	if (data->type->d || data->type->i)
	{
		nb = va_arg(ap, int);
		if (!data->tool->size)
			len = ((nb < 0) ? (ft_intlen(nb) + 2) : ft_intlen(nb));
		else if (data->tool->size)
		{
			if (data->size->h)
				len = ft_intlen((short)nb);
			else if (data->size->hh)
				len = ft_intlen((char)nb);
			else if (data->size->l)
				len = ft_intlen((long)nb);
			else if (data->size->ll)
				len = ft_intlen(nb);
		}
		len = ((data->flag->plus && nb > 0) || (data->flag->space && nb > 0)
				|| (data->flag->plus && data->flag->space && nb > 0) ?
				(len + 1) : len);
		if (data->lngt->prec && (data->lngt->prec_value <= len))
			data->lngt->prec = 0;
		if (data->lngt->prec
			&& (data->lngt->prec_value >= data->lngt->width_value))
			data->lngt->width = 0;
		if (data->lngt->prec
			&& (data->lngt->prec_value < data->lngt->width_value))
			data->lngt->width_value -= (data->lngt->prec_value - 2);
		if ((data->lngt->width && (data->lngt->width_value > 0))
			&& !data->flag->minus)
			widthprinter_nominus(data, len);
		if (!data->tool->size)
		{
			if (nb < 0)
			{
				ft_putchar('-');
				nb = -nb;
				len--;
			}
		}
		else if (data->tool->size)
		{
			if (data->size->h)
			{
				if (((short)nb) < 0)
				{
					ft_putchar('-');
					nb = -nb;
					len--;
				}
			}
			else if (data->size->hh)
			{
				if (((char)nb) < 0)
				{
					ft_putchar('-');
					nb = -nb;
					len--;
				}
			}
			else if (data->size->l)
			{
				if (((long)nb) < 0)
				{
					ft_putchar('-');
					nb = -nb;
					len--;
				}
			}
			else if (data->size->ll)
			{
				if (nb < 0)
				{
					ft_putchar('-');
					nb = -nb;
					len--;
				}
			}
		}
		if (!data->tool->size && (nb > 0) && (data->flag->plus ||
			data->flag->space))
		{	if (data->flag->plus)
				ft_putchar('+');
			else if (data->flag->space)
				ft_putchar(' ');
		}
		else if (data->tool->size && (data->flag->plus || data->flag->space))
		{
			if (data->flag->plus)
			{
				if ((data->size->h && (((short)nb) > 0)) || (data->size->hh
					&& (((char)nb) > 0)) || ((data->size->l || data->size->ll)
					&& (nb > 0)))
					ft_putchar('+');
			}
			else if (data->flag->space)
			{
				if ((data->size->h && (((short)nb) > 0)) || (data->size->hh
					&& (((char)nb) > 0)) || ((data->size->l || data->size->ll)
					&& (nb > 0)))
					ft_putchar(' ');
			}
		}
		if (data->lngt->prec)
			precision_printer(data, len);
		if (!data->tool->size)
			ft_putnbr_long(nb);
		else if (data->tool->size)
		{
			if (data->size->h)
				ft_putnbr_long((short)nb);
			else if (data->size->hh)
				ft_putnbr_long((char)nb);
			else if (data->size->l)
				ft_putnbr_long((long)nb);
			else if (data->size->ll)
				ft_putnbr_long(nb);
		}
		if ((data->lngt->width && (data->lngt->width_value > 0))
			&& data->flag->minus)
			widthprinter_minus(data, len);
	}
}
