/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:26:34 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/15 15:59:51 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		flag_minus(t_data data, int size)
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
	return (data);
}
