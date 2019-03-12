/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:29 by myener            #+#    #+#             */
/*   Updated: 2019/03/12 16:04:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void	display_float(int len, char *str, unsigned long long int tmp)
{
	int i;
	int zero;

	zero = (((int)ft_strlen(str)) < len);
	if (str[len - 1] >= '5')
	{
		str[len - 1] = '\0';
		tmp = (ft_atoll(str)) + 1;
		str = ft_lltoa(tmp);
	}
	else
		str[len - 1] = '\0';
	ft_putchar('.');
	i = -1;
	while (i++ < (len - 1))
		ft_putchar(str[i]);
	i = -1;
	if (zero)
		while (i++ < (len - ((int)ft_strlen(str)) - 2))
			ft_putchar('0');
}

void	overthedot(t_data *data, char *str, unsigned long long int tmp)
{
	int	i;

	i = -1;
	while (data->spec->flt)
	{
		data->spec->flt *= 10;
		tmp = data->spec->flt;
		str[++i] = ft_itoc(tmp);
		data->spec->flt -= tmp;
	}
}

void	troubleshooter(t_data *data, long long int num, int len)
{
	if (data->lngt->width && data->lngt->width_value && !data->flag->minus)
		widthprinter_nominus(data, (ft_intlen(num) + len));
	if (data->flag->space &&
		(data->lngt->width_value < (ft_intlen(num) + len)))
		ft_putchar(' ');
	if ((data->spec->flt > 0) && data->flag->plus)
		ft_putchar('+');
	if (data->lngt->prec_zero)
		return ;
	if (data->spec->flt < 0)
		data->spec->flt = -data->spec->flt;
}

void	typeis_float(va_list ap, t_data *data)
{
	int						len_prec;
	long long int			num;
	unsigned long long int	tmp;
	char					*str;

	if (data->type->f)
	{
		data->lngt->width_value = data->lngt->width_value;
		len_prec = (data->lngt->prec ? (data->lngt->prec_value + 1) : 7);
		data->spec->flt = va_arg(ap, double);
		if (data->flag->sharp)
			data->lngt->width_value++;
		num = data->spec->flt;
		troubleshooter(data, num, len_prec);
		data->spec->flt -= num;
		if (!(str = malloc(sizeof(char) * (len_prec + 1))))
			return ;
		tmp = 0;
		overthedot(data, str, tmp);
		str = ft_strsub(str, 0, len_prec);
		ft_putnbr(num);
		display_float(len_prec, str, tmp);
		if (data->lngt->width && data->lngt->width_value && data->flag->minus)
			widthprinter_minus(data, (ft_intlen(num) + len_prec));
	}
}
