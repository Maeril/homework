/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:11:10 by myener            #+#    #+#             */
/*   Updated: 2020/01/08 20:02:27 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mean_calculator(t_pslist *head, int deb, int fin)
{
	int			s;
	int			tot;
	t_pslist	*curr;

	curr = head;
	s = -1;
	while (++s < deb)
		curr = curr->next;
	tot = 0;
	while (s++ <= fin && (tot += curr->data))
		curr = curr->next;
	return (tot / (fin - deb + 1));
}

static void	three_args_saver(t_pslist **h_a, t_psflag *f, int c)
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

static void	three_args(t_pslist **h_a, t_psflag *f)
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

static void	ps_quicksort_saver(t_pslist **h_a, t_psflag *f, int deb, int fin)
{
	int			i;
	t_pslist	*head_b;

	f->nr = 0;
	f->np = 0;
	head_b = NULL;
	i = deb - 1;
	while (++i <= fin)
		if ((*h_a)->data <= f->pivot)
			f->np += push(h_a, &head_b, f);
		else
			f->nr += rot(h_a, 1, f);
	(fin != (f->t - 1) || deb != 0) ? rrot(h_a, f->nr, f) : 0;
	while (head_b)
		push(&head_b, h_a, f);
	head_b ? free(head_b) : 0;
}

t_pslist	*ps_quicksort(t_pslist **h_a, int deb, int fin, t_psflag *f)
{
	int			n;

	f->pivot = mean_calculator((*h_a), deb, fin);
	if (deb == fin)
		return (0);
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
