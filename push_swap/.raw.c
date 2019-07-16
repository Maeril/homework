/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 21:54:55 by myener            #+#    #+#             */
/*   Updated: 2019/07/16 17:42:54 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

// typedef struct			s_pslist
// {
// 	int				data;
// 	char			type;
// 	struct s_pslist	*next;
// 	struct s_pslist	*prev;

// }						t_pslist;

// int			check_list(t_pslist **head)
// {
// 	t_pslist *curr;

// 	curr = (*head); /* keep track of the head of the chained list */
// 	while (curr && curr->next) /* while the chained list exists, go through it */
// 	{
// 		if (curr->data > curr->next->data) /* if one data is greater than the next, */
// 			return (0); /* return 0 to signify the error */
// 		curr = curr->next;
// 	}
// 	return (1); /* if all is sorted return 1 */

// }

void	pile_print(t_pslist *curr)
{
	while (curr && curr->next)
	{
		printf("%d, ", curr->data);
		curr = curr->next;
	}
	printf("%d.\n", curr->data);
}

// t_pslist	*node_malloc(t_pslist *list)
// {
// 	if (!(list = malloc(sizeof(t_pslist))))
// 		return (NULL);
// 	list->data = 0;
// 	list->type = 0;
// 	list->next = NULL;
// 	list->prev = NULL;
// 	return (list);
// }

// t_pslist	*node_fill(t_pslist *node, int data)
// {
// 	node = node_malloc(node);
// 	node->data = data;
// 	node->type = 'a';
// 	return (node);
// }

// t_pslist	*convertto_list(char **argv, t_pslist *list, int *nb)
// {
// 	int			i;
// 	t_pslist	*head;
// 	t_pslist	*tmp;

// 	/* first interation OUTSIDE THE LOOP to attach head effectively */
// 	i = 1; // 1 et pas 0 pour sauter l'executable
// 	*nb = 0;
// 	list = node_fill(list, ft_atoi(argv[i])); /* fill every node with each argument as an int */
// 	head = list;
// 	tmp = list; // stock list in tmp
// 	i++;
// 	while (argv[i]) /* while we go through the proof-read arguments*/
// 	{
// 		list->next = node_fill(list->next, ft_atoi(argv[i])); /* fill every node with each argument as an int */
// 		list = list->next; // move current node to next
// 		list->prev = tmp; // "pour" tmp into prev
// 		tmp = list; // stock list in tmp
// 		i++;
// 		(*nb)++;
// 	}
// 	list->next = NULL;
// 	// printf("\n");
// 	return (head); /* return the filled-up list */
// }

// void rotate(char *instruc, t_pslist **head, int nb) // move all nodes upwards - head becomes tail
// {		 									 // nb = number of rotates
// 	int			i;
// 	t_pslist	*tmp;
// 	t_pslist	*tail;


// 	i = 0;
// 	if ((*head)->next)
// 	{
// 		while (i < nb)
// 		{
// ;			tail = *head;
// 			tmp = *head; // keep head position in tmp
// 			(*head) = tmp->next; // move head to new position
// 			while (tail && tail->next) // bring tail to the bottom of the list
// 				tail = tail->next;
// 			tail->next = tmp; // attach tmp to end of list
// 			tmp->prev = tail;
// 			tmp->next = NULL; // clear anything ar new tail
// 			(*head)->prev = NULL; // clear anything before new head
// 			i++;
// 		}
// 	}
// 	// strcat(instruc, (head->type == 'a' ? "ra " : "rb "));
// }

// void rrotate(char *instruc, t_pslist **head, int nb) // move all nodes downwards - tail becomes head
// {											  // nb = number of rrotates
// 	int			i;
// 	t_pslist	*tmp;
// 	t_pslist	*tail;

// 	i = 0;
// 	if ((*head)->next) // make sure there is at least two nodes, otherwise nothing to be done
// 	{
// 		while (i < nb)
// 		{
// 			printf("rra\n");
// 			tail = *head;
// 			while (tail && tail->next) // bring tail to the bottom of the list
// 				tail = tail->next;
// 			tmp = tail;	// keep tail position in tmp
// 			tail = tail->prev; // move tail to new position
// 			tmp->next = (*head); // attach tmp to beginning of the list
// 			(*head)->prev = tmp;
// 			(*head) = (*head)->prev;
// 			tmp->prev = NULL; // clear anything before new head
// 			tail->next = NULL; // clear anything ar new tail
// 			i++;
// 		}
// 	}
// 	// strcat(instruc, (head->type == 'a' ? "ra " : "rb "));
// }

// void push(char *instruc, t_pslist **src, t_pslist **dest) // BUS ERROR
// {
// 	t_pslist	*tmp;
// 	t_pslist	*tmp_dest;

// 	if (!(*src))
// 		return ;
// 	tmp = (*src)->next;
// 	if (*src)
// 		(*src)->type = ((*src)->type == 'a' ? 'b' : 'a'); // change type
// 	tmp_dest = (*dest);
// 	(*dest) = (*src); // move as pile B's head (aka NULL for the 1st node)
// 	(*dest)->next = tmp_dest; // attach to old head
// 	(*dest)->prev = NULL; // clear anything before head
// 	(*src)->prev = NULL; // already null'd but you never kow
// 	if (tmp_dest)
// 		tmp_dest->prev = (*src); //SGFLT
// 	(*src) = tmp; // change src(pile A's head)'s pointed content to new head_a
// 	if (*src)
// 		(*src)->prev = NULL; // clear anything before new head_a
// 	// strcat(instruc, (dest->type == 'b' ? "pb " : "pa "));
// }

// void swap(char *instruc, t_pslist *p1, t_pslist *p2) // swap two nodes inside a same pile
// {
// 	int		tmp_data;
// 	char	tmp_type;

