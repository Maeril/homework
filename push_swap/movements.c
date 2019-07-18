/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 17:37:08 by myener            #+#    #+#             */
/*   Updated: 2019/07/18 15:56:44 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(/* char *instruc , */t_pslist **src, t_pslist **dest, t_psflag *flag) // BUS ERROR
{
	t_pslist	*tmp;
	t_pslist	*tmp_dest;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	(*src)->type = ((*src)->type == 'a' ? 'b' : 'a'); // change type
	if (flag->ps)
		ft_printf("p%c\n", (*src)->type);
	tmp_dest = (*dest);
	(*dest) = (*src); // move as pile B's head (aka NULL for the 1st node)
	(*dest)->next = tmp_dest; // attach to old head
	(*dest)->prev = NULL; // clear anything before head
	(*src)->prev = NULL; // already null'd but you never kow
	if (tmp_dest)
		tmp_dest->prev = (*src);
	(*src) = tmp; // change src(pile A's head)'s pointed content to new head_a
	if (*src)
		(*src)->prev = NULL; // clear anything before new head_a
	// strcat(instruc, (dest->type == 'b' ? "pb " : "pa "));
}

void rotate(/* char *instruc , */t_pslist **head, int nb, t_psflag *flag) // move all nodes upwards - head becomes tail
{		 									 // nb = number of rotates
	int			i;
	t_pslist	*tmp;
	t_pslist	*tail;


	i = 0;
	if ((*head)->next)
	{
		while (i < nb)
		{
			if (flag->ps)
				ft_printf("r%c\n", (*head)->type = 'a' ? 'a' : 'b');
;			tail = *head;
			tmp = *head; // keep head position in tmp
			(*head) = tmp->next; // move head to new position
			while (tail && tail->next) // bring tail to the bottom of the list
				tail = tail->next;
			tail->next = tmp; // attach tmp to end of list
			tmp->prev = tail;
			tmp->next = NULL; // clear anything ar new tail
			(*head)->prev = NULL; // clear anything before new head
			i++;
		}
	}
	// strcat(instruc, (head->type == 'a' ? "ra " : "rb "));
}

void rrotate(/* char *instruc , */t_pslist **head, int nb, t_psflag *flag) // move all nodes downwards - tail becomes head
{											  // nb = number of rrotates
	int			i;
	t_pslist	*tmp;
	t_pslist	*tail;

	i = 0;
	if ((*head)->next) // make sure there is at least two nodes, otherwise nothing to be done
	{
		while (i < nb)
		{
			if (flag->ps)
				ft_printf("rr%c\n", (*head)->type = 'a' ? 'a' : 'b');
			tail = *head;
			while (tail && tail->next) // bring tail to the bottom of the list
				tail = tail->next;
			tmp = tail;	// keep tail position in tmp
			tail = tail->prev; // move tail to new position
			tmp->next = (*head); // attach tmp to beginning of the list
			(*head)->prev = tmp;
			(*head) = (*head)->prev;
			tmp->prev = NULL; // clear anything before new head
			tail->next = NULL; // clear anything ar new tail
			i++;
		}
	}
	// strcat(instruc, (head->type == 'a' ? "ra " : "rb "));
}

void swap(/* char *instruc , */t_pslist *p1, t_pslist *p2, t_psflag *flag) // swap two nodes inside a same pile
{
	int		tmp_data;
	char	tmp_type;

	if (flag->ps)
		ft_printf("s%c\n", p1->type = 'a' ? 'a' : 'b');
	tmp_data = p1->data;
	p1->data = p2->data;
	p2->data = tmp_data;
	tmp_type = p1->type;
	p1->type = p2->type;
	p2->type = tmp_type;
	// strcat(instruc, (p1->type == 'a' ? "sa " : "sb "));
}
