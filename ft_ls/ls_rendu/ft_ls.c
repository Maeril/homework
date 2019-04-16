/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:40:21 by myener            #+#    #+#             */
/*   Updated: 2019/04/16 19:33:11 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls(const char *name, t_lsflag *lsflag)
{
	DIR				*dir;
	struct dirent	*repo;

	lsflag = NULL;
	dir = opendir(name);
	if (readdir(dir))
	{
		while ((repo = readdir(dir)) != NULL)
		{
			// if (lsflag->flag)
			// 	flag_manager(lsflag, repo);
			// else if ((!lsflag->flag)) // ca segfault a cause de ces 3 lignes
				ft_printf("%s ", repo->d_name);
		}
		ft_putchar('\n');
		return (1);
	}
	closedir(dir);
	return (0);
}

int		main(int argc, char **argv)
{
	t_lsflag	*lsflag;
	const char	*name;
	const char	empty[] = "./";

	lsflag = NULL;
	if (argc >= 1 || argc <= 3)
	{
		ls_struct_malloc(lsflag);
		// initializer(lsflag); // ca segfault aussi ici
		if (argc == 1)
		{
			return (ft_ls(empty, lsflag));
		}
		else if (argc == 2 && argv[1][0] != '-')
		{
			name = argv[1];
			return (ft_ls(name, lsflag));
		}
		else if (argc == 2 && argv[1][0] == '-')
		{
			ls_parser(lsflag, argv[1]);
			return (ft_ls(empty, lsflag));
		}
		else if (argc == 3 && argv[1][0] == '-')
		{
			name = argv[2];
			ls_parser(lsflag, argv[1]);
			return (ft_ls(name, lsflag));
		}
		ls_free_malloc(lsflag);
	}
	return (0);
}
