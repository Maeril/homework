/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:42 by myener            #+#    #+#             */
/*   Updated: 2019/04/18 16:00:22 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_manager(t_lsflag *lsflag, struct dirent *repo, int i)
{
	// DIR				*dir;
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
