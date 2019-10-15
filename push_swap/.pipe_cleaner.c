/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:05:34 by myener            #+#    #+#             */
/*   Updated: 2019/10/15 19:11:40 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**append_return(char	**in)
{
	int	i;

	i = 0;
	while (in[i])
	{
		in[i] = ft_free_join(in[i], "\n");
		i++;
	}
	return (in);
}

char	**piped_data_doubledown(char **in)
{
    int     i;
    int     j;
    int     nb;
    char    **out;

    i = 0;
    nb = 0;
    out = NULL;
    while (in[i])
    {
        if (!ft_strcmp(in[i], "sa\n") || !ft_strcmp(in[i], "sb\n")
			|| !ft_strcmp(in[i], "pa\n") || !ft_strcmp(in[i], "pb\n")
			|| !ft_strcmp(in[i], "ra\n") || !ft_strcmp(in[i], "rb\n")
			|| !ft_strcmp(in[i], "rra\n") || !ft_strcmp(in[i], "rrb\n")
			|| !ft_strcmp(in[i], "ss\n") || !ft_strcmp(in[i], "rrr\n")
			|| !ft_strcmp(in[i], "rr\n") || !ft_strcmp(in[i], "")
			|| !ft_strcmp(in[i], "sa") || !ft_strcmp(in[i], "sb")
			|| !ft_strcmp(in[i], "pa") || !ft_strcmp(in[i], "pb")
			|| !ft_strcmp(in[i], "ra") || !ft_strcmp(in[i], "rb")
			|| !ft_strcmp(in[i], "rra") || !ft_strcmp(in[i], "rrb")
			|| !ft_strcmp(in[i], "ss") || !ft_strcmp(in[i], "rrr")
			|| !ft_strcmp(in[i], "rr"))
           nb++;
		else
			i++;
        i++;
    }
    if (!(out = malloc(sizeof(char*) * (nb + 1))))
        return (NULL);
    i = 0;
    j = 0;
    while (in[i])
    {
        if (!ft_strcmp(in[i], "sa\n") || !ft_strcmp(in[i], "sb\n")
			|| !ft_strcmp(in[i], "pa\n") || !ft_strcmp(in[i], "pb\n")
			|| !ft_strcmp(in[i], "ra\n") || !ft_strcmp(in[i], "rb\n")
			|| !ft_strcmp(in[i], "rra\n") || !ft_strcmp(in[i], "rrb\n")
			|| !ft_strcmp(in[i], "ss\n") || !ft_strcmp(in[i], "rrr\n")
			|| !ft_strcmp(in[i], "rr\n") || !ft_strcmp(in[i], "")
			|| !ft_strcmp(in[i], "sa") || !ft_strcmp(in[i], "sb")
			|| !ft_strcmp(in[i], "pa") || !ft_strcmp(in[i], "pb")
			|| !ft_strcmp(in[i], "ra") || !ft_strcmp(in[i], "rb")
			|| !ft_strcmp(in[i], "rra") || !ft_strcmp(in[i], "rrb")
			|| !ft_strcmp(in[i], "ss") || !ft_strcmp(in[i], "rrr")
			|| !ft_strcmp(in[i], "rr"))
        {
            out[j] = ft_strdup(in[i]);
            j++;
        }
		else
			i++;
        i++;
    }
    out[j] = NULL;
    return (out);
}

int		incorrect_read(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '\n' && tab[i][j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**piped_data_cleaner(char **dirty)
{
	int		i;
	int		j;
	char	*stock;
	char	**clean;

	i = 0;
	stock = NULL;
	clean = NULL;
	while (dirty[i])
	{
		j = 0;
		while (dirty[i][j])
		{
			if (dirty[i][j] == '\n' && dirty[i][j + 1])
				stock = stock ? ft_free_join(stock, dirty[i]) : ft_strdup(dirty[i]);
			j++;
		}
		i++;
	}
	clean = ft_strsplit(stock, '\n');
    clean = piped_data_doubledown(clean);
    clean = piped_data_append_return(clean);
	return (clean);
}