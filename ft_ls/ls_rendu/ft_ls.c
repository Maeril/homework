/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:40:21 by myener            #+#    #+#             */
/*   Updated: 2019/04/25 17:26:53 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		listfill(const char *name, t_lsdata *list, struct dirent *repo)
{
	struct stat		buf;

	stat(name, &buf);
	list->filename = repo->d_name;
	list->date_sec = buf.st_mtime;
}

static void	ls_printer(t_lsdata *list, t_lsflag *flag, const char *name)
{
	int		i;
	int		dot;

	i = 0;
	dot = 0;
	while (list)
	{
		if (!flag->r && !flag->t)
			list = sort_list_alpha(list);
		if (flag->l || flag->r || flag->t || (flag->t && flag->a && flag->l))
			flag_manager(flag, name, list);
		dot = starts_with_dot(list->filename);
		if (!flag->l && !dot)
			ft_printf("%s ", list->filename);
		else if (!flag->l && flag->a && dot == 1)
			ft_printf("%s ", list->filename);
		if (flag->big_r)
			recursive(name, list, flag);
		list = list->next;
		i++;
	}
}

int			ft_ls(const char *name, t_lsflag *lsflag)
{
	DIR				*dir;
	struct dirent	*repo;
	char			*tmp;
	t_lsdata		*node;
	t_lsdata		*head;

	dir = opendir(name);
	node = NULL;
	if (readdir(dir))
	{
		node = list_malloc(node);
		repo = readdir(dir);
		listfill(name, node, repo);
		node->next = NULL;
		head = node;
		while ((repo = readdir(dir)) != NULL)
		{
			node = list_malloc(node);
			tmp = ft_free_join(ft_strjoin(name, "/"), repo->d_name);
			listfill(tmp, node, repo);
			node->next = head;
			head = node;
		}
		ls_printer(head, lsflag, name);
		ft_putchar('\n');
		return (1);
	}
	closedir(dir);
	return (0);
}

int			main(int argc, char **argv)
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
		else if (argc == 2 && argv[1][0] != '-')
		{
			name = argv[1];
			return (ft_ls(name, &lsflag));
		}
		else if ((argc == 2 || argc == 3) && argv[1][0] == '-')
		{
			ls_parser(&lsflag, argv[1]);
			if (argc == 3)
				name = argv[2];
			return (ft_ls((argc == 2 ? empty : name), &lsflag));
		}
		ls_struct_free(&lsflag);
	}
	return (0);
}
