/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:29 by myener            #+#    #+#             */
/*   Updated: 2019/03/27 18:53:20 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static void	troubleshooter(t_data *data, long long int num, int prec_len, int len)
{
	t_lngt *lngt;
	t_flag *flag;

	lngt = data->lngt;
	flag = data->flag;
	lngt->prec = (lngt->prec && (lngt->prec_value <= prec_len)) ? 0 : lngt->prec;
	lngt->width = (lngt->width && ((lngt->width_value <= len) ||
		((lngt->prec && (lngt->width_value <= lngt->prec_value))))) ?
		0 : lngt->width;
	if (lngt->prec && !lngt->prec_rien && !lngt->prec_zero)
		prec_len = lngt->prec_value;
	if ((lngt->width && (lngt->width_value > 0)) && !flag->minus && !lngt->prec)
		widthprinter_nominus(data, prec_len);
	else if ((lngt->width && (lngt->width_value > 0)) && !flag->minus && lngt->prec)
		widthprinter_nominus(data, lngt->prec_value);
	if (data->spec->flt < 0)
	{
		ft_putchar('-');
		data->tool->vir += 1;
	}
	else if ((data->spec->flt > 0) && (flag->plus || flag->space)
		&& (lngt->width_value < (ft_intlen(num) + prec_len)) && (num >= 0))
	{
		if (flag->plus)
			ft_putchar('+');
		else if (flag->space)
			ft_putchar(' ');
		data->tool->vir++;
	}
	if (lngt->prec_zero)
		return ;
	if (data->spec->flt < 0)
		data->spec->flt = -data->spec->flt;
}

static void	overthedot(t_data *data, char *str)
{
	int						i;
	unsigned long long int	tmp;

	i = -1;
	tmp = 0;
	while (data->spec->flt)
	{
		data->spec->flt *= 10;
		tmp = data->spec->flt;
		str[++i] = ft_itoc(tmp);
		data->spec->flt -= tmp;
	}
	data->tool->flt_tmp = tmp;
}

static void	writer(t_data *data, int prec_len, char *str, long long int num)
{
	int						i;
	int 					zero;
	unsigned long long int	tmp;
	int						len;
	char					*stk;

	zero = (((int)ft_strlen(str)) < prec_len);
	tmp = data->tool->flt_tmp;
	len = ((num < 0) ? ft_intlen(num) + 1 : ft_intlen(num));
	if (!(stk = malloc(sizeof(char) * (len + 2))))
			return ;
	stk = ft_lltoa(num);
	data->tool->vir += ((data->lngt->prec_rien || data->lngt->prec_zero) ? (prec_len - 1) : prec_len);
	if ((data->lngt->prec_rien || data->lngt->prec_zero) && (stk[len - 1] >= '5'))
	{
		num = (ft_atoll(stk)) + 1;
		ft_putnbr(num);
		if (data->flag->sharp)
			ft_putchar('.');
		data->tool->vir += (data->flag->sharp ? 1 : 0);
	}
	else if (!data->lngt->prec_rien && !data->lngt->prec_zero)
	{
		ft_putnbr(num);
		ft_putchar('.');
	}
	if (str[prec_len - 1] >= '5')
	{
		str[prec_len - 1] = '\0';
		tmp = (ft_atoll(str)) + 1;
		str = ft_lltoa(tmp);
	}
	else
		str[prec_len - 1] = '\0';
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
	char					*str;

	len = 0;
	if (data->type->f)
	{
		data->lngt->width_value = data->lngt->width_value;
		prec_len = (data->lngt->prec ? (data->lngt->prec_value + 1) : 7);
		data->spec->flt = va_arg(ap, double);
		num = data->spec->flt;
		len = ft_intlen(num);
		troubleshooter(data, num, prec_len, len);
		data->spec->flt = (data->spec->flt < 0) ? -data->spec->flt : data->spec->flt;
		num = (num < 0) ? -num : num;
		data->spec->flt -= num;
		if (!(str = malloc(sizeof(char) * (prec_len + 1))))
			return (0);
		overthedot(data, str);
		str = ft_strsub(str, 0, prec_len);
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && data->type->f != 0) || data->type->f)
		{
			writer(data, prec_len, str, num);
			if (data->lngt->width && data->lngt->width_value && data->flag->minus)
				widthprinter_minus(data, (ft_intlen(num) + prec_len));
			len = (ft_intlen(num) + data->tool->vir);
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return(data->lngt->width_value);
	}
	return (-1);
}
