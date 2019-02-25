/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:32:38 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/25 15:35:02 by myener           ###   ########.fr       */
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
# define UINT_MAX 4294967296

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
	int					width_value;
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
	int					f;
	int					pourcentage;
}						t_type;

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

typedef struct			s_data
{
	// char				type;
	t_spec 				*spec;
	t_flag 				*flag;
	t_lngt 				*lngt;
	t_size 				*size;
	t_type 				*type;
	t_tool				*tool;
}						t_data;

void					check_zero(t_type *type, t_flag *flag);
void					check_sharp(t_type *type, t_flag *flag);
void					check_unsigned(t_type *type, t_size *size, t_tool *tool);
void					cleaner(t_data *data);
void					finalizer(t_data *data);
int						ft_printf(const char *format, ...);
void					get_arg_len(va_list ap, t_data *data);
void					parse_flags(char *instruc, t_flag *flag, int i);
void					parse_precision(char *instruc, t_lngt *lngt, t_tool *tool, int i);
void					parse_size(char *instruc, t_size *size, int i);
void					parse_type(char *instruc, t_type *type, t_tool *tool, int i);
void					parse_width(char *instruc, t_lngt *lngt, t_tool *tool, int i);
void					parser(char *instruc, t_data *data);
void					prt_precision(t_lngt *lngt, t_flag *flag, t_spec *spec);
int						put_text(va_list ap, const char *format, char *instruc);
void					dispatcher(va_list ap, t_data *data);
char					*take_instructions(const char *format, int i);
void					typeis_int(va_list ap, t_data *data);
void					typeis_perc(va_list ap, t_data *data);
void					typeis_str(va_list ap, t_data *data);
void					typeis_ptr(va_list ap, t_data *data);
void					typeis_char(va_list ap, t_data *data);
void					typeis_unsign(va_list ap, t_data *data);
void					typeis_octal(va_list ap, t_data *data);
void					typeis_hexl(va_list ap, t_data *data);
void					typeis_hexu(va_list ap, t_data *data);

#endif
