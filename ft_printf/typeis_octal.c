/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:59:01 by myener            #+#    #+#             */
/*   Updated: 2019/03/13 17:38:33 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void typeis_octal(va_list ap, t_data *data)
{
	int 			len;
	// long long int	num;
	// char			*res;

	if (data->type->o)
	{
		data->type->o = va_arg(ap, int);
		if (!data->tool->size)
			len = ft_octlen(data->type->o);
		else if (data->tool->size)
		{
			if (data->size->h)
				len = ft_octlen((unsigned short)data->type->o);
			else if (data->size->hh)
				len = ft_octlen((unsigned char)data->type->o);
			else if (data->size->l)
				len = ft_octlen((unsigned long)data->type->o);
			else if (data->size->ll)
				len = ft_octlen((unsigned long long)data->type->o);
		}
		if (data->flag->sharp)
			len++;
		if (data->lngt->prec && (data->lngt->prec_value <= len))
			data->lngt->prec = 0;
		if (data->lngt->prec && (data->lngt->prec_value >= data->lngt->width_value))
			data->lngt->width = 0;
		if (data->lngt->prec && (data->lngt->prec_value < data->lngt->width_value) && !data->flag->sharp)
			data->lngt->width_value -= data->lngt->prec_value;
		else if (data->lngt->prec && (data->lngt->prec_value < data->lngt->width_value) && data->flag->sharp)
			data->lngt->width_value -= (data->lngt->prec_value - 3);
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if (data->flag->sharp)
			ft_putchar('0');
		if (data->lngt->prec)
			precision_printer(data, len);
		if (!data->tool->size)
			ft_putnbr_base(data->type->o, OCT);
		else if (data->tool->size)
		{
			if (data->size->h)
				ft_putnbr_base(((unsigned short)data->type->o), OCT);
			else if (data->size->hh)
				ft_putnbr_base(((unsigned char)data->type->o), OCT);
			else if (data->size->l)
				ft_putnbr_base(((unsigned long)data->type->o), OCT);
			else if (data->size->ll)
				ft_putnbr_base(data->type->o, OCT);
		}
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
}
