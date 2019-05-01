/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:40:21 by myener            #+#    #+#             */
/*   Updated: 2019/05/01 16:50:51 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		listfill(const char *name, t_lsdata *list,
					struct dirent *repo, t_lsdata *next)
{
	struct stat		buf;

	stat(name, &buf);
	list->filename = repo->d_name;
	list->date_sec = buf.st_mtime;
	list->next = next;
}

void			ls_printer(t_lsdata *list, t_lsflag *flag, int i)
{
	int			dot;
	struct stat	buf;

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
	if (flag->l && !dot)
		ft_printf("%s \n", list->filename);
	else if (flag->l && (flag->a && dot))
		ft_printf("%s \n", list->filename);
	else if (!flag->l && !dot)
		ft_printf("%s ", list->filename);
	else if (!flag->l && (flag->a && dot))
		ft_printf("%s ", list->filename);
	ft_putstr("\033[0m");
}

int				ls_print_manager(t_lsdata *list, t_lsflag *flag,
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
		if (!flag->r && !flag->t)
			list = sort_list_alpha(list);
		if (flag->l || flag->r || flag->t || (flag->t && flag->a && flag->l))
			flag_manager(flag, name, list);
		ls_printer(list, flag, i);
		if (flag->big_r)
		{
			tmp = ft_free_join(ft_strjoin(name, "/"), list->filename);
			isdir = opendir(tmp);
			if ((isdir != NULL) && (ft_strcmp(list->filename, ".") != 0)
			&& (ft_strcmp(list->filename, "..") != 0))
				ft_ls(tmp, flag, (lvl + 1));
			free(tmp);
			if (isdir)
				closedir(isdir);
		}
		list = list->next;
		i++;
	}
	if (!flag->l && lvl == 0)
		ft_putchar('\n');
	list_free(head);
	return (1);
}

int				ft_ls(const char *name, t_lsflag *lsflag, int lvl)
{
	DIR				*dir;
	struct dirent	*repo;
	char			*tmp;
	t_lsdata		*node;
	t_lsdata		*head;
	int				ret;

	dir = opendir(name);
	node = NULL;
	if ((repo = readdir(dir)))
	{
		node = list_malloc(node);
		listfill(name, node, repo, NULL);
		head = node;
		while ((repo = readdir(dir)) != NULL)
		{
			node = list_malloc(node);
			tmp = ft_free_join(ft_strjoin(name, "/"), repo->d_name);
			listfill(tmp, node, repo, head);
			head = node;
			free(tmp);
		}
		ret = ls_print_manager(head, lsflag, name, lvl);
		if (dir)
			closedir(dir);
		return (ret);
	}
	if (dir && (repo = readdir(dir)) == NULL)
		closedir(dir);
	return (0);
}

int				main(int argc, char **argv)
{
	t_lsflag	lsflag;
	const char	*name;
	const char	empty[] = ".";

	if (argc >= 1 || argc <= 3)
	{
		initializer(&lsflag);
		if (argc == 1)
			return (ft_ls(empty, &lsflag, 0));
		else if (argc == 2 && argv[1][0] != '-')
		{
			name = argv[1];
			return (ft_ls(name, &lsflag, 0));
		}
		else if ((argc == 2 || argc == 3) && argv[1][0] == '-')
		{
			ls_parser(&lsflag, argv[1]);
			if (argc == 3)
				name = argv[2];
			return (ft_ls((argc == 2 ? empty : name), &lsflag, 0));
		}
	}
	return (0);
}
