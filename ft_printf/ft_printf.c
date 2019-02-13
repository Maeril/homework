/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:52:42 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/13 14:56:56 by myener           ###   ########.fr       */
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

int			put_text(va_list ap, const char *format)
{
	int		i;
	char	*instruc;
	t_data	data;
	int		nb;

	i = 0;
	nb = 0;
	data.integer = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			nb++;
		}
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				ft_putchar('%');
				nb++;
			}
			else
			{
				instruc = take_instructions(format, i);
				data = parse_instructions(instruc, data);
				data = finalize_instructions(data);
				data = find_arg_type(ap, data);
				data = print_all(data);
				data = clean_data(data);
				i++;
			}
			i++;
		}
		i++;
	}
	if (data.nb_printed)
		nb = data.nb_printed;
	if (data.width)
		nb = data.width;
	return (nb);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		nb;

	va_start(ap, format);
	nb = put_text(ap, format);
	va_end(ap);
	return (nb);
}

int			main(void)
{
	ft_putchar('\n');
	ft_printf("%d is one", 1);
	ft_putchar('\n');
	printf("%d is one", 1);
	return (0);
}
