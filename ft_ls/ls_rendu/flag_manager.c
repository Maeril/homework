/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:42 by myener            #+#    #+#             */
/*   Updated: 2019/04/28 14:51:47 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		flag_manager(t_lsflag *flag, const char *name, t_lsdata *list)
{
	char	*tmp;
	int		dot;

	if (flag->t)
		list = sort_list_revdate(list);
	else if (flag->r && !flag->t)
		list = sort_list_revalpha(list);
	if (flag->l && flag->a)
	{
		tmp = ft_strjoin(name, "/");
		tmp = ft_strjoin(tmp, list->filename);
		get_file_info(tmp);
	}
	else if (flag->l && !flag->a)
	{
		dot = starts_with_dot(list->filename);
		if (!dot)
		{
			tmp = ft_free_join(ft_strjoin(name, "/"), list->filename);
			get_file_info(tmp);
		}
	}
}

int			starts_with_dot(char *filename)
{
	return (filename[0] == '.' ? 1 : 0);
}
