/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:17:02 by myener            #+#    #+#             */
/*   Updated: 2019/11/27 19:11:44 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char    **trim_comments(char **in, int i)
{
    int     j;
    int    len;
    char    **out;

    j = 0;
    len = i;
	if (!(out = malloc(sizeof(char*) * ((len - 2) + 1))))
        return (NULL);
	i = 1;
	while (in[i] && i < (len - 1))
	{
		out[j] = ft_strdup(in[i]); // faudra sans doute free in[i] ici
		i++;
		j++;
	}
	out[j] = NULL;
	// in ? free(in) : 0;
    return (out);
}

void    instructions_displayer(int code, int nb)
{
    if (code == 1)
    {
        ft_printf("\033[1;36mPlease enter the desired commands.\n");
        ft_printf("\033[0;36mYou may conclude your input by pressing ctrl + D.\033[0m\n");
    }
    else if (code == 2)
        ft_printf("\033[1;36mThe following commands were generated:\033[0m\n");
    else if (code == 3)
    {
        ft_printf("\033[0;36mFor a total of");
        ft_printf("\033[1;31m %d\033[0;36m instructions.\033[0m\n", nb);
    }
}
