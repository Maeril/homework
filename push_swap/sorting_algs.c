/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:11:10 by myener            #+#    #+#             */
/*   Updated: 2019/08/19 12:27:02 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			same_data(t_pslist *curr, int fin)
{
	int	i;

	i = 0;
	while (curr && i < fin)
	{
		if (!curr->next)
			break ;
		if (curr->data != curr->next->data)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

t_pslist	*ps_bubblesort(t_pslist **h_a, t_psflag *f)
{
	int			swapd;
	t_pslist	*c;
	t_pslist	*lptr;

	(!(c = (*h_a))) ? exit(0) : 0;
	swapd = 0;
	while (c->next != NULL)
	{
		swapd = (c->data > c->next->data) ? swap(c, c->next, f) : swapd;
		c = c->next;
	}
	lptr = c;
	while (swapd)
	{
		swapd = 0;
		if (!c->next)
			break ;
		while (c->next != lptr)
		{
			swapd = (c->data > c->next->data) ? swap(c, c->next, f) : swapd;
			c = c->next;
		}
		lptr = c;
	}
	return ((*h_a));
}

int			mean_calculator(t_pslist *head, int deb, int fin)
{
	int			s;
	t_pslist	*curr;
	int			tot;

	curr = head;
	s = 0;
	while (s < deb)
	{
		curr = curr->next;
		s++;
	}
	tot = 0;
	while (s <= fin)
	{
		tot += curr->data;
		curr = curr->next;
		s++;
	}
	return (tot / (fin - deb + 1));
}

t_pslist	*ps_quicksort(t_pslist **h_a, int deb, int fin, t_psflag *f)
{
	int			i;
	int			nr;
	int			np;
	t_pslist	*head_b;

	head_b = NULL;
	f->pivot = mean_calculator((*h_a), deb, fin);
	if (deb == fin)
		return (0);
	rot(h_a, deb, f);
	if ((deb + 1) == fin)
	{
		(*h_a)->data > (*h_a)->next->data ? swap((*h_a), (*h_a)->next, f) : 0;
		rrot(h_a, deb, f);
		return ((*h_a));
	}
	(same_data(*h_a, (fin - deb))) ? rrot(h_a, deb, f) : 0;
	if (same_data(*h_a, (fin - deb)))
		return ((*h_a));
	nr = 0;
	np = 0;
	np += ((*h_a)->data <= f->pivot) ? push(h_a, &head_b, f) : 0;
	nr += ((*h_a)->data > f->pivot) ? rot(h_a, 1, f) : 0;
	i = deb;
	while ((h_a && (*h_a)->next) && (i < fin))
	{
		np += ((*h_a)->data <= f->pivot) ? push(h_a, &head_b, f) : 0;
		nr += ((*h_a)->data > f->pivot) ? rot(h_a, 1, f) : 0;
		i++;
	}
	rrot(h_a, nr, f);
	while (head_b)
		push(&head_b, h_a, f);
	free(head_b);
	rrot(h_a, deb, f);
	ps_quicksort(h_a, deb, (deb + np) - 1, f);
	ps_quicksort(h_a, (deb + np), fin, f);
	return ((*h_a));
}
