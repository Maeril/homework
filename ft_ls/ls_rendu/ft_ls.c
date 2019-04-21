/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:40:21 by myener            #+#    #+#             */
/*   Updated: 2019/04/21 19:02:13 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// t_lsdata	*listfill(const char *name, t_lsdata *list, struct dirent *repo)
// {
// 	struct stat		buf;
// 	struct passwd	*pw;
// 	struct group	*gr;

// 	stat(name, &buf);
// 	pw = getpwuid(buf.st_uid);
// 	gr = getgrgid(buf.st_gid);

// 	list->filename = repo->d_name;
// 	list->ls_namelen = ft_strlen(repo->d_name);
// 	list->date_sec = time(&buf.st_mtime);
// 	return (list);
// }

int			ft_ls(const char *name, t_lsflag *lsflag)
{
	DIR				*dir;
	DIR				*isdir;
	struct dirent	*repo;
	int				i;
	char			*tmp;
	// t_lsdata		*list;
	// t_lsdata		*head;

	isdir = NULL;
	dir = opendir(name);
	i = 0;
	// list = NULL;
	if (readdir(dir))
	{
		// list = list_malloc(list);
		// repo = readdir(dir);
		// list = listinit(list);
		// list = listfill(name, list, repo);
		// head = list;
		while ((repo = readdir(dir)) != NULL)
		{
			if (lsflag->a)
			{
				if (i == 0)
					ft_printf(". ");
				if (ft_strcmp(repo->d_name, "..") == 0)
					ft_printf(".. ");
			}
			if (lsflag->l)
			{
				tmp = ft_strjoin(name, "/");
				tmp = ft_strjoin(tmp, repo->d_name);
				get_file_info(tmp);
			}
			if (!lsflag->l && ft_strcmp(repo->d_name, "..") != 0 //problematique car du coup le flag -l n'est pas compatible avec les autres :/
			&& ft_strcmp(repo->d_name, ".") != 0)
				ft_printf("%s \n", repo->d_name);
			if (lsflag->R)
			{
				tmp = ft_strjoin(name, "/");
				tmp = ft_strjoin(tmp, repo->d_name);
				isdir = opendir(tmp);
				if ((isdir != NULL) && (ft_strcmp(repo->d_name, "..") != 0))
					ft_ls(tmp, lsflag);
			}
			// list = list->next;
			// list = list_malloc(list);
			// list = listinit(list);
			// list = listfill(name, list, repo);
//			list = list->next;
			i++;
		}
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
