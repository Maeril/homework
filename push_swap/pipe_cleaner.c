/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:05:34 by myener            #+#    #+#             */
/*   Updated: 2019/10/10 16:49:24 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        {
           nb++;
        }
        i++;
    }
    printf("nb = %d\n", nb);
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
        i++;
    }
    out[j] = NULL;
    // i = 0;
    // while (out[i])
    // {
    //     printf(">%s<", out[i]);
    //     i++;
    // }
    return (out);
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
    // clean = piped_data_append_return(clean); // add \n at every string's end ?
	return (clean);
}