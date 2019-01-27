/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:45:59 by myener            #+#    #+#             */
/*   Updated: 2019/01/27 21:46:56 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct			s_block
{
	int 				x;
	int 				y;
} 						t_block;

struct					s_list
{
	t_block				*forme;
	char				letter;
	struct s_list		*next;
}						t_list;
#endif
