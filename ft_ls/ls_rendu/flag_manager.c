/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:42 by myener            #+#    #+#             */
/*   Updated: 2019/04/17 13:47:14 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_manager(t_lsflag *lsflag, struct dirent *repo)
{
	// DIR				*dir;
	if (lsflag->a)
	{
		if (ft_strcmp(repo->d_name, ".") == 0)
			ft_printf(". ");
		if (ft_strcmp(repo->d_name, "..") == 0)
			ft_printf(".. ");
	}
}
