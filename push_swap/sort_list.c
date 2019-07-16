/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:11:10 by myener            #+#    #+#             */
/*   Updated: 2019/07/16 17:56:27 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int ps_cleaner(char *src, const char *rem)
// {
// 	char *cur;
// 	int r = 0;
// 	while ((cur = ft_strstr(src, rem)))
// 	{
// 		ft_strcpy(cur, (cur + ft_strlen(rem)));
// 		r++;
// 	}
// 	return (r);
// }

// void replace(char *c)
// {
// 	while (*c)
// 	{
// 		if (*c == 't')
// 			*c = 'r';
// 		c++;
// 	}
// }

int		mean_calculator(t_pslist *head, int deb, int fin)
{
	int			s; // size
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
	while(s <= fin)
	{
		tot += curr->data;
		curr = curr->next;
		s++;
	}
	return (tot / (fin - deb + 1));
}

t_pslist *ps_quicksort(/* char *instruc , */t_pslist **head_a, int deb, int fin)
{
	int			i;
	int			nr;
	int			np;
	int			pivot;
	t_pslist	*head_b;

	head_b = NULL;
	i = deb;
	pivot = mean_calculator((*head_a), deb, fin);
	// if (check_list(head_a) == 1) // if ALREADY SORTED, finish now
	// 	return ((*head_a));
	if (deb == fin) // if only 1 node, finish now
		return (0);
	rotate(/* instruc, */head_a, deb);
	if ((deb + 1) == fin) // if only 2 nodes
	{
		if ((*head_a)->data > (*head_a)->next->data)
			swap(/* instruc, */(*head_a), (*head_a)->next);
		rrotate(/* instruc, */head_a, deb); // pseudo code
		return ((*head_a));
	}
	nr = 0;
	np = 0;
	if ((*head_a)->data <= pivot)
	{
		printf ("pb\n");
		push(/* instruc, */head_a, &head_b);
		np++;
	}
	else if ((*head_a)->data > pivot)
	{
		printf ("ra\n");
		rotate(/* instruc, */head_a, 1);
		nr++;
	}
	while ((head_a && (*head_a)->next) && (i < fin)) // "fin - 1" car un des nodes a deja ete traite juste avant
	{
		if ((*head_a)->data <= pivot)
		{
			printf ("pb\n");
			push(/* instruc, */head_a, &head_b);
			np++;
		}
		else if ((*head_a)->data > pivot)
		{
			printf ("ra\n");
			rotate(/* instruc, */head_a, 1);
			nr++;
		}
		i++;
	}
	rrotate(/* instruc, */head_a, nr);
	while (head_b)
	{
		printf ("pa\n");
		push(/* instruc, */&head_b, head_a);
	}
	rrotate(/* instruc, */head_a, deb);
	ps_quicksort(/* instruc, */head_a, deb, (deb + np) - 1); // sort all small nums (which are in the beginning of the list)
	ps_quicksort(/* instruc, */head_a, (deb + np), fin); // sort all big nums (which are right ar)
	return ((*head_a));
}
