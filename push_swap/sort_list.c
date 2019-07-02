/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 21:54:55 by myener            #+#    #+#             */
/*   Updated: 2019/07/02 20:52:07 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

typedef struct			s_pslist
{
	int				data;
	char			type;
	struct s_pslist	*next;
	struct s_pslist	*prev;

}						t_pslist;

t_pslist	*list_malloc(t_pslist *list)
{
	if (!(list = malloc(sizeof(t_pslist))))
		return (NULL);
	list->data = 0;
	list->type = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_pslist	*nodefill(t_pslist *node, int data)
{
	node = list_malloc(node);
	node->data = data;
	node->type = 'a';
	return (node);
}

t_pslist	*convertto_list(char **argv, t_pslist *list)
{
	int			i;
	t_pslist	*curr;

	curr = list;
	i = 1; // 1 et pas 0 pour sauter l'executable
	while (argv[i]) /* while we go through the proof-read arguments*/
	{
		curr = nodefill(curr, ft_atoi(argv[i])); /* fill every node with each argument as an int */
		printf("%d, ", curr->data);
		curr = curr->next;
		i++;
	}
	printf("\n");
	return (list); /* return the filled-up list */
}

void rotate(char *instruc, t_pslist *head) // move all nodes upwards
{
	t_pslist	*curr;
	t_pslist	*tail;

	curr = head;
	tail = head;
	curr->next = NULL; // cut curr from the top of the list
	while (tail && tail->next) // bring tail to the bottom of the list
		tail = tail->next;
	curr->prev = tail; // attach curr to end of list
	tail->next = curr; // same
	head = head->next; // move head to next node (which is the new head)
	head->prev = NULL; // clear anything before new head
	ft_strcat(instruc, (head->type == 'a' ? "ra " : "rb "));
}

void rrotate(char *instruc, t_pslist *head) // move all nodes downwards
{
	t_pslist	*curr;
	t_pslist	*tail;

	while (tail && tail->next) // bring tail to the bottom of the list
		tail = tail->next;
	curr = tail;
	curr->prev = NULL; // cut curr from the bottom of the list
	curr->next = head; // attach curr to beginning of list
	head->prev = curr; // same
	tail = tail->prev; // move tail to precedent node (which is the new tail)
	tail->next = NULL; // clear anything after new tail
	// /!\ here curr is the new head
	ft_strcat(instruc, (curr->type == 'a' ? "tta " : "ttb "));
}

void push(char *instruc, t_pslist *src, t_pslist *dest) // push src's head to top of dest
{
	t_pslist	*curr;

	curr = src;
	curr->type = (curr->type == 'a') ? 'b' : 'a'; // change the type to the new pile's
	curr->next = dest; // attach curr to the beginning of the list
	dest->prev = curr; // same
	src = src->next; // move src to its new head
	src->prev = NULL; // clear anything before new head
	// ft_strcat(instruc, (dest->type == 'b' ? "pb " : "pa "));
}

void swap(char *instruc, t_pslist *p1, t_pslist *p2) // swap two nodes inside a same pile
{
	int		tmp_data;
	char	tmp_type;

	tmp_data = p1->data;
	p1->data = p2->data;
	p2->data = tmp_data;
	tmp_type = p1->type;
	p1->type = p2->type;
	p2->type = tmp_type;
	// ft_strcat(instruc, (p1->type == 'a' ? "sa " : "sb "));
}

// void ps_quicksort(char *instruc, t_pslist *head_a)
// {
// 	int	i;
// 	int	nR;
// 	int pivot;
// 	t_pslist *curr;

