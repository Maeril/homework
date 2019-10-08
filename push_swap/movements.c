/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:37:08 by myener            #+#    #+#             */
/*   Updated: 2019/10/08 16:24:53 by myener           ###   ########.fr       */
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

int		push(t_pslist **src, t_pslist **dest, t_psflag *flag)
{
	t_pslist	*tmp;
	t_pslist	*tmp_dest;

	if (!(*src))
		return (0);
	tmp = (*src)->next;
	(*src)->type = ((*src)->type == 'a' ? 'b' : 'a');
	tmp_dest = (*dest);
	(*dest) = (*src);
	(*dest)->next = tmp_dest;
	(*dest)->prev = NULL;
	(*src)->prev = NULL;
	if (tmp_dest)
		tmp_dest->prev = (*src);
	(*src) = tmp;
	if (*src)
		(*src)->prev = NULL;
	if (flag->instruc)
		flag->instruc = ft_free_join(flag->instruc,
		((*dest)->type == 'b' ? "pb " : "pa "));
	else
		flag->instruc = ft_strdup(((*dest)->type == 'b' ? "pb " : "pa "));
	return (1);
}

int		rot(t_pslist **head, int rot, t_psflag *f)
{
	t_pslist	*tmp;
	t_pslist	*tail;

	tmp = NULL;
	tail = NULL;
	if ((*head)->next)
		while (rot > 0)
		{
			if (f->instruc)
				f->instruc = ft_free_join(f->instruc,
				((*head)->type == 'a' ? "ra " : "rb "));
			else
				f->instruc = ft_strdup((*head)->type == 'a' ? "ra " : "rb ");
			tail = *head;
			tmp = *head;
			(*head) = tmp->next;
			while (tail && tail->next)
				tail = tail->next;
			tail->next = tmp;
			tmp->prev = tail;
			tmp->next = NULL;
			(*head)->prev = NULL;
			rot--;
		}
	return (1);
}

int		rrot(t_pslist **head, int rot, t_psflag *f)
{
	t_pslist	*tmp;
	t_pslist	*tail;

	tmp = NULL;
	tail = NULL;
	if ((*head)->next)
		while (rot > 0)
		{
			if (f->instruc)
				f->instruc = ft_free_join(f->instruc,
				((*head)->type == 'a' ? "rra " : "rrb "));
			else
				f->instruc = ft_strdup((*head)->type == 'a' ? "rra " : "rrb ");
			tail = *head;
			while (tail && tail->next)
				tail = tail->next;
			tmp = tail;
			tail = tail->prev;
			tmp->next = (*head);
			(*head)->prev = tmp;
			(*head) = (*head)->prev;
			tail->next = NULL;
			rot--;
		}
	return (1);
}

int		swap(t_pslist *p1, t_pslist *p2, t_psflag *f)
{
	int		tmp_data;
	char	tmp_type;

	tmp_data = p1->data;
	p1->data = p2->data;
	p2->data = tmp_data;
	tmp_type = p1->type;
	p1->type = p2->type;
	p2->type = tmp_type;
	if (f->instruc)
		f->instruc = ft_free_join((f->instruc),
		(p1->type == 'a' ? "sa " : "sb "));
	else
		f->instruc = ft_strdup((p1->type == 'a' ? "sa " : "sb "));
	return (1);
}
