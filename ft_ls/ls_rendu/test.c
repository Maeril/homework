/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:16:31 by myener            #+#    #+#             */
/*   Updated: 2019/04/23 15:59:08 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* structure for a lsdata */
struct			s_lsdata
{
	char				*filename;
	char				*username;
	char				*groupname;
	long int			ls_namelen;
	long long int		date_sec;
	struct s_lsdata		*next;
}						t_lsdata;

/*Function to swap the lsdatas */
struct s_lsdata	*swap_nodes(struct s_lsdata* ptr1, struct s_lsdata* ptr2)
{
	struct lsdata* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return (ptr2);
}

/* Function to sort the list */
int bubblesort_list(struct s_lsdata** head, int count)
{
	struct s_lsdata** h;
	struct s_lsdata	*p1 = *h;
	struct s_lsdata	*p2 = p1->next;
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i <= count)
	{
		h = head;
		swapped = 0;
		j = 0;
		while (j < count - i - 1)
		{
			if (p1->date_sec > p2->date_sec)
			{
				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}
			h = &(*h)->next;
			j++;
		}
		/* break if the loop ended without any swap */
		if (!swapped)
			break;
		i++;
	}
}

void rev_list(struct s_lsdata** head)
{
	struct s_lsdata	*first;
	struct s_lsdata	*rest;

	if (*head == NULL)
	   return;
	first = *head;
	rest  = first->next;
	if (rest == NULL)
	   return;
	/* reverse the rest list and put the first element at the end */
	recursiveReverse(&rest);
	first->next->next  = first;
	/* tricky step -- see the diagram */
	first->next  = NULL;
	/* fix the head pointer */
	*head = rest;
}