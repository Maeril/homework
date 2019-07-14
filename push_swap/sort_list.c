/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 21:54:55 by myener            #+#    #+#             */
/*   Updated: 2019/07/13 15:45:52 by myener           ###   ########.fr       */
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

void	pile_print(t_pslist *curr)
{
	while (curr && curr->next)
	{
		printf("%d, ", curr->data);
		curr = curr->next;
	}
	printf("%d.\n", curr->data);
}

t_pslist	*node_malloc(t_pslist *list)
{
	if (!(list = malloc(sizeof(t_pslist))))
		return (NULL);
	list->data = 0;
	list->type = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

t_pslist	*node_fill(t_pslist *node, int data)
{
	node = node_malloc(node);
	node->data = data;
	node->type = 'a';
	return (node);
}

t_pslist	*convertto_list(char **argv, t_pslist *list, int *nb)
{
	int			i;
	t_pslist	*head;
	t_pslist	*tmp;

	/* first interation OUTSIDE THE LOOP to attach head effectively */
	i = 1; // 1 et pas 0 pour sauter l'executable
	*nb = 0;
	list = node_fill(list, ft_atoi(argv[i])); /* fill every node with each argument as an int */
	head = list;
	tmp = list; // stock list in tmp
	i++;
	while (argv[i]) /* while we go through the proof-read arguments*/
	{
		list->next = node_fill(list->next, ft_atoi(argv[i])); /* fill every node with each argument as an int */
		list = list->next; // move current node to next
		list->prev = tmp; // "pour" tmp into prev
		tmp = list; // stock list in tmp
		i++;
		(*nb)++;
	}
	list->next = NULL;
	// printf("\n");
	return (head); /* return the filled-up list */
}

void rotate(char *instruc, t_pslist **head, int nb) // move all nodes upwards - head becomes tail
{		 									 // nb = number of rotates
	int			i;
	t_pslist	*tmp;
	t_pslist	*tail;


	i = 0;
	while (i < nb)
	{
;		tail = *head;
		tmp = *head; // old head
		(*head) = tmp->next;
		while (tail && tail->next) // bring tail to the bottom of the list
			tail = tail->next;
		tail->next = tmp; // attach curr to end of list
		tmp->prev = tail; // clear anything before new head
		tmp->next = NULL;
		i++;
	}
	// ft_strcat(instruc, (head->type == 'a' ? "ra " : "rb "));
}

void rrotate(char *instruc, t_pslist **head, int nb) // move all nodes downwards - tail becomes head
{											  // nb = number of rrotates
	int			i;
	t_pslist	*tmp;
	t_pslist	*tail;

	i = 0;
	while (i < nb)
	{
		tail = *head;
		tmp = tail;
		while (tail && tail->next) // bring tail to the bottom of the list
			tail = tail->next;
		tail->next = (*head);
		(*head) = tail;
		(*head)->prev = NULL;
		tail = tmp->prev;
		tail->next = NULL;
		i++;
	}
	// ft_strcat(instruc, (head->type == 'a' ? "ra " : "rb "));
}

void push(char *instruc, t_pslist **src, t_pslist **dest) // BUS ERROR
{
	t_pslist	*tmp;
	t_pslist	*tmp_dest;

	if (!(*src))
		return ;
	tmp = (*src)->next;
	if (*src)
		(*src)->type = ((*src)->type == 'a' ? 'b' : 'a'); // change type
	tmp_dest = (*dest);
	(*dest) = (*src); // move as pile B's head (aka NULL for the 1st node)
	(*dest)->next = tmp_dest; // attach to old head
	(*dest)->prev = NULL; // clear anything before head
	(*src)->prev = NULL; // already null'd but you never kow
	if (tmp_dest)
		tmp_dest->prev = (*src); //SGFLT
	(*src) = tmp; // change src(pile A's head)'s pointed content to new head_a
	if (*src)
		(*src)->prev = NULL; // clear anything before new head_a
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

int		*sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int j;
	int tmp;

	if (size <= 1)
		return (0);
	while(i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int		median_calculator(t_pslist *head) // OK !
{
	int			s; // size
	int			*tab;
	t_pslist	*curr;

	curr = head;
	s = 0;
	while (curr && curr->next) // count size of the list
	{
		curr = curr->next;
		s++;
	}
	if (!(tab = malloc(sizeof(int) * s)))
		return (-1);
	curr = head;
	s = 0;
	while (curr && curr->next) // while we go through the list,
	{
		tab[s] = curr->data; // stock list's data in tab
		curr = curr->next;
		s++;
	}
	tab[s] = curr->data; // last node
	tab = sort_int_tab(tab, s);
	s /= 2;
	return (tab[s]); // return the int on the middle of the tab, so size / 2
}

t_pslist *ps_quicksort(char *instruc, t_pslist *head_a, int deb, int fin)
{
	int			i;
	int			nr;
	int			np;
	int			pivot;
	t_pslist	*head_b;
	t_pslist	*curr_b;

	pivot = median_calculator(head_a);
	printf("pivot = %d\n", pivot);
	head_b = NULL;
	i = deb;
	nr = 0;
	np = 0;
	if (deb == fin)
		return (0);
	rotate(instruc, &head_a, deb); // pseudo code
	printf("data = %d\n", head_a->data);
	printf("deb = %d && fin = %d\n", deb, fin);
	if ((deb + 1) == fin)
	{
		if (head_a->data > head_a->next->data)
			swap(instruc, head_a, head_a->next);
		rrotate(instruc, &head_a, deb); // pseudo code
	}
	while (head_a && head_a->next && i < fin) // fin - 1 pour eviter de repasser 2 fois sur le debut de la liste
	{
		if (head_a->data <= pivot)
		{
			printf("data = %d, push !\n", head_a->data);
			push(instruc, &head_a, &head_b);
			np++;
		}
		if (head_a->data > pivot)
		{
			printf("data = %d, rotate !\n", head_a->data);
			rotate(instruc, &head_a, 1/*???*/); // "fin" car on doit rotate tout a la fin de la pile A ?
			nr++;
		}
		i++;
	}
	while (head_b)
	{
		printf ("push back in pile A\n");
		push(instruc, &head_b, &head_a);
	}
	rrotate(instruc, &head_a, deb); // pseudo code
	ps_quicksort(instruc, head_a, deb, (deb + np) - 1); // sort all small nums (which are in the beginning of the list)
	ps_quicksort(instruc, head_a, (deb + np), fin); // sort all big nums (which are right after)
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
	int			nb;
	char		*instruc;
	t_pslist	list_a;
	t_pslist	*head_a;
	t_pslist	*curr;

	if (argc == 1)
		printf("Please enter arguments for the program to sort.\n");
	else if (argc == 2)
		printf("Nothing to sort, you just entered %s.\n", argv[1]);
	else if (argc >= 3)
	{
		head_a = convertto_list(argv, &list_a, &nb);
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
		curr = head_a;
		curr = ps_quicksort(instruc, head_a, 0, nb); // ici deb = 0 & fin = la "vraie" fin
		while (curr && curr->next)
		{
			printf("%d, ", curr->data);
			curr = curr->next;
		}
		printf("%d.\n", curr->data);
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


// t_pslist *ps_bubblesort(char *instruc, t_pslist *head_a)
// {
// 	t_pslist	head_b;
// 	t_pslist	*tmp_b;
// 	t_pslist	*curr_a;
// 	t_pslist	*curr_b;

// 	curr_a = head_a;
// 	tmp_b = node_malloc(&head_b);
// 	while (curr_a && curr_a->next)
// 	{
// 		while (curr_a && curr_a->next)
// 		{
// ;			if (curr_a->data > curr_a->next->data)
// 				swap(instruc, curr_a, curr_a->next);
// 			push(instruc, head_a, tmp_b);
// 			curr_a = curr_a->next;
// 		}
// 		if (tmp_b && !(tmp_b->next))
// 		{
// 			push(instruc, tmp_b, head_a);
// 		}
// 		else
// 		{
// 			curr_b = tmp_b;
// 			while (curr_b && curr_b->next)
// 			{
// 				if (curr_b->data < curr_b->next->data)
// 					swap(instruc, curr_b, curr_b->next);
// 				push(instruc, &head_b, head_a);
// 				curr_b = curr_b->next;
// 			}
// 		}
// 		push(instruc, &head_b, head_a);
// 		curr_a = curr_a->next;
// 	}
// 	return (head_a);
// }
