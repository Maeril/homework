/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .debug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 21:54:55 by myener            #+#    #+#             */
/*   Updated: 2020/01/07 18:54:08 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/ft_printf/ft_printf.h"

void	pile_print(t_pslist *curr)
{
	while (curr && curr->next)
	{
		printf("%d, ", curr->data);
		curr = curr->next;
	}
	printf("%d.\n", curr->data);
}

void    display_tab(char **tab, int index) // debug
{
    int     i;

    i = index;
    while (tab[i])
    {
        if(ft_strcmp(tab[i], "na"))
            ft_putendl(tab[i]);
        i++;
    }
}

