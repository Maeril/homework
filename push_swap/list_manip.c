/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:05:48 by myener            #+#    #+#             */
/*   Updated: 2019/07/16 17:49:46 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*node_malloc(t_pslist *node)
{
	if (!(node = malloc(sizeof(t_pslist))))
		return (NULL);
	node->data = 0;
	node->type = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_pslist	*node_fill(t_pslist *node, int data)
{
	node = node_malloc(node);
	node->data = data;
	node->type = 'a';
	return (node);
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

int			check_list(t_pslist *list, t_psflag *flag) // check whether list is already sorted
{
	t_pslist *curr;

	curr = list; /* keep track of the head of the chained list */
	while (curr && curr->next) /* while the chained list exists, go through it */
	{
		if (!(curr->data >= '0' && curr->data <= '9'))
			ps_output(1);
		if (curr->data > curr->next->data) /* if one data is greater than the next, */
			return (1); /* then it's unsorted and we can proceed to the next step */
		curr = curr->next;
	}
	return (flag->ch ? ps_output(3) : 0); /* if all is well and checker was called, output "OK"
	-- otherwise terminate without outputting anything (since it means it's already sorted). */

}
