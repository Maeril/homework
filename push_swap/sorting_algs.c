/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:11:10 by myener            #+#    #+#             */
/*   Updated: 2019/07/27 18:39:06 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pile_print(t_pslist *curr) // A SUPPRIMER AVANT RENDU
{
	while (curr && curr->next)
	{
		printf("%d, ", curr->data);
		curr = curr->next;
	}
	printf("%d.\n", curr->data);
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

// void	sort_int_tab(int *tab, unsigned int size)
// {
// 	int i = 0;
// 	int j;
// 	int tmp;

// 	if (size <= 1)
// 		return ;
// 	while(i < size)
// 	{
// 		j = 0;
// 		while (j < size - 1)
// 		{
// 			if (tab[j] > tab[j + 1])
// 			{
// 				tmp = tab[j];
// 				tab[j] = tab[j + 1];
// 				tab[j + 1] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int		median_calculator(t_pslist *head, int deb, int fin)
// {
// 	int			i;
// 	int			ret;
// 	int			*tab;
// 	t_pslist	*curr;

// 	curr = head;
// 	if (!(tab = malloc(sizeof(int) * (fin + 1))))
// 		return (0);
// 	i = 0;
// 	while (curr && i < fin)
// 	{
// 		tab[i] = curr->data;
// 		if (!curr->next)
// 			break ;
// 		curr = curr->next;
// 		i++;
// 	}
// 	sort_int_tab(tab, i);
// 	ret = tab[i / 2];
// 	free (tab);
// 	return (ret);
// }


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
	// if (deb == 0 && fin == 2)
	// {
	// 	pile_print(*head_a);
	// 	exit (0);
	// }
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
	if (same_data(*head_a, (fin - deb)))
	{
		rrotate(head_a, deb, flag);
		return ((*head_a));
	}
	nr = 0;
	np = 0;
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
