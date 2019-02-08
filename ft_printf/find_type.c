/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:14:48 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 17:40:40 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"


t_data		ft_typeis_int(va_list ap, t_data data)
{
	int hey;

	hey = 0;
	if (data.integer == 1)
		hey = va_arg(ap, int);
	printf("hey = %d\n", hey);
	return (data);
}
