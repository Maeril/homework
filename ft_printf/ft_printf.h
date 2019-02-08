/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:32:38 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 15:22:14 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>

typedef struct      		s_data
{
	int             		minus;
	int             		plus;
	int             		zero;
	int             		space;
	int             		sharp;
	int             		width;
	int             		precision;
	int             		h;
	int             		ll;
	int             		l;
	int             		hh;
	int						c;
	int						s;
	int						p;
	int						d;
	int						i;
	int						o;
	int						u;
	int						x;
	int						X;
// je mets les types possibles 

	int						integer;
	char					car;
	int						str; // ancien char *str
	unsigned int			unint;
	signed char				signcar;
	short					sh;
	long					lg;
	long long				lglg;
	unsigned char			unsigncar;
	unsigned short			unsignsh;
	unsigned long			unsignlg;
	unsigned long long		unsignlglg; 
}                   		t_data;
	
char						*take_instructions(const char *format, int i);

int							ft_printf(const char *format, ...);


t_data						check_plus_flag(t_data data);
t_data						check_zero(t_data data);
t_data						check_sharp(t_data data);
t_data						finalize_instructions(t_data data);
t_data						find_arg_type(va_list ap, t_data data, char *instructions, int i);
t_data						parse_flags(char *instructions, t_data data, int i);
t_data						parse_instructions(char *instructions, t_data data);
t_data						parse_precision(char *instructions, t_data data, int i);
t_data						parse_size(char *instructions, t_data data, int i);
t_data						parse_type(char *instructions, t_data data, int i);
t_data						parse_width(char *instructions, t_data data, int i);

void						put_text(va_list ap, const char *format);




#endif
