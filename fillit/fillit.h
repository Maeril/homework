/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:45:59 by myener            #+#    #+#             */
/*   Updated: 2019/01/24 14:12:32 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_block
{
	int 		x;
	int 		y;
} 				t_block;

typedef	struct			s_forme
{
	t_block				*block_tab;
	char				letter;
	struct s_forme		*next;
}						t_forme;


#endif