/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:11:10 by myener            #+#    #+#             */
/*   Updated: 2019/08/19 14:16:34 by myener           ###   ########.fr       */
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

void		ps_quicksort_saver(t_pslist **h_a, t_psflag *f, int deb, int fin)
{
	int			i;
	t_pslist	*head_b;

	i = 0;
	f->nr = 0;
	f->np = 0;
	head_b = NULL;
	f->np += ((*h_a)->data <= f->pivot) ? push(h_a, &head_b, f) : 0;
	f->nr += ((*h_a)->data > f->pivot) ? rot(h_a, 1, f) : 0;
	i = deb;
	while ((h_a && (*h_a)->next) && (i < fin))
	{
		f->np += ((*h_a)->data <= f->pivot) ? push(h_a, &head_b, f) : 0;
		f->nr += ((*h_a)->data > f->pivot) ? rot(h_a, 1, f) : 0;
		i++;
	}
	rrot(h_a, f->nr, f);
	while (head_b)
		push(&head_b, h_a, f);
	head_b ? free(head_b) : 0;
}

t_pslist	*ps_quicksort(t_pslist **h_a, int deb, int fin, t_psflag *f)
{
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
	ps_quicksort_saver(h_a, f, deb, fin);
	rrot(h_a, deb, f);
	ps_quicksort(h_a, deb, (deb + f->np) - 1, f);
	ps_quicksort(h_a, (deb + f->np), fin, f);
	return ((*h_a));
}
