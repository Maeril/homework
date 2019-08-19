/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .insertion_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:13:23 by myener            #+#    #+#             */
/*   Updated: 2019/08/19 14:15:55 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct node
{
  	  int data;
		struct node *next;
};

struct node *head=NULL;

void insert_sort(int data)
{
		struct node *temp=head;
		struct node *prev=NULL;
		struct node *ptr;

		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->data=data;
		ptr->next=NULL;

		if(temp==NULL) //Executes when linked list is empty
		{
				ptr->next=NULL;
				head=ptr;
				return;
		}

		if(data<temp->data) //Executes if given data is less than data in first node of linked list
		{
				ptr->next=head;
				head=ptr;
				return;
		}
		else
		{
				while(temp!=NULL)
				{
						if(data>temp->data) //Traverse to location we want to insert the node + 1 node
						{
								prev=temp;
								temp=temp->next;
								continue;
						}
						else //Insert the node
						{
								prev->next=ptr;
								ptr->next=temp;
								return;
						}
				}
				prev->next=ptr; //Insert node at last
		}
}

void print()
{
		struct node *temp=head;
		printf("\nList:");
		while(temp!=NULL)
		{
				printf("\n%d ",temp->data);
				temp=temp->next;
		}
}

int main()
{
		insert_sort(23);
		print();
		insert_sort(10);
		print();
		insert_sort(15);
		print();
		insert_sort(45);
		print();
		insert_sort(50);
		print();
		return 0;
}