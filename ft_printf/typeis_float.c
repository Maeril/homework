/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:14:29 by myener            #+#    #+#             */
/*   Updated: 2019/04/03 15:56:34 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

#include "ft_printf.h"
#include <stdlib.h>

static int infnan(t_data *data, double num, int len)
{
	t_lngt *lngt;
	t_flag *flag;

	lngt = data->lngt;
	flag = data->flag;
	if (num != num)
	{
		len += flag->minus ?  2 : 1;
		if ((lngt->width && (lngt->width_value > 0)) && !flag->minus && (lngt->width_value > (len + 1)))
			widthprinter_nominus(data, len);
		ft_putstr("nan");
		if (lngt->width && lngt->width_value && flag->minus)
			widthprinter_minus(data, len);
		return (1);
	}
	else if (num >= 1 / 0.0 && num <= 1 / 0.0)
    {
		len += flag->minus ?  2 : 1;
		if ((lngt->width && (lngt->width_value > 0)) && !flag->minus && (lngt->width_value > (len + 1)))
			widthprinter_nominus(data, len);
		ft_putstr("inf");
		if (lngt->width && lngt->width_value && flag->minus)
			widthprinter_minus(data, len);
		return (1);
	}
	else if (num >= -1 / 0.0 && num <= -1 / 0.0)
	{
		len += flag->minus ?  3 : 2;
		if ((lngt->width && (lngt->width_value > 0)) && !flag->minus && (lngt->width_value > (len + 1)))
			widthprinter_nominus(data, len);
		ft_putstr("-inf");
		if (lngt->width && lngt->width_value && flag->minus)
			widthprinter_minus(data, len);
		return (1);
	}
	return (0);
}

static void	troubleshooter(t_data *data, long long int num, int prec_len, int len)
{
	t_lngt	*lngt;
	t_flag	*flag;
	t_spec	*spec;

	spec = data->spec;
	lngt = data->lngt;
	flag = data->flag;
	if (lngt->prec && !lngt->prec_rien && !lngt->prec_zero)
		prec_len = lngt->prec_value;
	lngt->prec = (lngt->prec && (lngt->prec_value <= prec_len)) ? 0 : lngt->prec;
	lngt->width = (lngt->width && ((lngt->width_value <= len + prec_len) ||
		((lngt->prec && (lngt->width_value <= len + prec_len))))) ?
		0 : lngt->width;
	if (spec->flt < 0)
	{
		ft_putchar('-');
		data->tool->vir++;
	}
	else if (flag->plus || flag->space)
	{
		if (flag->plus)
			ft_putchar('+');
		else if (flag->space)
			ft_putchar(' ');
		data->tool->vir++;
	}
	num += 1;
	num -= 1;
	if (flag->sharp && (!flag->zero || (flag->sharp && (spec->flt - num == 0) && flag->zero)))
		data->tool->vir++;
	len += data->tool->vir;
	len += prec_len;
	if ((lngt->width && (lngt->width_value > 0)) && !flag->minus && (lngt->width_value > (len + 1)))
		widthprinter_nominus(data, len);
	if (lngt->prec_zero)
		return ;
	if (spec->flt < 0)
		spec->flt = -spec->flt;
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
	stk = ft_strnew(len + 2);
	stk = ft_lltoa(num);
	data->tool->vir = !data->tool->vir ? 1 : data->tool->vir;
	data->tool->vir += ((data->lngt->prec_rien || data->lngt->prec_zero) ? (prec_len - 1) : prec_len);
	data->tool->vir -= (!data->lngt->prec_rien && !data->lngt->prec_zero) ? 1 : 0;
	if (((data->lngt->prec_rien || data->lngt->prec_zero)) && ((stk[len - 1] >= '5') || num == 0 ))
	{
		if ((num != 0) && (stk[len - 1] > '5'))
			num = ft_atoll(stk) + 1;
		num -= (!data->tool->neg && num != 0 && (stk[len - 1] > '5')) ? 1 : 0;
		ft_putnbr_long(num);
		if (data->flag->sharp)
			ft_putchar('.');
		data->tool->vir += (data->flag->sharp ? 1 : 0);
	}
	else if ((!data->lngt->prec_rien && !data->lngt->prec_zero && num == 0) || num != 0)
	{
		ft_putnbr_long(num);
		if ((!data->lngt->prec_rien && !data->lngt->prec_zero) || data->flag->sharp)
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
	data->lngt->prec_value = prec_len;
	if (!zero)
		while (i++ < (prec_len - 1))
			ft_putchar(str[i]);
	else if (zero)
		precision_printer(data, (((int)ft_strlen(str))));
}

int			typeis_float(va_list ap, t_data *data)
{
	int						prec_len;
	int						len;
	long long int			num;
	char					*str;
	t_spec					*spec;

	spec = data->spec;
	len = 0;
	if (data->type->f)
	{
		data->lngt->width_value = data->lngt->width_value;
		prec_len = (data->lngt->prec ? (data->lngt->prec_value + 1) : 7);
		prec_len = ((data->lngt->prec_zero || data->lngt->prec_rien) ? 0 : prec_len);
		spec->flt = va_arg(ap, double);
		data->tool->stock = spec->flt;
		num = spec->flt;
		len = ft_intlen(num);
		if (infnan(data, spec->flt, len))
			return (0);
		troubleshooter(data, num, prec_len, len);
		spec->flt = (spec->flt < 0) ? -spec->flt : spec->flt;
		data->tool->neg = (num < 0) ? 1 : 0;
		num = (num < 0) ? -num : num;
		spec->flt -= num;
		if (!(str = malloc(sizeof(char) * (prec_len + 1))))
			return (0);
		overthedot(data, str);
		str = ft_strsub(str, 0, prec_len);
		if (((data->lngt->prec_zero || data->lngt->prec_rien) && spec->flt != 0) || spec->flt || spec->flt == 0)
		{
			writer(data, prec_len, str, num);
			len = (ft_intlen(num) + data->tool->vir);
			if (data->lngt->width && data->lngt->width_value && data->flag->minus)
				widthprinter_minus(data, len);
			return ((len < data->lngt->width_value) ? data->lngt->width_value : len);
		}
		return(data->lngt->width_value);
	}
	return (-1);
}
