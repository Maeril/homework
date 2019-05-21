/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:42 by myener            #+#    #+#             */
/*   Updated: 2019/05/21 15:44:46 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		flag_manager(t_lsflag *flag, const char *name, t_lsdata *list)
{
	char	*tmp;
	int		dot;

	if (flag->t && !flag->r)
		list = sort_list_revdate(list);
	else if (flag->r && !flag->t)
		list = sort_list_revalpha(list);
	else if (flag->rt)
		list = sort_list_date(list);
	if (flag->l && flag->a)
	{
		tmp = ft_strjoin(name, "/");
		tmp = ft_free_join(tmp, list->filename);
		get_file_info(tmp);
		free(tmp);
	}
	else if (flag->l && !flag->a)
	{
		dot = starts_with_dot(list->filename);
		if (!dot)
		{
			tmp = ft_strjoin(name, "/");
			tmp = ft_free_join(tmp, list->filename);
			get_file_info(tmp);
			free(tmp);
		}
	}
}

int			is_flag(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' && str[1] != '-')
	{
		while (str[i])
		{
			if (str[i] == 'l' || str[i] == 'a' || str[i] == 'r'
				|| str[i] == 'R' || str[i] == 't')
				return (1);
			i++;
		}
	}
	else if (str[0] == '-' && str[1] == '-')
	{
		ft_putstr("ls: illegal option -- -\n");
		ft_putstr("usage: ./ft_ls [-alrRt] [file ...]\n");
	}
	return (0);
}

void		ls_parser(t_lsflag *flag, char *str)
{
	int		i;

	i = 1;
	while ((str[i] && str[i] != ' ') || str[i])
	{
		if (str[i] != 'R' && str[i] != 'a' && str[i] != 'l'
			&& str[i] != 'r' && str[i] != 't')
		{
			flag->c_intrus = str[i];
			flag->intrus = 1;
			break ;
		}
		if (str[i] == 'R')
			flag->big_r = 1;
		if (str[i] == 'a')
			flag->a = 1;
		if (str[i] == 'l')
			flag->l = 1;
		if (str[i] == 'r')
			flag->r = 1;
		if (str[i] == 't')
			flag->t = 1;
		if (flag->big_r || flag->a || flag->l || flag->r || flag->t)
			flag->flag = 1;
		if (flag->r && flag->t)
		{
			flag->r = 0;
			flag->t = 0;
			flag->rt = 1;
		}
		i++;
	}
	printf("str = %s, i = %d,  R = %d, r = %d, a = %d, l = %d, t = %d\n", str, i, flag->big_r, flag->r, flag->a, flag->l, flag->t);
}

int			starts_with_dot(char *filename)
{
	return (filename[0] == '.' ? 1 : 0);
}

void		inexistant_file(const char *name, t_lsflag *flag)
{
	struct stat		buf;

	lstat(name, &buf);
	if ((S_ISDIR(buf.st_mode)) && !flag->intrus)
		ft_printf("ls: %s: Permission denied\n", name);
	else if (flag->intrus || name[0] == '-')
	{
		ft_printf("ls: illegal option -- %c\n", flag->intrus ?
		flag->c_intrus : name[1]);
		ft_putstr("usage: ./ft_ls [-alrRt] [file ...]\n");
	}
	else
		ft_printf("ls: %s: No such file or directory\n", name);
}
