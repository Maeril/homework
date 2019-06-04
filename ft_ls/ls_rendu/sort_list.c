/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:42:23 by myener            #+#    #+#             */
/*   Updated: 2019/05/28 10:53:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	swap_list_data(t_lsdata *p1, t_lsdata *p2)
{
	char			*tmp_name;
	long long int	tmp_date;
	long long int	tmp_size;

	tmp_name = p1->filename;
	p1->filename = p2->filename;
	p2->filename = tmp_name;
	tmp_date = p1->date_sec;
	p1->date_sec = p2->date_sec;
	p2->date_sec = tmp_date;
	tmp_size = p1->size;
	p1->size = p2->size;
	p2->size = tmp_size;
	return (1);
}

t_lsdata	*sort_list_revdate(t_lsdata *head)
{
	t_lsdata	*p1;
	t_lsdata	*p2;

	p1 = head;
	p2 = head;
	while (p2->next != NULL)
	{
		while ((p1->next != NULL))
		{
			if (p1->date_sec < p1->next->date_sec)
				swap_list_data(p1, p1->next);
			p1 = p1->next;
		}
		p1 = head;
		p2 = p2->next;
	}
	return (p1);
}

t_lsdata	*sort_list_date(t_lsdata *head)
{
	t_lsdata	*p1;
	t_lsdata	*p2;

	p1 = head;
	p2 = head;
	while (p2->next != NULL)
	{
		while ((p1->next != NULL))
		{
			if (p1->date_sec > p1->next->date_sec)
				swap_list_data(p1, p1->next);
			p1 = p1->next;
		}
		p1 = head;
		p2 = p2->next;
	}
	return (p1);
}

t_lsdata	*sort_list_alpha(t_lsdata *head)
{
	t_lsdata	*p1;
	t_lsdata	*p2;

	p1 = head;
	p2 = head;
	while (p2->next != NULL)
	{
		while ((p1->next != NULL))
		{
			if (ft_strcmp(p1->filename, p1->next->filename) > 0)
				swap_list_data(p1, p1->next);
			p1 = p1->next;
		}
		p1 = head;
		p2 = p2->next;
	}
	return (p1);
}

t_lsdata	*sort_list_revalpha(t_lsdata *head)
{
	t_lsdata	*p1;
	t_lsdata	*p2;

	p1 = head;
	p2 = head;
	while (p2->next != NULL)
	{
		while ((p1->next != NULL))
		{
			if (ft_strcmp(p1->filename, p1->next->filename) < 0)
				swap_list_data(p1, p1->next);
			p1 = p1->next;
		}
		p1 = head;
		p2 = p2->next;
	}
	return (p1);
}
