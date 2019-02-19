/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:26:34 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 19:57:26 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_minus(t_lngt *lngt, int size)
{
	int space_to_add;

	space_to_add = 0;
	if (size < lngt->width)
	{
		space_to_add = lngt->width - size;
		while (space_to_add)
		{
			ft_putchar(' ');
			space_to_add--;
		}
	}
}
