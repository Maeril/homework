/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:32:38 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 16:51:18 by myener           ###   ########.fr       */
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

typedef struct			s_spec
{
	/* Gestion du type s'il y a une size : signed char, short, long
	 * long long, unsigned char/short/long/longlong*/
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
}						t_spec;

typedef struct			s_tool
{
	int					unsign;
	char				*str_tp;
	/* Nombre de caracteres imprimes */
	int					nb_a; // compteur pour chaque caractere imprimes de l argument
	int					nb_printed;
	int					perc;/* cas special : si on a "%%" et qu'il y a des instructions entre les %*/
	int					index;/* Pour gerer data.width on a besoin de l'index i  */
	int					index2;/* pour gerer data.precision on a besoin de l'index j */
	/* data */
}						t_tool;


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
	int					precision_dot;
	int					precision_zero;/* Quand on a une precision egale a zero.*/

}						t_lngt;

typedef struct			s_size
{
	int					h;
	int					ll;
	int					l;
	int					hh;
}						t_size;

typedef struct			s_type
{
	int					c;
	int					s;
	int					p;
	int					d;
	int					i;
	int					o;
	int					u;
	int					x;
	int					big_x;
	int					pourcentage;
}						t_type;

typedef struct			s_data
{
	t_spec 				*spec;
	t_flag 				*flag;
	t_lngt 				*lngt;
	t_size 				*size;
	t_type 				*type;
	t_tool				*tool;
}						t_data;

t_data					check_zero(t_data data);
t_data					check_sharp(t_data data);
t_data					clean_data(t_data data);
t_data					finalize_instructions(t_data data);
t_data					find_arg_type(va_list ap, t_data data);
int						ft_printf(const char *format, ...);
void					parse_flags(char *instruc, t_data *data, int i);
void					parse_instructions(char *instruc, t_data *data);
void					parse_precision(char *instruc, t_data *data, int i);
void					parse_size(char *instruc, t_data *data, int i);
void					parse_type(char *instruc, t_data *data, int i);
void					parse_width(char *instruc, t_data *data, int i);
int						put_text(va_list ap, const char *format);
char					*take_instructions(const char *format, int i);
t_data					typeis_int(va_list ap, t_data data);
t_data					typeis_char(va_list ap, t_data data);
t_data					typeis_unsign(va_list ap, t_data data);
t_data					print_all(t_data data);
t_data 					flag_minus(t_data data, int size_of_integer);
t_data					width_and_precision(t_data data);
t_data					prt_precision(t_data data);
t_data					print_octal(t_data data, va_list ap);
int						conv_octal(int i);
t_data					pourcentage(t_data data);

#endif
