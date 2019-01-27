/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:04:27 by myener            #+#    #+#             */
/*   Updated: 2019/01/24 16:55:05 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_lst_add_new(t_block *forme, t_list *list)
{
	t_list	*new;

	while (new->next != NULL)
    if (!(new = malloc(sizeof(t_list))))
    {
        return (NULL);
		exit(EXIT_FAILURE);
    }
    if (!forme)
	{
		new->forme = NULL;
		new->forme_size = 0;
        exit(EXIT_FAILURE);
	}
	else
	{
		if (!(new->forme = malloc(sizeof(t_block) * (forme_size))))
		{
        	return (NULL);
            exit(EXIT_FAILURE);
        }
        ft_memcpy(new->forme, forme, forme_size);
		new->forme_size = forme_size;
	}
    new->letter = (next->letter + 1);
	new = new->next;
}

void	ft_lst_free(t_list *list)
{
	if (list)
	{
		ft_lstdel(&(list)->next);
        free(&list)->forme, (&list)->forme_size);
		list->next = NULL;
		free(list)
        list = NULL;
	}
}