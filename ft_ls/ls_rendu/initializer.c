/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:02:03 by myener            #+#    #+#             */
/*   Updated: 2019/05/20 19:20:47 by myener           ###   ########.fr       */
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
	flag->notaflag = 0;
}

void		symlink_manager(t_lsdata *list, const char *name, struct stat buf)
{
	char	*str;
	char	*tmp;

	if (!(str = malloc(sizeof(char) * buf.st_size + 1)))
		return ;
	str[buf.st_size] = '\0';
	tmp = ft_free_join(ft_strjoin(name, "/"), list->filename);
	readlink(tmp, str, buf.st_size + 1);
	ft_printf("%s ", list->filename);
	if (S_ISLNK(buf.st_mode))
		ft_printf("\033[0m-> %s", str);
	ft_putchar('\n');
	free (str);
}

t_lsdata	*list_malloc(t_lsdata *data)
{
	if (!(data = malloc(sizeof(t_lsdata))))
		return (NULL);
	data->filename = NULL;
	data->date_sec = 0;
	data->next = NULL;
	return (data);
}

t_lsdata	*listfill(const char *name, t_lsdata *list,
					struct dirent *repo, t_lsdata *next)
{
	struct stat		buf;
	char			*tmp;

	if (next != NULL)
		tmp = ft_free_join(ft_strjoin(name, "/"), repo->d_name);
	list = list_malloc(list);
	lstat(tmp, &buf);
	list->filename = repo->d_name;
	list->date_sec = buf.st_mtime;
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