// 	tmp_data = p1->data;
// 	p1->data = p2->data;
// 	p2->data = tmp_data;
// 	tmp_type = p1->type;
// 	p1->type = p2->type;
// 	p2->type = tmp_type;
// 	// strcat(instruc, (p1->type == 'a' ? "sa " : "sb "));
// }

// int		mean_calculator(t_pslist *head, int deb, int fin)
// {
// 	int			s; // size
// 	t_pslist	*curr;
// 	int			tot;

// 	curr = head;
// 	s = 0;
// 	while (s < deb)
// 	{
// 		curr = curr->next;
// 		s++;
// 	}
// 	tot = 0;
// 	while(s <= fin)
// 	{
// 		tot += curr->data;
// 		curr = curr->next;
// 		s++;
// 	}
// 	return (tot / (fin - deb + 1));
// }

// t_pslist *ps_quicksort(char *instruc, t_pslist **head_a, int deb, int fin)
// {
// 	int			i;
// 	int			nr;
// 	int			np;
// 	int			pivot;
// 	t_pslist	*head_b;
// 	t_pslist	*curr_b;

// 	head_b = NULL;
// 	i = deb;
// 	pivot = mean_calculator((*head_a), deb, fin);
// 	if (check_list(head_a) == 1) // if ALREADY SORTED, finish now
// 		return ((*head_a));
// 	if (deb == fin) // if only 1 node, finish now
// 		return (0);
// 	rotate(instruc, head_a, deb);
// 	if ((deb + 1) == fin) // if only 2 nodes
// 	{
// 		if ((*head_a)->data > (*head_a)->next->data)
// 			swap(instruc, (*head_a), (*head_a)->next);
// 		rrotate(instruc, head_a, deb); // pseudo code
// 		return ((*head_a));
// 	}
// 	nr = 0;
// 	np = 0;
// 	if ((*head_a)->data <= pivot)
// 	{
// 		printf ("pb\n");
// 		push(instruc, head_a, &head_b);
// 		np++;
// 	}
// 	else if ((*head_a)->data > pivot)
// 	{
// 		printf ("ra\n");
// 		rotate(instruc, head_a, 1);
// 		nr++;
// 	}
// 	while ((head_a && (*head_a)->next) && (i < fin)) // "fin - 1" car un des nodes a deja ete traite juste avant
// 	{
// 		if ((*head_a)->data <= pivot)
// 		{
// 			printf ("pb\n");
// 			push(instruc, head_a, &head_b);
// 			np++;
// 		}
// 		else if ((*head_a)->data > pivot)
// 		{
// 			printf ("ra\n");
// 			rotate(instruc, head_a, 1);
// 			nr++;
// 		}
// 		i++;
// 	}
// 	rrotate(instruc, head_a, nr);
// 	while (head_b)
// 	{
// 		printf ("pa\n");
// 		push(instruc, &head_b, head_a);
// 	}
// 	rrotate(instruc, head_a, deb);
// 	ps_quicksort(instruc, head_a, deb, (deb + np) - 1); // sort all small nums (which are in the beginning of the list)
// 	ps_quicksort(instruc, head_a, (deb + np), fin); // sort all big nums (which are right ar)
// 	return ((*head_a));
// }

// int ps_cleaner(char *src, const char *rem)
// {
// 	char *cur;
// 	int r = 0;
// 	while ((cur = ft_strstr(src, rem)))
// 	{
// 		ft_strcpy(cur, (cur + ft_strlen(rem)));
// 		r++;
// 	}
// 	return (r);
// }

// void replace(char *c)
// {
// 	while (*c)
// 	{
// 		if (*c == 't')
// 			*c = 'r';
// 		c++;
// 	}
// }

// int main(int argc, char** argv)
// {
// 	int			nb;
// 	char		*instruc;
// 	t_pslist	list_a;
// 	t_pslist	*head_a;
// 	t_pslist	*curr;

// 	if (argc == 1)
// 		printf("Please enter arguments for the program to sort.\n");
// 	else if (argc == 2)
// 		printf("Nothing to sort, you just entered %s.\n", argv[1]);
// 	else if (argc >= 3)
// 	{
// 		head_a = convertto_list(argv, &list_a, &nb);
// 		instruc = (char *)malloc(1000 * 15);
// 		instruc[0] = '\0';
// 		// i = 0;
// 		// while (i < nLong)
// 		// {
// 		// 	printf("%d, ", head_a.data[i]);
// 		// 	i++;
// 		// }
// 		// ps_quicksort(instruc, &head_a);
// 		// else
// 		curr = head_a;
// 		curr = ps_quicksort(instruc, &head_a, 0, nb); // ici deb = 0 & fin = la "vraie" fin
// 		while (curr && curr->next)
// 		{
// 			printf("%d, ", curr->data);
// 			curr = curr->next;
// 		}
// 		printf("%d.\n", curr->data);
// 		// printf("\n%s\n", instruc);
// 		// Nb = 1;
// 		// while (Nb > 0) // juste pour afficher les instructions
// 		// {
// 		// 	Nb = ps_cleaner(instruc, "pa pb ");
// 		// 	Nb += ps_cleaner(instruc, "ra tta ");
// 		// 	Nb += ps_cleaner(instruc, "tta ra ");
// 		// 	Nb += ps_cleaner(instruc, "pb pa ");
// 		// 	Nb += ps_cleaner(instruc, "sa sa ");
// 		// 	Nb += ps_cleaner(instruc, "sb sb ");
// 		// 	printf("modifs = %d\n", Nb);
// 		// }
// 		// replace(instruc);
// 		// printf("\n%s", instruc);
// 		// free(instruc);
// 	}
// 	return (0);
// }
