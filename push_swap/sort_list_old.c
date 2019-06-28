/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:15:07 by myener            #+#    #+#             */
/*   Updated: 2019/06/25 23:03:39 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_node(t_pslist** head_ref, int new_data) /* Test - insert node at beginning */
{
	t_pslist* new_node;

	if (!(new_node = malloc(sizeof(t_pslist))))
		return ;
	new_node->data = new_data; /* put in the data */
	new_node->next = (*head_ref); /* link the old list off the new node */
	(*head_ref) = new_node; /* move the head to point to the new node */
}

t_pslist *get_tail(t_pslist *curr)
{
	while (curr != NULL && curr->next != NULL)
		curr = curr->next;
	return (curr);
}

t_pslist *partition(t_pslist *head, t_pslist *end,
					   t_pslist **new_head, t_pslist **new_end) // Partitions the list taking the last element as the pivot
{
	t_pslist *pivot;
	t_pslist *prev;
	t_pslist *curr;
	t_pslist *tail;

	pivot = end; // Head and end of the list might change: it's updated in new_head and new_end
	prev = NULL;
	curr = head;
	tail = pivot;
	while (curr != pivot)
	{
		if (curr->data < pivot->data) // First node that has a value less than the pivot - becomes the new head
		{
			if ((*new_head) == NULL)
				(*new_head) = curr;
			prev = curr;
			curr = curr->next;
		}
		else // If current node is greater than pivot
		{
			if (prev) // Move current node to next of tail, and change tail
				prev->next = curr->next;
			t_pslist *tmp = curr->next;
			curr->next = NULL;
			tail->next = curr;
			tail = curr;
			curr = tmp;
		}
	}
	if ((*new_head) == NULL) // If the pivot data = smallest in the currrent list, pivot becomes the head
		(*new_head) = pivot;
	(*new_end) = tail; // Update new_end to the currrent last node
	return (pivot);
}

t_pslist *ps_quicksort_rec(t_pslist *head, t_pslist *end) // Here the sorting happens exclusive of the end node
{
	t_pslist *pivot;
	t_pslist *new_head;
	t_pslist *new_end;

	new_head = new_end = NULL;
	if (!head || head == end) // base condition
		return (head);
	pivot = partition(head, end, &new_head, &new_end); // Partition list, new_head and new_end will be updated by partition function
	// If pivot is the smallest element, no need to recurse for the left part.
	if (new_head != pivot)
	{
		t_pslist *tmp = new_head; // Set the node before the pivot node as NULL
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		new_head = ps_quicksort_rec(new_head, tmp); // Recursive for the list before pivot
		tmp = get_tail(new_head); // Change next of last node of the left half to pivot
		tmp->next =  pivot;
	}
	pivot->next = ps_quicksort_rec(pivot->next, new_end); // Recurse for the list after the pivot element
	return (new_head);
}

void ps_quicksort(t_pslist **head_ref) // Wrapper over ps_quicksort_rec()
{
	(*head_ref) = ps_quicksort_rec(*head_ref, get_tail(*head_ref));
	return ;
}

int main()
{
	t_pslist *list = NULL;
	t_pslist *curr = NULL;

	add_node(&list, 5);
	add_node(&list, 20);
	add_node(&list, 4);
	add_node(&list, 3);
	add_node(&list, 30);
	printf("Pile A before sorting:\n");
	curr = list;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	ps_quicksort(&list);
	printf("\n\nPile A after sorting:\n");
	curr = list;
	while (curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	return (0);
}