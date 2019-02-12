/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:32:38 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/12 11:34:40 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct			s_data
{
	int					unsign;
	int					minus;
	int					plus;
	int					zero;
	int					space;
	int					sharp;
	int					width;
	int					precision;
	int					h;
	int					ll;
	int					l;
	int					hh;
	int					c;
	int					s;
	int					p;
	int					d;
	int					i;
	int					o;
	int					u;
	int					x;
	int					big_x;
	int					integer;
	int					str;
	char				car;
	unsigned int		unint;
	signed char			signcar;
	short				sh;
	long				lg;
	long long			lglg;
	unsigned char		unsigncar;
	unsigned short		unsignsh;
	unsigned long		unsignlg;
	unsigned long long	unsignlglg;
}						t_data;

t_data					check_zero(t_data data);
t_data					check_sharp(t_data data);
t_data					clean_data(t_data data);
t_data					finalize_instructions(t_data data);
t_data					find_arg_type(va_list ap, t_data data);
int						ft_printf(const char *format, ...);
t_data					parse_flags(char *instruc, t_data data, int i);
t_data					parse_instructions(char *instruc, t_data data);
t_data					parse_precision(char *instruc, t_data data, int i);
t_data					parse_size(char *instruc, t_data data, int i);
t_data					parse_type(char *instruc, t_data data, int i);
t_data					parse_width(char *instruc, t_data data, int i);
int						put_text(va_list ap, const char *format);
char					*take_instructions(const char *format, int i);
t_data					typeis_int(va_list ap, t_data data);
t_data					typeis_char(va_list ap, t_data data);
t_data					typeis_unsign(va_list ap, t_data data);

#endif
