/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:53:33 by myener            #+#    #+#             */
/*   Updated: 2019/06/23 20:24:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct			s_pslist
{
	int				data;
	struct s_pslist	*next;

}						t_pslist;

void		checker(t_pslist *list, char **argv);
int			check_length(t_pslist *list);
int			check_list(t_pslist *list);
t_pslist	*convertto_list(char **argv, t_pslist *list);
t_pslist	*list_malloc(t_pslist *list);
t_pslist	*listfill(t_pslist *list, int data);
void		ps_insertion_sort(t_pslist *list);
void		ps_quicksort(t_pslist *list);
int			ps_output(int i);
void		push_swap(t_pslist *list, char **argv);

#endif
