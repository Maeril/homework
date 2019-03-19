/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:32:38 by myener            #+#    #+#             */
/*   Updated: 2019/03/19 16:00:26 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

# define OCT "01234567"
# define DECI "0123456789"
# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"
# define UINT_MAX 4294967296

typedef struct			s_spec
{
	int					integer;
	int					str;
	long double			flt;
	char				car;
	unsigned int		unint;
	signed char			signcar;
	short				sh;
	long				lg;
	long long			lglg;
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
	int					prec;
	int					prec_value;
	int					prec_zero;
	int					prec_rien;

}						t_lngt;

typedef struct			s_size
{
	int					h;
	int					hh;
	int					l;
	int					ll;
	int					big_l;
}						t_size;

typedef struct			s_type
{
	int					c;
	int					s;
	long long int		p;
	long long int		d;
	long long int		i;
	unsigned long long int		o;
	unsigned long long int		u;
	unsigned long long int		x;
	unsigned long long int		big_x;
	int					f;
}						t_type;

typedef struct			s_tool
{
	int					dioux;
	int					size;
	int					unsign;
	char				*str_tp;
	int					ret;
	int					perc;/* cas special : si on a "%%" et qu'il y a des instructions entre les %*/
	int					index;/* Pour gerer data.width on a besoin de l'index i  */
	int					index2;/* pour gerer data.precision on a besoin de l'index j */
}						t_tool;

typedef struct			s_data
{
	t_spec 				*spec;
	t_flag 				*flag;
	t_lngt 				*lngt;
	t_size 				*size;
	t_type 				*type;
	t_tool				*tool;
}						t_data;

int				ft_atoi(const char *str);
long long int	ft_atoll(const char *str);
void	ft_bzero(void *s, size_t n);
int				ft_intlen(long long int n);
int				ft_uintlen(unsigned long long int n);
int				ft_octlen(unsigned long long int n);
int				ft_hexlen(unsigned long long int n);
char			ft_itoc(int n);
char   			*ft_lltoa(long long int n);
void	*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putnbr_base(long long int nb, const char *base);
void			ft_putunbr_base(unsigned long long int nb, const char *base);
void			ft_putnbr_long(long long int nb);
void			ft_putunbr_long(unsigned long long int nb);
void			ft_putstr(char *str);
size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
void					cleaner(t_data *data);
void					finalizer(t_data *data);
int						ft_printf(const char *format, ...);
void					get_arg_len(va_list ap, t_data *data);
void					parse_flags(char *instruc, t_flag *flag, int i);
void					parse_precision(char *instruc, t_lngt *lngt, t_tool *tool, int i);
void					parse_size(char *instruc, t_size *size, int i);
void					parse_type(char *instruc, t_type *type, t_tool *tool, int i);
void					parse_width(char *instruc, t_data *data, int i);
void					parser(char *instruc, t_data *data);
void					precision_printer(t_data *data, int len);
int						put_text(va_list ap, const char *format, char *instruc);
void						dispatcher(va_list ap, t_data *data);
char					*take_instructions(const char *format, int i);
int						typeis_int(va_list ap, t_data *data);
int						typeis_perc(va_list ap, t_data *data);
int						typeis_str(va_list ap, t_data *data);
int						typeis_ptr(va_list ap, t_data *data);
int						typeis_char(va_list ap, t_data *data);
int						typeis_unsign(va_list ap, t_data *data);
int						typeis_octal(va_list ap, t_data *data);
int						typeis_hexl(va_list ap, t_data *data);
int						typeis_hexu(va_list ap, t_data *data);
int	       				typeis_float(va_list ap, t_data *data);
void        			widthprinter_minus(t_data *data, int len);
void      				widthprinter_nominus(t_data *data, int len);

#endif
