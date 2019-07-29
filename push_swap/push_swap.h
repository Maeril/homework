/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:53:33 by myener            #+#    #+#             */
/*   Updated: 2019/07/27 17:20:54 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct			s_psflag
{
	int		ch;
	int		ps;
	char	*instruc;
}						t_psflag;

typedef struct			s_pslist
{
	int				data;
	char			type;
	struct s_pslist	*next;
	struct s_pslist	*prev;

}						t_pslist;

int			bad_instructions(char **instruc);
void		checker(t_pslist *list, t_psflag *flag, char **argv);
int			check_length(t_pslist *list);
int			check_list(t_pslist *list, t_psflag *flag);
t_pslist	*convertto_list(char **argv, t_pslist *list, int *nb);
char		**duplicate_cleaner(char **tab1, int nb);
int			duplicate_finder(t_pslist *list);
int			final_tab_len(char **tab);
void		list_free(t_pslist *head);
t_pslist	*node_malloc(t_pslist *node);
t_pslist	*node_fill(t_pslist *node, int data);
char		**papb_cleaner(char **tab);
int			pattern_match(char *s1, char *s2);
t_pslist	*ps_bubblesort(t_pslist **head_a, t_psflag *flag);
t_pslist	*ps_quicksort(/* char *instruc , */t_pslist **head_a, int deb, int fin, t_psflag *flag);
int			ps_output(int i);
void		push(/* char *instruc , */t_pslist **src, t_pslist **dest, t_psflag *flag);
void		push_swap(t_pslist *list, t_psflag *flag, char **argv);
void		rotate(/* char *instruc , */t_pslist **head, int nb, t_psflag *flag);
void		rrotate(/* char *instruc , */t_pslist **head, int nb, t_psflag *flag);
void		swap(/* char *instruc , */t_pslist *p1, t_pslist *p2, t_psflag *flag);

#endif
