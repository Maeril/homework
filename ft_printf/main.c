/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/27 12:39:18 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>

int			main(void)
{
	int			ret1 = 0;
	int			ret2 = 0;

	unsigned long nb = 12356549864789;
	ret1 += ft_printf("test o:%lo\n", nb);
	ret1 += ft_printf("hash:%#lo\n", nb);
	ret1 += ft_printf("precision / grande:%.5lo\n", nb);
	ret1 += ft_printf("precision / petite:%.0lo\n", nb);
	ret1 += ft_printf("Prec + hash / grande:%#.5lo\n", nb);
	ret1 += ft_printf("Prec + hash / petite:%#.1lo\n", nb);
	ret1 += ft_printf("Prec + 0:%0.5lo\n", nb);
	ret1 += ft_printf("Prec + minus:%-.5lo\n", nb);
	ret1 += ft_printf("Size:%5lo\n", nb);
	ret1 += ft_printf("size + prec:%7.3lo\n", nb);
	ret1 += ft_printf("size + minus:%-5lo\n", nb);
	ret1 += ft_printf("size + zero:%05lo\n", nb);
	ret1 += ft_printf("size + zero + hash:%#05lo\n", nb);
	ret1 += ft_printf("size + zero + prec:%05.3lo\n", nb);
	ret1 += ft_printf("size + minus + prec:%-5.3lo\n", nb);
	ret1 += ft_printf("size + hash + zero + prec:%#05.3lo\n", nb);
	ret1 += ft_printf("size + hash + zero + prec:%0#5.3lo\n", nb);
	ret1 += ft_printf("size + hash + minus + prec:%-#7.3lo\n\n", nb);

	ret2 += printf("test o:%lo\n", nb);
	ret2 += printf("hash:%#lo\n", nb);
	ret2 += printf("precision / grande:%.5lo\n", nb);
	ret2 += printf("precision / petite:%.0lo\n", nb);
	ret2 += printf("Prec + hash / grande:%#.5lo\n", nb);
	ret2 += printf("Prec + hash / petite:%#.1lo\n", nb);
	ret2 += printf("Prec + 0:%0.5lo\n", nb);
	ret2 += printf("Prec + minus:%-.5lo\n", nb);
	ret2 += printf("Size:%5lo\n", nb);
	ret2 += printf("size + prec:%7.3lo\n", nb);
	ret2 += printf("size + minus:%-5lo\n", nb);
	ret2 += printf("size + zero:%05lo\n", nb);
	ret2 += printf("size + zero + hash:%#05lo\n", nb);
	ret2 += printf("size + zero + prec:%05.3lo\n", nb);
	ret2 += printf("size + minus + prec:%-5.3lo\n", nb);
	ret2 += printf("size + hash + zero + prec:%#05.3lo\n", nb);
	ret2 += printf("size + hash + zero + prec:%0#5.3lo\n", nb);
	ret2 += printf("size + hash + minus + prec:%-#7.3lo\n\n", nb);

	printf("res mine : %d\n", ret1);
	printf("res syst : %d\n\n", ret2);

	return (0);
}