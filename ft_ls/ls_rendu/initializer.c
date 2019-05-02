/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:02:03 by myener            #+#    #+#             */
/*   Updated: 2019/05/02 16:08:20 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		initializer(t_lsflag *flag)
{
	flag->flag = 0;
	flag->big_r = 0;
	flag->a = 0;
	flag->l = 0;
	flag->r = 0;
	flag->t = 0;
	flag->ret = 0;
}

t_lsdata	*list_malloc(t_lsdata *data)
{
	if (!(data = malloc(sizeof(t_lsdata))))
		return (NULL);
	data->filename = NULL;
	data->date_sec = 0;
	data->next = NULL;
	return (data);
}

void		list_free(t_lsdata *head)
{
	t_lsdata	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
