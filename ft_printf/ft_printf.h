/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:32:38 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/13 12:07:36 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct			s_data
{
	/* Gestion des Flags : 1 ou 0*/
	int					unsign;
	int					minus;
	int					plus;
	int					zero;
	int					space;
	int					sharp;

	/* Gestion de la longueur de champs : longueur donnee. */
	int					width;
	int					precision;

	/* Gestion de Size */
	int					h;
	int					ll;
	int					l;
	int					hh;

	/* Gestion du type  cspdiouxX*/
	int					c;
	int					s;
	int					p;
	int					d;
	int					i;
	int					o;
	int					u;
	int					x;
	int					big_x;

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
	char				*str_tp;

	/* Nombre de caracteres imprimes */
	int					nb_printed;

	/* cas special : si on a "%%" et qu'il y a des instructions entre les %*/
	int					perc;

	/* Pour gerer data.width on a besoin de l'index i  */
	int					index;


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
t_data					print_all(t_data data);
t_data 					flag_minus(t_data data, int size_of_integer);

#endif
