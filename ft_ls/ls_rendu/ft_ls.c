/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:40:21 by myener            #+#    #+#             */
/*   Updated: 2019/05/02 16:11:55 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lsdata	*listfill(const char *name, t_lsdata *list,
					struct dirent *repo, t_lsdata *next)
{
	struct stat		buf;
	char			*tmp;

	if (next != NULL)
		tmp = ft_free_join(ft_strjoin(name, "/"), repo->d_name);
	list = list_malloc(list);
	stat(name, &buf);
	list->filename = repo->d_name;
	list->date_sec = buf.st_mtime;
	list->next = next;
	if (next != NULL)
		free(tmp);
	return (list);
}

static void		ls_printer(t_lsdata *list, t_lsflag *flag, int i, const char *n)
{
	int			dot;
	struct stat	buf;

	if (!flag->r && !flag->t)
		list = sort_list_alpha(list);
	if (flag->l || flag->r || flag->t || (flag->t && flag->a && flag->l))
		flag_manager(flag, n, list);
	stat(list->filename, &buf);
	dot = starts_with_dot((char *)list->filename);
	if (i == 0 && flag->a && !flag->l)
		ft_printf("\033[1;36m. \033[0m");
	if (S_ISDIR(buf.st_mode))
		ft_putstr("\033[1;36m");
	else if (buf.st_mode & S_IXUSR)
		ft_putstr("\033[1;31m");
	else if (S_ISLNK(buf.st_mode))
		ft_putstr("\033[1;35m");
	else if (S_ISBLK(buf.st_mode) || S_ISCHR(buf.st_mode))
		ft_putstr("\033[1;33m");
	if ((flag->l && !dot) || (flag->l && (flag->a && dot)))
		ft_printf("%s \n", list->filename);
	else if ((!flag->l && !dot) || (!flag->l && (flag->a && dot)))
		ft_printf("%s ", list->filename);
	ft_putstr("\033[0m");
}

static int		ls_print_manager(t_lsdata *list, t_lsflag *flag,
						const char *name, int lvl)
{
	int				i;
	char			*tmp;
	DIR				*isdir;
	t_lsdata		*head;

	i = 0;
	head = list;
	while (list)
	{
		ls_printer(list, flag, i, name);
		if (flag->big_r)
		{
			tmp = ft_free_join(ft_strjoin(name, "/"), list->filename);
			if ((isdir = opendir(tmp)) && (ft_strcmp(list->filename, ".") != 0)
			&& (ft_strcmp(list->filename, "..") != 0))
				ft_ls(tmp, flag, (lvl + 1));
			free(tmp);
			(isdir) ? closedir(isdir) : 0;
		}
		list = list->next;
		i++;
	}
	(!flag->l && lvl == 0) ? ft_putchar('\n') : 0;
	list_free(head);
	return (1);
}

int				ft_ls(const char *name, t_lsflag *flag, int lvl)
{
	DIR				*dir;
	struct dirent	*repo;
	t_lsdata		*node;
	t_lsdata		*head;

	dir = opendir(name);
	node = NULL;
	if ((repo = readdir(dir)))
	{
		node = listfill(name, node, repo, NULL);
		head = node;
		while ((repo = readdir(dir)) != NULL)
		{
			node = listfill(name, node, repo, head);
			head = node;
		}
		flag->ret = ls_print_manager(head, flag, name, lvl);
		(dir) ? closedir(dir) : 0;
		return (flag->ret);
	}
	(dir && (repo = readdir(dir)) == NULL) ? closedir(dir) : 0;
	return (0);
}

int				main(int argc, char **argv)
{
	t_lsflag	flag;
	const char	*name;
	const char	empty[] = ".";

	if (argc >= 1 || argc <= 3)
	{
		initializer(&flag);
		if (argc == 1)
			return (ft_ls(empty, &flag, 0));
		else if (argc == 2 && argv[1][0] != '-')
		{
			name = argv[1];
			return (ft_ls(name, &flag, 0));
		}
		else if ((argc == 2 || argc == 3) && argv[1][0] == '-')
		{
			ls_parser(&flag, argv[1]);
			if (argc == 3)
				name = argv[2];
			return (ft_ls((argc == 2 ? empty : name), &flag, 0));
		}
	}
	return (0);
}
