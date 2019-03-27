/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:29 by myener            #+#    #+#             */
/*   Updated: 2019/03/27 14:43:37 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	troubleshooter(t_data *data, long long int num, int len)
{
	t_lngt *lngt;
	t_flag *flag;

	lngt = data->lngt;
	flag = data->flag;
	if ((lngt->width && (lngt->width_value > 0)) && !flag->minus && !lngt->prec)
		widthprinter_nominus(data, len);
	else if ((lngt->width && (lngt->width_value > 0)) && !flag->minus && lngt->prec)
		widthprinter_nominus(data, lngt->prec_value);
	if (flag->space && (lngt->width_value < (ft_intlen(num) + len)) && (num >= 0))
		ft_putchar(' ');
	if (data->spec->flt < 0)
		ft_putchar('-');
	if ((data->spec->flt > 0) && flag->plus)
		ft_putchar('+');
	if (lngt->prec_zero)
		return ;
	if (data->spec->flt < 0)
		data->spec->flt = -data->spec->flt;
}

static void	overthedot(t_data *data, char *str, unsigned long long int tmp)
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

static void	display_float(int prec_len, char *str, unsigned long long int tmp)
{
	int i;
	int zero;

	zero = (((int)ft_strlen(str)) < prec_len);
	if (str[prec_len - 1] >= '5')
	{
		str[prec_len - 1] = '\0';
		tmp = (ft_atoll(str)) + 1;
		str = ft_lltoa(tmp);
	}
	else
		str[prec_len - 1] = '\0';
	ft_putchar('.');
	prec_len -= 1;
	i = -1;
	while (i++ < (prec_len - 1))
		ft_putchar(str[i]);
	i = -1;
	if (zero)
		while (i++ < (prec_len - ((int)ft_strlen(str)) - 1))
			ft_putchar('0');
}

int			typeis_float(va_list ap, t_data *data)
{
	int						prec_len;
	int						len;
	long long int			num;
	unsigned long long int	tmp;
	char					*str;

	len = 0;
	if (data->type->f)
	{
		data->lngt->width_value = data->lngt->width_value;
		prec_len = (data->lngt->prec ? (data->lngt->prec_value + 1) : 7);
		data->spec->flt = va_arg(ap, double);
		if (data->flag->sharp)
			data->lngt->width_value++;
		num = data->spec->flt;
		troubleshooter(data, num, prec_len);
		data->spec->flt = (data->spec->flt < 0) ? -data->spec->flt : data->spec->flt;
		num = (num < 0) ? -num : num;
		data->spec->flt -= num;
		if (!(str = malloc(sizeof(char) * (prec_len + 1))))
			return (0);
		tmp = 0;
		overthedot(data, str, tmp);
		str = ft_strsub(str, 0, prec_len);
		ft_putnbr(num);
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && data->type->f > 0) || data->type->f)
		{
			display_float(prec_len, str, tmp);
			if (data->lngt->width && data->lngt->width_value && data->flag->minus)
				widthprinter_minus(data, (ft_intlen(num) + prec_len));
			len = (ft_intlen(num) + prec_len);
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return(data->lngt->width_value);
	}
	return (-1);
}
