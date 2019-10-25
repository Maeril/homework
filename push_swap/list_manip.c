/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:05:48 by myener            #+#    #+#             */
/*   Updated: 2019/10/25 18:00:44 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pslist	*node_malloc(t_pslist *node)
{
	if (!(node = malloc(sizeof(t_pslist))))
		return (NULL);
	nbmalloc++;
	node->data = 0;
	node->type = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_pslist		*node_fill(t_pslist *node, int data)
{
	node = node_malloc(node);
	node->data = data;
	node->type = 'a';
	return (node);
}

void			list_free(t_pslist *head)
{
	t_pslist	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
		nbfree++;
	}
}

int				check_length(t_pslist *list)
{
	int			i;
	t_pslist	*curr;

	i = 1;
	curr = list;
	while (curr && curr->next)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int				check_list(t_pslist *list)
{
	t_pslist *curr;

	curr = list;
	while (curr)
	{
		if (!curr->next)
			break ;
		if (curr->data > curr->next->data)
			return (1);
		curr = curr->next;
	}
	return (0);
}
