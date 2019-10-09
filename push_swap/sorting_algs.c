/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:11:10 by myener            #+#    #+#             */
/*   Updated: 2019/10/08 23:37:27 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			mean_calculator(t_pslist *head, int deb, int fin)
{
	int			s;
	int			tot;
	t_pslist	*curr;

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

void		three_args_saver(t_pslist **h_a, t_psflag *f, int c)
{
	t_pslist	*head_b;

	head_b = NULL;
	if ((*h_a)->data <= ((*h_a)->next)->data && c <= (*h_a)->data)
	{
		rot(h_a, 1, f);
		swap(*h_a, (*h_a)->next, f);
		rrot(h_a, 1, f);
		swap(*h_a, (*h_a)->next, f);
	}
	else if ((*h_a)->data >= c && c >= ((*h_a)->next)->data)
	{
		swap(*h_a, (*h_a)->next, f);
		rot(h_a, 1, f);
		swap(*h_a, (*h_a)->next, f);
		rrot(h_a, 1, f);
	}
	else if ((*h_a)->data >= ((*h_a)->next)->data && ((*h_a)->next)->data >= c)
	{
		swap(*h_a, (*h_a)->next, f);
		push(h_a, &head_b, f);
		swap(*h_a, (*h_a)->next, f);
		push(&head_b, h_a, f);
		swap(*h_a, (*h_a)->next, f);
	}
}

void		three_args(t_pslist **h_a, t_psflag *f)
{
	int			c;
	t_pslist	*head_b;

	c = (((*h_a)->next)->next)->data;
	head_b = NULL;
	if ((*h_a)->data <= ((*h_a)->next)->data && ((*h_a)->next)->data <= c)
		return ;
	else if ((*h_a)->data <= c && c <= ((*h_a)->next)->data)
	{
		push(h_a, &head_b, f);
		swap(*h_a, (*h_a)->next, f);
		push(&head_b, h_a, f);
	}
	else if (((*h_a)->next)->data <= (*h_a)->data && (*h_a)->data <= c)
		swap(*h_a, (*h_a)->next, f);
	else if (((*h_a)->data <= ((*h_a)->next)->data && c <= (*h_a)->data)
	|| ((*h_a)->data >= c && c >= ((*h_a)->next)->data)
	|| ((*h_a)->data >= ((*h_a)->next)->data && ((*h_a)->next)->data >= c))
		three_args_saver(h_a, f, c);
}

void		ps_quicksort_saver(t_pslist **h_a, t_psflag *f, int deb, int fin)
{
	int			i;
	t_pslist	*head_b;

	f->nr = 0;
	f->np = 0;
	head_b = NULL;
	i = deb;
	while (i <= fin)
	{
		f->np += ((*h_a)->data <= f->pivot) ? push(h_a, &head_b, f) : 0;
		f->nr += ((*h_a)->data > f->pivot) ? rot(h_a, 1, f) : 0;
		i++;
	}
	(fin != (f->t - 1) || deb != 0) ? rrot(h_a, f->nr, f) : 0;
	while (head_b)
		push(&head_b, h_a, f);
	head_b ? free(head_b) : 0;
}

void		pile_print(t_pslist **h_a)
{
	t_pslist	*curr;

	curr = (*h_a);
	while (curr)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("\n");
}

t_pslist	*ps_quicksort(t_pslist **h_a, int deb, int fin, t_psflag *f)
{
	int			n;

	f->pivot = mean_calculator((*h_a), deb, fin);
	if (deb == fin)
		return (0);
	// printf("deb = %d, fin = %d, pivot = %d\n", deb, fin, f->pivot);
	// pile_print(h_a);
	deb < (f->t / 2) ? rot(h_a, deb, f) : rrot(h_a, f->t - deb, f);
	if ((deb + 1 == fin) || (f->t != 3 && deb + 2 == fin))
	{
		(deb + 1 == fin && (*h_a)->data > (*h_a)->next->data) ?
		swap((*h_a), (*h_a)->next, f) : 0;
		(f->t != 3 && (deb + 2 == fin)) ? three_args(h_a, f) : 0;
		deb < (f->t / 2) ? rrot(h_a, deb, f) : rot(h_a, f->t - deb, f);
		return ((*h_a));
	}
	if (same_data(*h_a, (fin - deb)))
		deb < (f->t / 2) ? rrot(h_a, deb, f) : rot(h_a, f->t - deb, f);
	if (same_data(*h_a, (fin - deb)))
		return ((*h_a));
	ps_quicksort_saver(h_a, f, deb, fin);
	deb < (f->t / 2) ? rrot(h_a, deb, f) : rot(h_a, f->t - deb, f);
	n = f->np;
	ps_quicksort(h_a, deb, (deb + n) - 1, f);
	ps_quicksort(h_a, (deb + n), fin, f);
	return ((*h_a));
}
