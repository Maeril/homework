#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int main() // main de test, commenter le main de main.c et compiler avec *.c
{
	int 		c;
	int 		i;
	int			n;
	int			nb;
	char		**tab;
	char		**output; // les instructions sont stockees la pour les cleaner avant d'output
	t_pslist	list;
	t_pslist	*list_p;
	t_psflag	flag;

	if (!(tab = malloc(sizeof(char*) * 100 + 1)))
		return (0);
	c = 1;
	i = 0;
	while (c <= 100)
	{
		n = rand() % 100 + 1;
		tab[i] = ft_itoa(n);
		i++;
		c++;
	}
	list_p = convertto_list(tab, &list, &nb);
	while (*tab)
	{
		free (*tab);
		tab++;
	}
	ps_quicksort(&list_p, 0, nb, &flag); // sorting algo - not working ? (solution: c a cause des triplons)
	output = ft_strsplit(flag.instruc, ' ');
	output = papb_cleaner(output);
	while (output[i])
	{
		if (ft_strcmp(output[i], "na"))
			ft_putendl(output[i]);
		i++;
	}
	return (0);
}