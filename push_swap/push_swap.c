/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:52:32 by myener            #+#    #+#             */
/*   Updated: 2019/07/22 15:14:57 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int			pattern_match(char *s1, char *s2)
{
	if ((!ft_strcmp(s1, "rra") && !ft_strcmp(s2, "ra"))
		|| (!ft_strcmp(s1, "ra") && !ft_strcmp(s2, "rra"))
		|| (!ft_strcmp(s1, "pa") && !ft_strcmp(s2, "pb"))
		|| (!ft_strcmp(s1, "pb") && !ft_strcmp(s2, "pa"))
		|| (!ft_strcmp(s1, "sa") && !ft_strcmp(s2, "sa"))
		|| (!ft_strcmp(s1, "sb") && !ft_strcmp(s2, "sb")))
		return (1);
	return (0);
}

int			final_tab_len(char **tab) // calculate needed length of final array
{									// once the bad strings are removed
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i + 1] == NULL)
			break;
		if (pattern_match(tab[i], tab[i + 1]))
			j++;
		i++;
	}
	return (i - j);
}

char		**duplicate_cleaner(char **tab1)
{
	int		i;
	int		j;
	int		len;
	char	**tab2;

	i = 0;
	len = final_tab_len(tab1);
	if (!(tab2 = malloc(sizeof(char*) * len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (tab1[i])
	{
		if (tab1[i + 1] == NULL)
			break;
		if (pattern_match(tab1[i], tab1[i + 1])) // if mutually cancelling strings appear,
			i += 2; // increment i twice to "jump over" these array ranks
		else // else instructions are OK, so transfer them normally
		{
			tab2[j] = ft_strdup(tab1[i]);
			j++;
			i++;
		}
	}
	tab2[j] = ft_strdup(tab1[i]);
	if (pattern_match(tab2[j - 1], tab2[j])) // if mutually cancelling strings appear,
		tab2[j - 1] = NULL;
	return (tab2);
}

char		**papb_cleaner(char **tab)
{
	int i;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if (pattern_match(tab[i], tab[i + 1]))
		{
			tab = duplicate_cleaner(tab);
			tab = papb_cleaner(tab);
		}
		i++;
	}
	tab = duplicate_cleaner(tab);
	return (tab);
}

void		push_swap(t_pslist *list, t_psflag *flag, char **argv)
{
	int		i;
	int 	nb; // indicates the end of the list, is filled during convertto_list
	char	**output; // les instructions sont stockees la pour les cleaner avant d'output

	i = 0;
	list = convertto_list(argv, list, &nb); /* put all the arguments in chained list nodes */
	if (check_list(list, flag)) // if list isn't sorted yet,
	{
		if ((i = check_length(list)) == 0)
			return ; /* "si aucun paramètre n'est passé, ps termine immédiatement et n'affiche rien" */
		else
			ps_quicksort(&list, 0, nb, flag); /* else we can proceed to sorting */
	}
	// printf("instructions = %s, len = %zu\n", flag->instruc, ft_strlen(flag->instruc));
	output = ft_strsplit(flag->instruc, ' ');
	if (ft_strlen(flag->instruc) > 4) // 4 c'est la taille qu'aurait au max une chaine avec juste 1 instructions.
		output = papb_cleaner(output);
	i = 0;
	while (output[i])
	{
		ft_putendl(output[i]);
		i++;
	}
}
