/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:51:38 by myener            #+#    #+#             */
/*   Updated: 2019/04/03 14:07:21 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			troubleshooter(t_data *data, int len)
{
	t_lngt *lngt;

	lngt = data->lngt;
	lngt->width = (lngt->prec && (lngt->width_value <= lngt->prec_value)) ?
		0 : lngt->width;
	lngt->prec = (lngt->prec && (lngt->prec_value >= len)) ? 0 : lngt->prec;
	if (lngt->prec && !lngt->prec_rien && !lngt->prec_zero)
		len = lngt->prec_value;
	return (len);
}

void		errormanager(t_data *data, int len, char *err)
{
	if (data->tool->str_tp == NULL)
	{
		len = 6;
		if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
			widthprinter_nominus(data, len);
		if (!data->lngt->prec_zero && !data->lngt->prec_rien)
			ft_putstr("(null)");
		if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
			widthprinter_minus(data, len);
	}
	else if (ft_strcmp(data->tool->str_tp, err) == 0)
	{
		len = 0;
		if ((data->lngt->width && (data->lngt->width_value > 0)))
			widthprinter_nominus(data, len);
	}
}

int		typeis_str(va_list ap, t_data *data)
{
	int		i;
    int     len;
	int		prec_len;
	char	*err;

	err = "";
	if (data->tool->str_tp || data->type->s)
	{
		len = 0;
		data->tool->str_tp = va_arg(ap, char*);
		if (data->tool->str_tp == NULL || ft_strcmp(data->tool->str_tp, err) == 0)
		{
			errormanager(data, len, err);
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		len = ft_strlen(data->tool->str_tp);
		len = troubleshooter(data, len);
		prec_len = (data->lngt->prec && !data->lngt->prec_rien && !data->lngt->prec_zero) ?
			ft_strlen(data->tool->str_tp) : 0;
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && prec_len > 0) || len)
		{
			if ((data->lngt->width && (data->lngt->width_value > 0)) && !data->flag->minus)
				widthprinter_nominus(data, len);
			if ((!data->lngt->prec_zero && !data->lngt->prec_rien) || data->lngt->prec)
			{
				if (data->lngt->prec && ((data->lngt->prec_value <= prec_len && (data->lngt->prec_value > 1))))
				{
					i = -1;
					while (i++ < (data->lngt->prec_value - 1))
						ft_putchar(data->tool->str_tp[i]);
					len = (data->lngt->prec_value <= len) ? data->lngt->prec_value : len;
				}
				else if (!data->lngt->prec || ((data->lngt->prec && data->lngt->prec_value > prec_len)))
					ft_putstr(data->tool->str_tp);
			}
			if ((data->lngt->width && (data->lngt->width_value > 0)) && data->flag->minus)
				widthprinter_minus(data, len);
			if (data->lngt->prec_value > data->lngt->width_value) // pas sure que ca soit utile (p-e source de bugs)
				data->lngt->width_value += data->lngt->prec_value;
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return (data->lngt->width_value);
	}
	return (-1);
}
