/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:52:32 by myener            #+#    #+#             */
/*   Updated: 2019/07/18 15:32:53 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_swap(t_pslist *list, t_psflag *flag, char **argv)
{
	int		i;
	int 	nb; // indicates the end of the list, is filled during convertto_list
	// char	*instruc; // les instructions sont stockees la pour les cleaner avant d'output

	i = 0;
	list = convertto_list(argv, list, &nb); /* put all the arguments in chained list nodes */
	if (check_list(list, flag)) // if list isn't sorted yet,
	{
		if ((i = check_length(list)) == 0)
			return ; /* "si aucun paramètre n'est passé, ps termine immédiatement et n'affiche rien" */
		else
			ps_quicksort(/* instruc, */&list, 0, nb, flag); /* else we can proceed to sorting */
	}
}
