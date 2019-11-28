/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:17:02 by myener            #+#    #+#             */
/*   Updated: 2019/11/28 12:39:55 by myener           ###   ########.fr       */
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
        ft_printf("\033[1;36mNow fetching the commands.\n");
        ft_putstr("\033[0;36m(In manual mode, You may ");
        ft_printf("conclude your input by pressing ctrl + D.)\033[0m\n");
    }
    else if (code == 2)
    {
        ft_putstr("\033[1;36m\e[4m");
        ft_printf("The following commands were generated\e[0m:\033[0m\n");
    }
    else if (code == 3)
    {
        ft_printf("\033[0;36mFor a total of");
        ft_printf("\033[1;31m %d\033[0;36m instructions.\033[0m\n", nb);
    }
}
