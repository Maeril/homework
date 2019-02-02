/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:52:45 by myener            #+#    #+#             */
/*   Updated: 2019/02/02 17:49:51 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>

typedef struct	s_tetri
{
	char			**tetri;
	char			key;
	int				x;
	int				y;
	struct s_tetri	*next;
}				t_tetri;

int		ft_printf(const char *format);

#endif
