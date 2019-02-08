/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 14:14:48 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 16:18:56 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"


t_data		type_is_int(va_list ap, t_data data)
{
	int hey;

	hey = 0;
	if (data.integer == 1)
		hey = va_arg(ap, int);
	printf("hey = %d\n", hey);
	return (data);
}


t_data		find_arg_type(va_list ap, t_data data, char *instructions, int i)
{
	int index;

	ft_putchar(instructions[i]);
	index = 0;
	if (data.d == 1 || data.i == 1 || data.o == 1 || data.x == 1 || data.X == 1)
		data.integer = 1;
	if (data.c == 1)
		data.car = 1;
	if (data.s == 1 || data.p == 1)
		data.str = 1;
	if (data.u == 1)
		data.unint = 1;
	if ((data.d == 1 || data.i == 1) && (data.hh == 1))
		data.signcar = 1;
	if ((data.d == 1 || data.i == 1) && (data.h == 1))
		data.sh = 1;
	if ((data.d == 1 || data.i == 1) && (data.l == 1))
		data.lg = 1;
	if ((data.d == 1 || data.i == 1) && (data.ll == 1))
		data.lglg = 1;
	if ((data.o == 1 || data.u == 1 || data.x == 1 || data.X == 1) && (data.hh == 1))
		data.unsigncar = 1;
	if ((data.o == 1 || data.u == 1 || data.x == 1 || data.X == 1) && (data.h == 1))
		data.unsignsh = 1;
	if ((data.o == 1 || data.u == 1 || data.x == 1 || data.X == 1) && (data.ll == 1))
		data.unsignlglg = 1;
	if ((data.o == 1 || data.u == 1 || data.x == 1 || data.X == 1) && (data.l == 1))
		data.unsignlg = 1;

	printf("a la fin de find arg type, data.integer = %d\n", data.integer);

	if (data.integer == 1)
		data = type_is_int(ap, data);


	return (data);
}
