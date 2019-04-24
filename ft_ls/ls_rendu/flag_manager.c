/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:42 by myener            #+#    #+#             */
/*   Updated: 2019/04/24 16:22:18 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_manager(t_lsflag *flag, const char *name, t_lsdata *list, int i)
{
	char	*tmp;

	if (flag->a)
	{
		if (i == 0)
			ft_printf(". ");
		if (ft_strcmp(list->filename, "..") == 0 && !flag->l)
			ft_printf(".. ");
	}
	if (flag->l)
	{
		tmp = ft_strjoin(name, "/");
		tmp = ft_strjoin(tmp, list->filename);
		get_file_info(tmp);
	}
	// if (flag->t)
	// 	list = sort_list_revdate(list);
}
