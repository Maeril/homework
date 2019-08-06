/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:05:48 by myener            #+#    #+#             */
/*   Updated: 2019/08/06 13:43:28 by myener           ###   ########.fr       */
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

void		list_free(t_pslist *head)
{
	t_pslist	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int			check_length(t_pslist *list)
{
	int			i;
	t_pslist	*curr;

	i = 1;
	curr = list;
	while (curr && curr->next) /* while the chained list exists, go through it */
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int			check_list(t_pslist *list) // check whether list is already sorted
{
	t_pslist *curr;

	curr = list; /* keep track of the head of the chained list */
	while (curr) /* while the chained list exists, go through it */
	{
		if (!curr->next)
			break ;
		if (curr->data > curr->next->data) /* if one data is greater than the next, */
			return (1); /* then it's unsorted and we can proceed to the next step */
		curr = curr->next;
	}
	// if (flag->ch)
	// 	return (ps_output(3)); /* if all is well and checker was called, output "OK" */
	return (0);

}
