/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:42 by myener            #+#    #+#             */
/*   Updated: 2019/04/21 14:59:53 by myener           ###   ########.fr       */
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
		if (ft_strcmp(repo->d_name, "..") == 0)
			ft_printf(".. ");
	}
	if (lsflag->l)
		get_file_info(repo->d_name);
}
