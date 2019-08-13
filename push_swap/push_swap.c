/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:52:32 by myener            #+#    #+#             */
/*   Updated: 2019/08/13 17:46:36 by myener           ###   ########.fr       */
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

char		**duplicate_cleaner(char **tab1, int nb)
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
			break ;
		if (i == nb) // if mutually cancelling strings appear,
			i += 2; // increment i twice to "jump over" these array ranks
		else // else instructions are OK, so transfer them normally
		{
			tab2[j] = ft_strdup(tab1[i]);
			j++;
			i++;
		}
	}
	if (pattern_match(tab2[j - 2], tab2[j - 1])) // if mutually cancelling strings appear,
		tab2[j - 2] = NULL;
	return (tab2);
}

char		**papb_cleaner(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if (ft_strcmp(tab[i], "na"))
		{
			j = i + 1;
			while (tab[j] && !ft_strcmp(tab[j], "na"))
				j++;
			if (tab[j] && pattern_match(tab[i], tab[j]))
			{
				ft_bzero(tab[i], ft_strlen(tab[i]));
				tab[i] = ft_free_join(tab[i], "na");
				ft_bzero(tab[j], ft_strlen(tab[j]));
				tab[j] = ft_free_join(tab[j], "na");
				i -= 2;
			}
		}
		i++;
	}
	return (tab);
}

char		**push_swap(t_pslist *list, t_psflag *flag, char **argv)
{
	int		i;
	int		qs;
	int 	nb; // indicates the end of the list, is filled during convertto_list
	char	**output; // les instructions sont stockees la pour les cleaner avant d'output

	i = 0;
	qs = 0;
	list = convertto_list(argv, list, &nb); /* put all the arguments in chained list nodes */
	if ((check_list(list) == 0) && flag->ps) // if list is sorted yet (and flag = ps), finish immediately
	{
		list_free(list);
		exit (0);
	}
	if (check_list(list))
	{
		if ((i = check_length(list)) == 0)
		{
			list_free(list);
			exit (0); /* "si aucun paramètre n'est passé, ps termine immédiatement et n'affiche rien" */
		}
		else if ((i = check_length(list)) > 4 && (i <= 6)) // for small lists do a bubblesort
			ps_bubblesort(&list, flag);
		else
		{
			ps_quicksort(&list, 0, nb, flag); /* else do a quicksort */
			qs = 1;
		}
	}
	list_free(list);
	if (flag->instruc)
	{
		output = ft_spacesplit(flag->instruc);
		if (ft_strlen(flag->instruc) > 4 && qs) // si il y a plus d'une instruction
			output = papb_cleaner(output);
	}
	i = 0;
	if (flag->ch)
		return (flag->instruc ? output : NULL);
	else if (flag->ps)
		ps_displayer(output);
	free(output);
	free(flag->instruc);
	return (NULL);
}
