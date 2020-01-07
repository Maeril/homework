/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:26:59 by myener            #+#    #+#             */
/*   Updated: 2020/01/07 19:36:23 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pattern_match(char *s1, char *s2)
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

static int	rotate_replacer(char **tab, char *str, int marker, t_psflag *flag)
{
	int		i;
	int		j;
	int		k;

	i = marker;
	j = 0;
	k = i;
	while (k < (i + (flag->t - flag->nr)))
	{
		ft_bzero(tab[k], ft_strlen(tab[k]));
		tab[k] = ft_free_join(tab[k], !ft_strcmp(str, "rra") ? "ra" : "rra");
		k++;
	}
	j = k;
	while (j < (k + (flag->nr - (flag->t - flag->nr))))
	{
		ft_bzero(tab[j], ft_strlen(tab[j]));
		tab[j] = ft_free_join(tab[j], "na");
		j++;
	}
	return (flag->nr);
}

static void	rotate_cleaner(char **tab, t_psflag *flag)
{
	int		i;
	char	*str;
	int		marker;

	i = 0;
	marker = 0;
	str = NULL;
	while (tab[i])
	{
		if ((!ft_strcmp(tab[i], "rra")) || (!ft_strcmp(tab[i], "ra")))
		{
			marker = i;
			str = ft_strdup(tab[i]);
			flag->nr = 0;
			while (tab[i] && !ft_strcmp(tab[i++], str))
				flag->nr++;
			i = marker;
			if (flag->nr > (flag->t / 2))
				i += rotate_replacer(tab, str, marker, flag);
			free(str);
		}
		i++;
	}
}

void		papb_cleaner(char **tab, t_psflag *flag)
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
	rotate_cleaner(tab, flag);
}
