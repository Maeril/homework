/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:40:21 by myener            #+#    #+#             */
/*   Updated: 2019/04/24 16:33:34 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsdata	*listfill(const char *name, t_lsdata *list, struct dirent *repo)
{
	struct stat		buf;

	stat(name, &buf);
	list->filename = repo->d_name;
	list->ls_namelen = ft_strlen(repo->d_name);
	list->date_sec = buf.st_mtime;
	return (list);
}

static void	ls_printer(t_lsdata *list, t_lsflag *flag, const char *n, int i)
{
	char			*tmp;
	DIR				*isdir;

	while (list)
	{
		if (flag->a || flag->l || flag->t)
			flag_manager(flag, n, list, i);
		if (!flag->l && ft_strcmp(list->filename, "..") != 0
		&& ft_strcmp(list->filename, ".") != 0)
			ft_printf("%s ", list->filename);
		if (flag->R)
		{
			tmp = ft_strjoin(n, "/");
			tmp = ft_strjoin(tmp, list->filename);
			isdir = opendir(tmp);
			if ((isdir != NULL) && (ft_strcmp(list->filename, "..") != 0))
				ft_ls(tmp, flag);
		}
		list = list->next;
	}
}

int			ft_ls(const char *name, t_lsflag *lsflag)
{
	DIR				*dir;
	struct dirent	*repo;
	int				i;
	char			*tmp;
	t_lsdata		*list;
	t_lsdata		*prec;

	dir = opendir(name);
	i = 0;
	list = NULL;
	if (readdir(dir))
	{
		list = list_malloc(list);
		repo = readdir(dir);
		listinit(list);
		list = listfill(name, list, repo);
		list->next = NULL;
		prec = list;
		while ((repo = readdir(dir)) != NULL)
		{
			list = list_malloc(list);
			listinit(list);
			tmp = ft_strjoin(name, "/");
			tmp = ft_strjoin(tmp, repo->d_name);
			list = listfill(tmp, list, repo);
			list->next = prec;
			prec = list;
			i++;
		}
		ls_printer(prec, lsflag, name, i);
		ft_putchar('\n');
		return (1);
	}
	closedir(dir);
	return (0);
}

int		main(int argc, char **argv)
{
	t_lsflag	lsflag;
	const char	*name;
	const char	empty[] = ".";

	if (argc >= 1 || argc <= 3)
	{
		ls_struct_malloc(&lsflag);
		initializer(&lsflag);
		if (argc == 1)
			return (ft_ls(empty, &lsflag));
		if (argc == 2 && argv[1][0] != '-')
		{
			name = argv[1];
			return (ft_ls(name, &lsflag));
		}
		else if (argc == 2 && argv[1][0] == '-')
		{
			ls_parser(&lsflag, argv[1]);
			return (ft_ls(empty, &lsflag));
		}
		else if (argc == 3 && argv[1][0] == '-')
		{
			name = argv[2];
			ls_parser(&lsflag, argv[1]);
			return (ft_ls(name, &lsflag));
		}
		ls_struct_free(&lsflag);
	}
	return (0);
}
