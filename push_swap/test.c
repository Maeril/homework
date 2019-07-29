#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// int main() // main de test, commenter le main de main.c et compiler avec *.c
// {
// 	int 		c;
// 	int 		i;
// 	int			n;
// 	char		**output; // les instructions sont stockees la pour les cleaner avant d'output
// 	t_pslist	list;
// 	t_pslist	*list_p;
// 	t_psflag	flag;

// 	c = 1;
// 	while (c <= 100)
// 	{
// 		list_p = node_fill(list_p, rand() % 1000 + 1);
// 		list_p = list_p->next;
// 		c++;
// 	}
// 	list_p->next = NULL;
// 	ps_quicksort(&list_p, 0, c, &flag); // SGFLT quand combine a convertto_list
// 	// output = ft_strsplit(flag.instruc, ' ');
// 	// output = papb_cleaner(output);
// 	// while (output[i])
// 	// {
// 	// 	if (ft_strcmp(output[i], "na"))
// 	// 		ft_putendl(output[i]);
// 	// 	i++;
// 	// }
// 	return (0);
// }