/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:53:33 by myener            #+#    #+#             */
/*   Updated: 2019/07/17 17:29:06 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct			s_psflag
{
	int		ch;
	int		ps;
}						t_psflag;

typedef struct			s_pslist
{
	int				data;
	char			type;
	struct s_pslist	*next;
	struct s_pslist	*prev;

}						t_pslist;

void		checker(t_pslist *list, t_psflag *flag, char **argv);
int			check_length(t_pslist *list);
int			check_list(t_pslist *list, t_psflag *flag);
t_pslist	*convertto_list(char **argv, t_pslist *list, int *nb);
t_pslist	*node_malloc(t_pslist *node);
t_pslist	*node_fill(t_pslist *node, int data);
t_pslist	*ps_quicksort(/* char *instruc , */t_pslist **head_a, int deb, int fin);
int			ps_output(int i);
void		push(/* char *instruc , */t_pslist **src, t_pslist **dest);
void		push_swap(t_pslist *list, t_psflag *flag, char **argv);
void		rotate(/* char *instruc , */t_pslist **head, int nb);
void		rrotate(/* char *instruc , */t_pslist **head, int nb);
void		swap(/* char *instruc , */t_pslist *p1, t_pslist *p2);

#endif
