/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:52:32 by myener            #+#    #+#             */
/*   Updated: 2019/06/23 20:42:24 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_pslist *list, char **argv)
{
	int	i;

	i = 0;
	list = convertto_list(argv, list); /* put all the arguments in chained list nodes */
	if (check_list(list))
	{
		if ((i = check_length(list)) == 0)
			return ; /* "si aucun paramètre n'est passé, ps termine immédiatement et n'affiche rien" */
		else if (i < /* une certaine valeur */)
			ps_insertion_sort(list);
		else
			ps_quicksort(list);
	}
}
