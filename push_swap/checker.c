/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:49:20 by myener            #+#    #+#             */
/*   Updated: 2019/06/12 16:38:35 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_pslist *list)
{
	t_pslist *curr;

	curr = list;
	while (curr && curr->next)
	{
		if (curr->data > curr->next->data)
		{
			ft_putstr("KO\n");
			return ;
		}
		curr = curr->next;
	}
	ft_putstr("OK\n");
}