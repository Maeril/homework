/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:42 by myener            #+#    #+#             */
/*   Updated: 2019/04/23 13:14:34 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_manager(t_lsflag *lsflag, struct dirent *repo, /*	t_lsdata *list,*/ int i)
{
	// DIR				*isdir;

	if (lsflag->a)
	{
		if (i == 0)
			ft_printf(". ");
		if (ft_strcmp(list->filename, "..") == 0)
			ft_printf(".. ");
	}
	if (lsflag->l)
	{
		tmp = ft_strjoin(name, "/");
		tmp = ft_strjoin(tmp, list->filename);
		get_file_info(tmp, list);
	}
}
