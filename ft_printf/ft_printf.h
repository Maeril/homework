/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:32:38 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/18 22:20:09 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

# define OCT "01234567"
# define DECI "0123456789"
# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"


typedef struct			s_flag
{
	int					minus;
	int					plus;
	int					zero;
	int					space;
	int					sharp;
}						t_flag;

typedef struct			s_lngt
{
	int					width;
	int					precision;
}						t_lngt;

typedef struct			s_data
{
	t_flag 				flag;
	t_lngt 				lngt;
	int					typ;
	int					len;
}						t_data;

int						convert_percent(va_list ap, t_data *data);
int						convert_int(va_list ap, t_data *data);
int						convert_uint(va_list ap, t_data *data);
int						convert_uhexl(va_list ap, t_data *data);
int						convert_uhexu(va_list ap, t_data *data);
int						convert_uoctal(va_list ap, t_data *data);
int						convert_char(va_list ap, t_data *data);
int						convert_string(va_list ap, t_data *data);
int						convert_pointer(va_list ap, t_data *data);

typedef struct			s_convert
{
	char				car;
	int					(*func)(va_list ap, t_data *data);
}						t_convert;

static const t_convert	g_conversions[] = {
	{'%', convert_percent},
	{'d', convert_int},
	{'i', convert_int},
	{'u', convert_uint},
	{'x', convert_uhexl},
	{'X', convert_uhexu},
	{'o', convert_uoctal},
	{'c', convert_char},
	{'s', convert_string},
	{'p', convert_pointer},
	NULL
};

/* t_convert g_conversions[data->typ].func(ap, data); */

#endif
