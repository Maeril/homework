/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:43:08 by myener            #+#    #+#             */
/*   Updated: 2019/04/26 18:12:33 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include "ls_libft/libft.h"
# include "ls_libft/ft_printf/ft_printf.h"

typedef struct			s_lsflag
{
	int					flag;
	int					big_r;
	int					a;
	int					l;
	int					r;
	int					t;
}						t_lsflag;

typedef struct			s_lsdata
{
	char				*filename;
	long long int		date_sec;
	struct s_lsdata		*next;
}						t_lsdata;

void					flag_manager(t_lsflag *flag, const char *name,
						t_lsdata *list);
int						ft_ls(const char *name, t_lsflag *lsflag);
int						get_file_info(const char *name);
void					initializer(t_lsflag *lsflag);
t_lsdata				*list_malloc(t_lsdata *lsdata);
void					list_free(t_lsdata *lsdata);
void					ls_parser(t_lsflag *lsflag, char *str);
void					ls_printer(const char *name, t_lsflag *flag, int i);
void					ls_struct_malloc(t_lsflag *lsflag);
void					ls_struct_free(t_lsflag *lsflag);
void					padding(struct stat buf);
void					recursive(const char *name, t_lsdata *list,
						t_lsflag *flag);
t_lsdata				*sort_list_revalpha(t_lsdata *head);
t_lsdata				*sort_list_alpha(t_lsdata *head);
t_lsdata				*sort_list_revdate(t_lsdata *head);
int						starts_with_dot(char *filename);
int						swap_list_data(t_lsdata *p1, t_lsdata *p2);

#endif
