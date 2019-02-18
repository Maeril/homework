/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 11:22:42 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/18 22:21:13 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

char		*take_instructions(const char *format, int i)
{
	int		tmp;
	char	*instruc;
	char	*str;
	int		k;
	int		j;

	i++;
	tmp = i;
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' &&
			format[i] != 'd' && format[i] != 'i' && format[i] != 'o' &&
			format[i] != 'u' && format[i] != 'x' && format[i] != 'X'
			&& format[i] != '%' && format[i])
		i++;
	if (!format)
		return (NULL);
	if (!(str = malloc(sizeof(*format) * ((i - tmp + 1) + 1))))
		return (NULL);
	k = tmp;
	j = 0;
	while (format[k] && k < tmp + (i - tmp + 1))
		str[j++] = format[k++];
	str[j] = '\0';
	instruc = str;
	return (instruc);
}

int			put_text(va_list ap, const char *format, char *instruc)
{
	int		i;
	t_data	data;
	int		index;
	int		tmp;
	int		len;

	index = 0;
	tmp = 0;
	i = 0;
	len = 0;
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
			parse_instructions(instruc, &data);
			finalize_instructions(&data);
			find_arg_type(ap, &data);
			print_all(&data);
			clean_data(&data);
		}
		i++;
	}
	index = index + tmp;
	return (index);
}

int			ft_printf(const char *format, ...)
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