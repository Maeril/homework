/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:42:23 by myener            #+#    #+#             */
/*   Updated: 2019/04/24 16:23:36 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// t_lsdata	*sort_list_revdate(t_lsdata *head)
// {
// 	t_lsdata				*i;
// 	t_lsdata				*j;
// 	t_lsdata				*tmp;

// 	i = head;
// 	j = i->next;
// 	while((i->next != NULL) && (i = i->next))
// 		while((j != NULL) && (j = j->next))
// 			if(i->date_sec > j->date_sec)
// 			{
// 				tmp = i->next;
// 				i->next = j->next;
// 				j->next = tmp;
// 			}
// 	return (i);
// }

void	swap_list_data(t_lsdata* p1, t_lsdata* p2)
{
	char			*tmp_file;
	long int		tmp_len;
	long long int	tmp_date;

	tmp_file = p1->filename;
	p1->filename = p2->filename;
	p2->filename = tmp_file;
	tmp_len = p1->ls_namelen;
	p1->ls_namelen = p2->ls_namelen;
	p2->ls_namelen = tmp_len;
	tmp_date = p1->date_sec;
	p1->date_sec = p2->date_sec;
	p2->date_sec = tmp_date;
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