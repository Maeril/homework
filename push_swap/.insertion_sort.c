/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .insertion_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:13:23 by myener            #+#    #+#             */
/*   Updated: 2019/10/05 17:00:08 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pslist	*insert_sort(t_pslist **head, int data)
{
	t_pslist *temp;
	t_pslist *prev;
	t_pslist *ptr;

	temp = *head;
	ptr = malloc(sizeof(t_pslist));
	ptr->data = data;
	ptr->next = NULL;
	prev = NULL;
	if(temp == NULL) //Executes when linked list is empty
	{
		ptr->next = NULL;
		head = ptr;
		return ;
	}
	if(data < temp->data) //Executes if given data is less than data in first node of linked list
	{
		ptr->next = head;
		head = ptr;
		return ;
	}
	else
	{
		while(temp != NULL)
		{
			if(data > temp->data) //Traverse to location we want to insert the node + 1 node
			{
				prev = temp;
				temp = temp->next;
				continue;
			}
			else //Insert the node
			{
				prev->next = ptr;
				ptr->next = temp;
				return;
			}
		}
		prev->next=ptr; //Insert node at last
	}
}
