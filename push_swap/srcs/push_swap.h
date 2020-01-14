/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:53:33 by myener            #+#    #+#             */
/*   Updated: 2020/01/14 14:46:15 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct			s_psflag
{
	int		ch;
	int		np;
	int		nr;
	int		pivot;
	int		ps;
	int		t;
	int		visual;
	char	*instruc;
}						t_psflag;

typedef struct			s_pslist
{
	int				data;
	char			type;
	struct s_pslist	*next;
	struct s_pslist	*prev;

}						t_pslist;

char					**append_return(char **in, t_pslist *list);
int						bad_instructions(char **instruc);
void					checker(t_pslist *list, t_psflag *flag, char **argv);
int						check_length(t_pslist *list);
int						check_list(t_pslist *list);
int						cmp(char *s1, char *s2);
t_pslist				*convertto_list(char **av, t_pslist *list, int *nb,
										t_psflag *f);
int						duplicate_finder(t_pslist *list);
void					flag_init(t_psflag *flag);
char					**ft_spacesplit(char *str);
char					**get_instruct(char **inst, t_pslist *list);
int						incorrect_read(char **tab);
t_pslist				*insertion_sort(t_pslist **h_a, int sz, t_psflag *f);
void					instructions_displayer(int code, int nb);
void					list_free(t_pslist *head);
int						max_min_checker(char **argv);
t_pslist				*node_fill(t_pslist *node, int data);
void					papb_cleaner(char **tab, t_psflag *flag);
int						pattern_match(char *s1, char *s2);
int						pile_print_graph(t_pslist *head, t_psflag *flag,
											int nb);
void					ps_displayer(char **out);
t_pslist				*ps_quicksort(t_pslist **head_a, int deb,
						int fin, t_psflag *flag);
int						ps_output(int i);
int						push(t_pslist **src, t_pslist **dest,
						t_psflag *flag);
char					**push_swap(t_pslist *list, t_psflag *flag,
						char **argv);
int						rot(t_pslist **head, int nb, t_psflag *flag);
int						rrot(t_pslist **head, int nb, t_psflag *flag);
int						same_data(t_pslist *curr, int fin);
int						swap(t_pslist *p1, t_pslist *p2, t_psflag *flag);
void					tab_free(char **tab);
char					**trim_comments(char **in, int i);
char					**visual_flag_remover(char **tab);

#endif
