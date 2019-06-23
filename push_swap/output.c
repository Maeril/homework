/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:21:03 by myener            #+#    #+#             */
/*   Updated: 2019/06/23 20:14:52 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_output(int i)
{
	if (i == 1)
		write(2, "Error\n", 6);
	else if (i == 2)
		write(1, "KO\n", 3); /* output "KO" means the list isn't in ascending order */
	else if (i == 3)
		write(1, "OK\n", 3);
	return (0);
}