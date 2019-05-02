/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:43:08 by myener            #+#    #+#             */
/*   Updated: 2019/05/02 16:11:36 by myener           ###   ########.fr       */
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
	int					ret;
}						t_lsflag;

typedef struct			s_lsdata
{
	char				*filename;
	long long int		date_sec;
	struct s_lsdata		*next;
}						t_lsdata;

void					flag_manager(t_lsflag *flag, const char *name,
						t_lsdata *list);
int						ft_ls(const char *name, t_lsflag *flag, int lvl);
int						get_file_info(const char *name);
void					initializer(t_lsflag *flag);
t_lsdata				*list_malloc(t_lsdata *data);
void					list_free(t_lsdata *data);
void					ls_parser(t_lsflag *flag, char *str);
void					ls_spacesaver(t_lsdata *node, const char *name,
						struct dirent *repo);
t_lsdata				*sort_list_revalpha(t_lsdata *head);
t_lsdata				*sort_list_alpha(t_lsdata *head);
t_lsdata				*sort_list_revdate(t_lsdata *head);
int						starts_with_dot(char *filename);

#endif