// 	if (debut == fin)
// 	// 	return;
// 	curr = head_a;
// 	rotate(instruc, curr);
// 	if (debut + 1 == fin)
// 	{
// 		if (A->data[0] > A->data[1])
// 			swap(instruc, A);
// 		rrotate(instruc, A, debut);
// 		return;
// 	}
// 	pivot = 0;
// 	i = 0;
// 	while (i <= fin - debut)
// 	{
// 		pivot += A->data[i];
// 		i++;
// 	}
// 	pivot = (int)(pivot / (fin - debut + 1));
// 	nR = 0;
// 	i = 0;
// 	while (i <= fin - debut)
// 	{
// 		if (A->data[0] < pivot)
// 			push(instruc, A, B);
// 		else
// 		{
// 			rotate(instruc, A, 1);
// 			nR++;
// 		}
// 		i++;
// 	}
// 	rrotate(instruc, A, nR);
// 	nR = B->size;
// 	while (B->size > 0)
// 		push(instruc, B, A);
// 	rrotate(instruc, A, debut);
// 	ps_quicksort(instruc, A, debut, debut + nR-1);
// 	ps_quicksort(instruc, A, debut + nR, fin);
// }

t_pslist *ps_bubblesort(char *instruc, t_pslist *head_a)
{
	t_pslist	head_b;
	t_pslist	*curr_a;
	t_pslist	*curr_b;

	curr_a = head_a;
	curr_b = &head_b;
	while (curr_a && curr_a->next) // comme on a déjà ce while là,
	{
		// while (curr_a && curr_a->next) // <- je crois que celui-ci est inutile ?
		// {
		if (curr_a->data > curr_a->next->data)
			swap(instruc, curr_a, curr_a->next);
		push(instruc, head_a, &head_b);
		// }
		while (curr_b && curr_b->next)
		{
			if (curr_b->data < curr_b->next->data)
			{
				swap(instruc, curr_b, curr_b->next);
			}
			push(instruc, &head_b, head_a);
			curr_b = curr_b->next;
		}
		push(instruc, &head_b, head_a);
		curr_a = curr_a->next;
	}
	return (head_a);
}

int ps_cleaner(char *src, const char *rem)
{
	char *cur;
	int r = 0;
	while ((cur = ft_strstr(src, rem)))
	{
		ft_strcpy(cur, (cur + ft_strlen(rem)));
		r++;
	}
	return (r);
}

void replace(char *c)
{
	while (*c)
	{
		if (*c == 't')
			*c = 'r';
		c++;
	}
}
int main(int argc, char** argv)
{
	// int		i;
	int		Nb;
	t_pslist	list_a;
	t_pslist	*head_a;
	t_pslist	tail_a;
	t_pslist	*curr;
	char	*instruc;

	if (argc == 1)
		printf("please enter arguments for the program to sort.\n");
	else if (argc == 2)
		printf("nothing to sort, you just entered %s.\n", argv[1]);
	else if (argc >= 3)
	{
		head_a = convertto_list(argv, &list_a);
		instruc = (char *)malloc(1000 * 15);
		instruc[0] = '\0';
		// i = 0;
		// while (i < nLong)
		// {
		// 	printf("%d, ", head_a.data[i]);
		// 	i++;
		// }
		// ps_quicksort(instruc, &head_a);
		// else
		head_a = ps_bubblesort(instruc, head_a);

		curr = head_a;
		while (curr && curr->next)
		{
			printf("%d, ", curr->data);
			curr = curr->next;
		}
		// printf("\n%s\n", instruc);
		// Nb = 1;
		// while (Nb > 0) // juste pour afficher les instructions
		// {
		// 	Nb = ps_cleaner(instruc, "pa pb ");
		// 	Nb += ps_cleaner(instruc, "ra tta ");
		// 	Nb += ps_cleaner(instruc, "tta ra ");
		// 	Nb += ps_cleaner(instruc, "pb pa ");
		// 	Nb += ps_cleaner(instruc, "sa sa ");
		// 	Nb += ps_cleaner(instruc, "sb sb ");
		// 	printf("modifs = %d\n", Nb);
		// }
		// replace(instruc);
		// printf("\n%s", instruc);
		// free(instruc);
	}
	return (0);
}