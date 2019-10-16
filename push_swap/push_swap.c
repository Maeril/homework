/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:52:32 by myener            #+#    #+#             */
/*   Updated: 2019/10/16 15:36:23 by myener           ###   ########.fr       */
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

int			final_tab_len(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i + 1] == NULL)
			break ;
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

	len = final_tab_len(tab1);
	if (!(tab2 = malloc(sizeof(char*) * len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (tab1[i])
	{
		if (tab1[i + 1] == NULL)
			break ;
		i += (i == nb) ? 2 : 0;
		if (i != nb)
		{
			tab2[j] = ft_strdup(tab1[i]);
			j++;
			i++;
		}
	}
	if (pattern_match(tab2[j - 2], tab2[j - 1]))
		tab2[j - 2] = NULL;
	return (tab2);
}

char		**papb_cleaner(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
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
				i -= (i > 0) ? 2 : 1;
			}
		}
		i++;
	}
	return (tab);
}

char		**push_swap(t_pslist *list, t_psflag *flag, char **argv)
{
	int		i;
	int		nb;
	int		ret;
	char	**output;

	i = 0;
	list = convertto_list(argv, list, &nb);
	((ret = duplicate_finder(list))) && flag->ps ? list_free(list) : 0;
	ret && flag->ps ? ps_output(1) : 0;
	if (check_list(list))
		push_swap_saver(i, nb, list, flag);
	else if (flag->ps)
	{
		list_free(list);
		exit(0);
	}
	list_free(list);
	output = flag->instruc ? ft_spacesplit(flag->instruc) : NULL;
	i = 0;
	output = output && ft_strlen(flag->instruc) > 4 ?
	papb_cleaner(output) : output;
	if (flag->ch)
		return (flag->instruc ? output : NULL);
	flag->ps ? ps_displayer(output) : 0;
	free(output);
	free(flag->instruc);
	return (NULL);
}
