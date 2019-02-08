/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:32:38 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 15:18:03 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>

typedef struct      s_data
{
	int				unsign;
	int             minus;
	int             plus;
	int             zero;
	int             space;
	int             sharp;
	int             width;
	int             precision;
	int             h;
	int             ll;
	int             l;
	int             hh;
	int				c;
	int				s;
	int				p;
	int				d;
	int				i;
	int				o;
	int				u;
	int				x;
	int				X;
}                   t_data;

#endif
