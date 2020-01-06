/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:26:59 by myener            #+#    #+#             */
/*   Updated: 2020/01/06 19:27:39 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    display_tab(char **tab, int index) // debug
{
    int     i;

    i = index;
    while (tab[i])
    {
        // if(ft_strcmp(tab[i], "na"))
            ft_putendl(tab[i]);
        i++;
    }
}

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

// static int  cleanutil(char *str, char *replacement)
// {
//     ft_bzero(str, ft_strlen(str));
// 	   str = ft_free_join(str, replacement);
//     return (1);
// }

void	    papb_cleaner(char **tab)
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
    // display_tab(tab, 0);
}

static int  rotate_replacer(char**tab, char *str, int marker, int pile_size)
{
    int     i;
    int     j;
    int     k;
    int     repeat_nb;

    i = marker;
    j = 0;
    k = 0;
    repeat_nb = 0;
    // printf("la pile a une longueur de %d, il y a %d %s à la suite.\n", pile_size, repeat_nb, str);
    while (!ft_strcmp(tab[i], str))
    {
        repeat_nb++;
        i++;
    }
    if (repeat_nb > (pile_size / 2))
    {
        printf("marker = %d\n", marker);
        printf("pile_size = %d, repeat_nb = %d '%s', replaced by %d '%s', %d '%s' left to turn into 'na'.\n", pile_size, repeat_nb, str, pile_size - repeat_nb, !ft_strcmp(str, "rra") ? "ra" : "rra", repeat_nb - (pile_size - repeat_nb), str);
        i = marker;
        k = i;
        while (k < (i + (pile_size - repeat_nb)))
        {
            printf("tab[%d] AVANT: %s\n", k, tab[k]);
            ft_bzero(tab[k], ft_strlen(tab[k]));
            printf("tab[%d] APRES 1: %s\n", k, tab[k]);
	        if (!ft_strcmp(str, "rra"))
                tab[k] = ft_free_join(tab[k], "ra");
            else if (!ft_strcmp(str, "ra"))
                tab[k] = ft_free_join(tab[k], "mih");
            printf("tab[%d] APRES 2: %s\n\n", k, tab[k]);
            k++;
        }
        // display_tab(tab, 0);
        j = k;
        while (j < (k + (repeat_nb - (pile_size - repeat_nb))))
        {
            ft_bzero(tab[j], ft_strlen(tab[j]));
			tab[j] = ft_free_join(tab[j], "na");
            j++;
        }
    }
    return (repeat_nb);
}

void        rotate_cleaner(char **tab, t_psflag *flag)
{
    int    i;
    int    marker;

    i = 0;
    marker = 0;
    while (tab[i])
    {
        if ((!ft_strcmp(tab[i], "rra")) || (!ft_strcmp(tab[i], "ra")))
        {
            marker = i; // le marker semle mauvais mais il est bon
            i += rotate_replacer(tab, tab[i], marker, flag->t);
            i--; // accurate ?
        }
        i++;
    }
}
