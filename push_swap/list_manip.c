/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:05:48 by myener            #+#    #+#             */
/*   Updated: 2019/06/12 17:47:45 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*list_malloc(t_pslist *list)
{
	if (!(list = malloc(sizeof(t_pslist))))
		return (NULL);
	list->data = 0;
	list->next = NULL;
	return (list);
}

t_pslist	*listfill(t_pslist *list, int data)
{
	list = list_malloc(list);
	list->data = data;
	list = list->next;
	return (list);
}
