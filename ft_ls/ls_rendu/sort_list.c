/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:42:23 by myener            #+#    #+#             */
/*   Updated: 2019/04/23 16:47:33 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_list_revdate(t_lsdata *head)
{
	t_lsdata				*i;
	t_lsdata				*j;
	t_lsdata				*tmp;

	i = head;
	j = i->next;
	while((i->next != NULL) && (i = i->next))
		while((j != NULL) && (j = j->next))
			if(i->date_sec < j->date_sec)
			{
				tmp = i->next;
				i->next = j->next;
				j->next = tmp;
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
/*Function to swap the lsdatas */
struct s_lsdata	*swap_nodes(struct s_lsdata* p1, struct s_lsdata* p2)
{
	struct s_lsdata	*tmp;

	tmp = p2->next;
	p2->next = p1;
	p1->next = tmp;
	return (p2);
}

// void	sort_list_alpha(t_lsdata *head)
// {
// 	t_lsdata	*i;
// 	t_lsdata	*j;
// 	t_lsdata	*tmp;

// 	i = head;
// 	j = i->next;
// 	while((i->next != NULL) && (i = i->next))
// 		while((j != NULL) && (j = j->next))
// 			if(ft_strcmp(i->filename, j->filename) > 0)
// 			{
// 				tmp = i;
// 				i = j;
// 				j = tmp;
// 			}
// }

// void	sort_list_revalpha(t_lsdata *head)
// {
// 	t_lsdata	*i;
// 	t_lsdata	*j;
// 	t_lsdata	*tmp;

// 	i = head;
// 	j = i->next;
// 	while((i->next != NULL) && (i = i->next))
// 		while((j != NULL) && (j = j->next))
// 			if(ft_strcmp(i->filename, j->filename) < 0)
// 			{
// 				tmp = i;
// 				i = j;
// 				j = tmp;
// 			}
// }