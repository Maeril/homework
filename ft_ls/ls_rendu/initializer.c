/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:02:03 by myener            #+#    #+#             */
/*   Updated: 2019/04/21 20:55:24 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	initializer(t_lsflag *lsflag)
{
	lsflag->flag = 0;
	lsflag->R = 0;
	lsflag->a = 0;
	lsflag->l = 0;
	lsflag->r = 0;
	lsflag->t = 0;
}

void	listinit(t_lsdata *lsdata)
{
	lsdata->filename = NULL;
	lsdata->username = NULL;
	lsdata->groupname = NULL;
	// lsdata->hardlinks = 0;
	lsdata->ls_namelen = 0;
	lsdata->next = NULL;
}

void	ls_struct_malloc(t_lsflag *lsflag)
{
	if (!(lsflag = malloc(sizeof(t_lsflag))))
		return ;
}

t_lsdata	*list_malloc(t_lsdata *lsdata)
{
	if (!(lsdata = malloc(sizeof(t_lsdata))))
		return (NULL);
	return (lsdata);
}

void	list_free(t_lsdata *lsdata)
{
	if (!(lsdata = malloc(sizeof(t_lsdata))))
		return ;
}

void	ls_struct_free(t_lsflag *lsflag)
{
	if (lsflag)
		free(lsflag);
}