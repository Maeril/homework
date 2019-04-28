/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:02:03 by myener            #+#    #+#             */
/*   Updated: 2019/04/28 14:37:13 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		initializer(t_lsflag *lsflag)
{
	lsflag->flag = 0;
	lsflag->big_r = 0;
	lsflag->a = 0;
	lsflag->l = 0;
	lsflag->r = 0;
	lsflag->t = 0;
}

void		ls_struct_malloc(t_lsflag *lsflag)
{
	if (!(lsflag = malloc(sizeof(t_lsflag))))
		return ;
}

t_lsdata	*list_malloc(t_lsdata *lsdata)
{
	if (!(lsdata = malloc(sizeof(t_lsdata))))
		return (NULL);
	lsdata->filename = NULL;
	lsdata->date_sec = 0;
	lsdata->next = NULL;
	return (lsdata);
}

void		list_free(t_lsdata *lsdata)
{
	if (!(lsdata = malloc(sizeof(t_lsdata))))
		return ;
}

void		ls_struct_free(t_lsflag *lsflag)
{
	if (lsflag)
		free(lsflag);
}
