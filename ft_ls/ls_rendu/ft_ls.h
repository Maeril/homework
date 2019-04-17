/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:43:08 by myener            #+#    #+#             */
/*   Updated: 2019/04/17 15:48:11 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS

# define FT_LS
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "ls_libft/libft.h"
# include "ls_libft/ft_printf/ft_printf.h"

typedef struct 			s_lsflag
{
	int					flag;
	// int					A;
	// int					B;
	// int					C;
	// int					F;
	// int					G;
	// int					H;
	// int					L;
	// int					O;
	// int					P;
	int					R;
	// int					S;
	// int					T;
	// int					U;
	// int					W;
	int					a;
	// int					b;
	// int					c;
	// int					d;
	// int					e;
	// int					f;
	// int					g;
	// int					h;
	// int					i;
	// int					k;
	int					l;
	// int					m;
	// int					n;
	// int					o;
	// int					p;
	// int					q;
	int					r;
	// int					s;
	int					t;
	// int					u;
	// int					w;
	// int					x;
	// int					un;
	// int					arobase;
}						t_lsflag;

void	initializer(t_lsflag *lsflag);
void	ls_struct_malloc(t_lsflag *lsflag);
void	ls_free_malloc(t_lsflag *lsflag);
void	ls_parser(t_lsflag *lsflag, char *str);
int		ls_recursive(const char *name, t_lsflag *lsflag);
void	flag_manager(t_lsflag *lsflag, struct dirent *repo);

#endif