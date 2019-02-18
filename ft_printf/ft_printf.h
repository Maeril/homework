/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:32:38 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/18 17:14:24 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

# define OCT "01234567"
# define DECI "0123456789"
# define HEXA "0123456789abcdef"
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
int						convert_uhexd(va_list ap, t_data *data);
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
	{'x', convert_uhexd},
	{'X', convert_uhexu},
	{'o', convert_uoctal},
	{'c', convert_char},
	{'s', convert_string},
	{'p', convert_pointer},
	NULL
}

g_conversions[data->typ].func(ap, data);

void					check_zero(t_type *type, t_flag *flag);
void					check_sharp(t_type *type, t_flag *flag);
void					check_unsigned(t_type *type, t_size *size, t_tool *tool);
void					clean_data(t_data *data);
int	    				conv_octal(int nb);
void					finalize_instructions(t_data *data);
void					find_arg_type(va_list ap, t_data *data);
void 					flag_minus(t_lngt *lngt, int size);
int						ft_printf(const char *format, ...);
void					parse_flags(char *instruc, t_flag *flag, int i);
void					parse_instructions(char *instruc, t_data *data);
void					parse_precision(char *instruc, t_lngt *lngt, t_tool *tool, int i);
void					parse_size(char *instruc, t_size *size, int i);
void					parse_type(char *instruc, t_type *type, t_tool *tool, int i);
void					parse_width(char *instruc, t_lngt *lngt, t_tool *tool, int i);
void					print_all(t_data *data);
int						put_text(va_list ap, const char *format, char *instruc);
char					*take_instructions(const char *format, int i);
void					typeis_int(va_list ap, t_spec *spec);
void					typeis_char(va_list ap, t_data *data);
void					typeis_unsign(va_list ap, t_tool *tool, t_spec *spec);
void					width_and_precision(t_lngt *lngt);
void					prt_precision(t_lngt *lngt, t_flag *flag, t_spec *spec);
void					print_octal(t_data *data, va_list ap);
void					pourcentage(t_data *data);

#endif
