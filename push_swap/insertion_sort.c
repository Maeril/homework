/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:49:45 by myener            #+#    #+#             */
/*   Updated: 2019/11/25 15:32:54 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			insert_sort_init(t_pslist *curr, int *min, int *t, int *pos)
{
	if (curr->data < *min)
	{
		*min = curr->data;
		*t = *pos;
	}
	(*pos)++;
	return (1);
}

t_pslist	*insertion_sort(t_pslist **h_a, int sz, t_psflag *f)
{
	int			min;
	int			pos;
	int			t;
	t_pslist	*curr;
	t_pslist	*head_b;

	t = 0;
	head_b = NULL;
	while (sz > 2)
	{
		curr = (*h_a);
		min = (*h_a)->data;
		pos = 1;
		t = 1;
		while (curr)
			curr = insert_sort_init(curr, &min, &t, &pos) ? curr->next : curr;
		t <= (sz + 1) / 2 ? rot(h_a, t - 1, f) : rrot(h_a, ((sz + 1) - t), f);
		push(h_a, &head_b, f);
		sz--;
	}
	((*h_a)->data > (*h_a)->next->data) ? swap((*h_a), (*h_a)->next, f) : 0;
	while (head_b)
		push(&head_b, h_a, f);
	return ((*h_a));
}
