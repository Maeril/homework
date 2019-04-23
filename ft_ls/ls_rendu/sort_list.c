/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:42:23 by myener            #+#    #+#             */
/*   Updated: 2019/04/23 13:30:42 by myener           ###   ########.fr       */
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
				tmp = i;
				i = j;
				j = tmp;
			}
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