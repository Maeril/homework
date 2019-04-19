/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:42 by myener            #+#    #+#             */
/*   Updated: 2019/04/19 18:34:55 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	flag_manager(t_lsflag *lsflag,	t_lsdata *list, int i)
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
		get_file_info(list->filename);
}
