/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:02:03 by myener            #+#    #+#             */
/*   Updated: 2019/04/17 13:43:36 by myener           ###   ########.fr       */
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

void	ls_struct_malloc(t_lsflag *lsflag)
{
	if (!(lsflag = malloc(sizeof(t_lsflag))))
		return ;
}

void	ls_free_malloc(t_lsflag *lsflag)
{
	if (lsflag)
		free(lsflag);
}