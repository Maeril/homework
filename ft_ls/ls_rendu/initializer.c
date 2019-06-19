/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:02:03 by myener            #+#    #+#             */
/*   Updated: 2019/06/18 18:17:06 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		initializer(t_lsflag *flag)
{
	flag->flag = 0;
	flag->big_r = 0;
	flag->a = 0;
	flag->l = 0;
	flag->r = 0;
	flag->t = 0;
	flag->ret = 0;
	flag->rt = 0;
	flag->blocks_nb = 0;
	flag->notaflag = 0;
	flag->intrus = 0;
}

t_lsdata	*list_malloc(t_lsdata *data)
{
	if (!(data = malloc(sizeof(t_lsdata))))
		return (NULL);
	data->filename = NULL;
	data->blocks = 0;
	data->date_sec = 0;
	data->next = NULL;
	return (data);
}

char		*ls_printer_helper(struct stat *buf, t_lsflag *flag,
								t_lsdata *list, char *tmp)
{
	int		dot;
	char	*str;

	dot = (list->filename[0] == '.') ? 1 : 0;
	if ((flag->l && !dot) || (flag->l && (flag->a && dot)))
	{
		if (!(ft_strcmp(list->filename, "")))
			ft_putstr(". ");
		ft_printf("%s ", list->filename);
		if (S_ISLNK(buf->st_mode))
		{
			str = ft_strnew(buf->st_size);
			readlink(tmp, str, buf->st_size);
			str[buf->st_size] = '\0';
			ft_printf("\033[0m-> %s", str);
			free(str);
		}
		ft_putchar('\n');
	}
	else if ((!flag->l && !dot) || (!flag->l && (flag->a && dot)))
	{
		ft_printf("%s ", list->filename);
		ft_putstr("\033[0m");
	}
	return (tmp);
}

t_lsdata	*listfill(const char *name, t_lsdata *list,
					struct dirent *repo, t_lsdata *next)
{
	struct stat		buf;
	char			*tmp;

	if (next != NULL)
		tmp = ft_free_join(ft_strjoin(name, "/"), repo->d_name);
	else
		tmp = NULL;
	list = list_malloc(list);
	if (tmp)
	{
		lstat(tmp, &buf);
		list->date_sec = buf.st_mtime;
		if (buf.st_blocks)
			list->blocks = buf.st_blocks;
		list->size = buf.st_size;
	}
	else
	{
		list->date_sec = 0;
		list->blocks = 0;
		list->size = 0;
	}
	list->filename = repo->d_name;
	list->next = next;
	if (next != NULL)
		free(tmp);
	return (list);
}

void		list_free(t_lsdata *head)
{
	t_lsdata	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
