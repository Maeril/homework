/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:40:21 by myener            #+#    #+#             */
/*   Updated: 2019/04/18 16:02:05 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls(const char *name, t_lsflag *lsflag)
{
	DIR				*dir;
	DIR				*isdir;
	struct dirent	*repo;
	int				i;

	dir = opendir(name);
	i = 0;
	if (readdir(dir))
	{
		while ((repo = readdir(dir)) != NULL)
		{
			if (lsflag->R)
				if (((isdir = opendir(repo->d_name)) != NULL)
				&& (ft_strcmp(repo->d_name, "..") != 0))
				{
					name = ft_strjoin(name, "/");
					name = ft_strjoin(name, repo->d_name);
					ft_ls(name, lsflag);
				}
			if (lsflag->flag)
				flag_manager(lsflag, repo, i);
			if (!lsflag->l && ft_strcmp(repo->d_name, "..") != 0
			&& ft_strcmp(repo->d_name, ".") != 0)
				ft_printf("%s ", repo->d_name);
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
	const char	empty[] = "./";

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
		ls_free_malloc(&lsflag);
	}
	return (0);
}
