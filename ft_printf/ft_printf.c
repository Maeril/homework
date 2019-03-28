/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:22:42 by myener            #+#    #+#             */
/*   Updated: 2019/03/28 15:30:21 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		is_type(const char *format, int i)
{
	if (format[i] == 'c' || format[i] == 'p' || format[i] == 's' ||
			format[i] == 'd' || format[i] == 'i' || format[i] == 'o' ||
			format[i] == 'u' || format[i] == 'x' || format[i] == 'X' ||
			format[i] == 'f')
		return (0);
	else
		return (1);
}

char	*take_instructions(const char *format, int i)
{
	int		tmp;
	char	*str;
	int		k;
	int		j;

	i++;
	tmp = i;
	if (!format)
		return (NULL);
	while (is_type(format, i) && format[i] != '%' && format[i])
		i++;
	if (!(str = malloc(sizeof(*format) * ((i - tmp + 1) + 1))))
		return (NULL);
	k = tmp;
	j = 0;
	while (format[k] && k < tmp + (i - tmp + 1))
		str[j++] = format[k++];
	str[j] = '\0';
	return (str);
}

void	struct_malloc(t_data *data)
{
	if (!(data->spec = malloc(sizeof(t_spec))))
		return ;
	if (!(data->flag = malloc(sizeof(t_flag))))
		return ;
	if (!(data->lngt = malloc(sizeof(t_lngt))))
		return ;
	if (!(data->size = malloc(sizeof(t_size))))
		return ;
	if (!(data->type = malloc(sizeof(t_type))))
		return ;
	if (!(data->tool = malloc(sizeof(t_tool))))
		return ;
}

int		put_text(va_list ap, const char *format, char *instruc)
{
	int		i;
	t_data	data;
	int		index;
	int		tmp;
	int		len;
	int		ret;

	index = 0;
	tmp = 0;
	i = 0;
	len = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			index++;
		}
		if (format[i] == '%')
		{
			instruc = take_instructions(format, i);
			len = ft_strlen(instruc);
			i = i + len;
			struct_malloc(&data);
			cleaner(&data);
			// printf("prec_value = %d\n", data.lngt->prec_value);
			parser(instruc, &data);
			// printf("prec_value = %d\n", data.lngt->prec_value);
			finalizer(&data);
			// printf("prec_value = %d\n", data.lngt->prec_value);
			dispatcher(ap, &data);
			ret += data.tool->ret;
			cleaner(&data);
		}
		i++;
	}
	index = index + ret;
	return (index);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		nb;
	char	*instruc;

	instruc = 0;
	va_start(ap, format);
	nb = put_text(ap, format, instruc);
	va_end(ap);
	return (nb);
}
