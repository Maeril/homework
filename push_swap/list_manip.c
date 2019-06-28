/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:05:48 by myener            #+#    #+#             */
/*   Updated: 2019/06/25 16:58:39 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*list_malloc(t_pslist *list)
{
	if (!(list = malloc(sizeof(t_pslist))))
		return (NULL);
	list->data = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_pslist	*listfill(t_pslist *list, int data)
{
	list = list_malloc(list);
	list->data = data;
	list = list->next;
	return (list);
}

int			check_length(t_pslist *list)
{
	int			i;
	t_pslist	*curr;

	i = 0;
	curr = list;
	while (curr && curr->next) /* while the chained list exists, go through it */
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int			check_list(t_pslist *list, t_psflag *flag)
{
	t_pslist *curr;

	curr = list; /* keep track of the head of the chained list */
	while (curr && curr->next) /* while the chained list exists, go through it */
	{
		if (!(curr->data >= '0' && curr->data <= '9'))
			ps_output(1);
		if (curr->data > curr->next->data) /* if one data is greater than the next, */
			return (1); /* then we can proceed to the next step */
		curr = curr->next;
	}
	return (flag->ch ? ps_output(3) : 0); /* if all is well and checker was called, output "OK"
	-- otherwise terminate without outputting anything. */

}
