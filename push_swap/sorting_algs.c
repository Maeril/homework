/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:11:10 by myener            #+#    #+#             */
/*   Updated: 2019/07/29 16:19:27 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pile_print(t_pslist *curr) // A SUPPRIMER AVANT RENDU
{
	while (curr && curr->next)
	{
		printf("%d, ", curr->data);
		curr = curr->next;
	}
	printf("%d.\n", curr->data);
}

// t_pslist	**three_sort(t_pslist **head, t_psflag *flag)
// {
// 	int			biggest;
// 	int 		smallest;
// 	t_pslist	*curr;

// 	curr = (*head);
// 	while (curr)
// 	{
// 		if (!curr->next)
// 			break ;
// 		if (curr->data > biggest)
// 			biggest = curr->data;
// 		curr = curr->next;
// 	}
// 	curr = (*head);
// 	while (curr)
// 	{
// 		if (!curr->next)
// 			break ;
// 		if (curr->data < smallest)
// 			smallest = curr->data;
// 		curr = curr->next;
// 	}
// 	if ((*head)->data == biggest)
// 	{
// 		if ((*head)->next->data == smallest)
// 			rotate(head, 1, flag);
// 		else
// 		{
// 			rotate(head, 1, flag);
// 			swap((*head), (*head)->next, flag);
// 		}
// 	}
// 	else if ((*head)->data == smallest)
// 	{
// 		if ((*head)->next->data == biggest)
// 			swap((*head)->next, (*head)->next->next, flag);
// 		else
// 			return (head);
// 	}
// 	else // aka if it's mid
// 		(*head)->next->data == biggest ? rrotate(head, 1, flag) : swap((*head), (*head)->next, flag);
// 	return (head);
// }

int		same_data(t_pslist *curr, int fin)
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

t_pslist *ps_bubblesort(t_pslist **head_a, t_psflag *flag)
{
    int 		swapd;
	t_pslist	*curr;
    t_pslist	*lptr;

	lptr = NULL;
	curr = (*head_a);
	if (!curr)
		return (NULL);
    swapd = 0;
    while (curr->next != lptr)
    {
        if (curr->data > curr->next->data)
        {
            swap(curr, curr->next, flag);
            swapd = 1;
        }
        curr = curr->next;
    }
    lptr = curr;
    while (swapd)
	{
        swapd = 0;
		if (!curr->next)
			break ;
		while (curr->next != lptr)
        {
            if (curr->data > curr->next->data)
            {
                swap(curr, curr->next, flag);
                swapd = 1;
            }
            curr = curr->next;
        }
        lptr = curr;
    }
	return ((*head_a));
}

int		mean_calculator(t_pslist *head, int deb, int fin)
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

t_pslist *ps_quicksort(t_pslist **head_a, int deb, int fin, t_psflag *flag)
{
	int			i;
	int			nr;
	int			np;
	int			pivot;
	t_pslist	*head_b;

	head_b = NULL;
	i = deb;
	pivot = mean_calculator((*head_a), deb, fin);
	// printf("deb = %d, fin = %d, pivot = %d\n", deb, fin, pivot);
	if (deb == fin) // if only 1 node or list already sorted, finish now
		return (0);
	rotate(head_a, deb, flag);
	if ((deb + 1) == fin) // if only 2 nodes
	{
		if ((*head_a)->data > (*head_a)->next->data)
			swap((*head_a), (*head_a)->next, flag);
		rrotate(head_a, deb, flag);
		return ((*head_a));
	}
	// if ((deb + 2) == fin) // if only 3 nodes
	// 	return (*(three_sort(head_a, flag)));
	if (same_data(*head_a, (fin - deb)))
	{
		rrotate(head_a, deb, flag);
		return ((*head_a));
	}
	nr = 0;
	np = 0;
	// printf("coucou\n");
	if ((*head_a)->data <= pivot)
	{
		push(head_a, &head_b, flag);
		np++;
	}
	else if ((*head_a)->data > pivot)
	{
		rotate(head_a, 1, flag);
		nr++;
	}
	while ((head_a && (*head_a)->next) && (i < fin))
	{
		if ((*head_a)->data <= pivot)
		{
			push(head_a, &head_b, flag);
			np++;
		}
		else if ((*head_a)->data > pivot)
		{
			rotate(head_a, 1, flag);
			nr++;
		}
		i++;
	}
	rrotate(head_a, nr, flag);
	while (head_b)
		push(&head_b, head_a, flag);
	rrotate(head_a, deb, flag);
	ps_quicksort(head_a, deb, (deb + np) - 1, flag); // sort all small nums (which are in the beginning of the list)
	ps_quicksort(head_a, (deb + np), fin, flag); // sort all big nums (which are right ar)
	return ((*head_a));
}
