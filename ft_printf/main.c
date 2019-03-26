/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/26 18:23:21 by myener           ###   ########.fr       */
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

	int	nb = 45;
	ret1 += ft_printf("MINE = test o:%o\n", nb);
	ret1 += ft_printf("hash:%#o\n", nb);
	ret1 += ft_printf("precision / grande:%.5o\n", nb);
	ret1 += ft_printf("Prec + hash / grande:%#.5o\n", nb);
	ret1 += ft_printf("Prec + hash / petite:%#.1o\n", nb);
	ret1 += ft_printf("Prec + 0:%0.5o\n", nb);
	ret1 += ft_printf("Prec + minus:%-.5o\n", nb);
	ret1 += ft_printf("Size:%5o\n", nb);
	ret1 += ft_printf("size + prec:%7.3o\n", nb);
	ret1 += ft_printf("size + minus:%-5o\n", nb);
	ret1 += ft_printf("size + zero:%05o\n", nb);
	ret1 += ft_printf("MINE = size + zero + hash:%#05o\n", nb);
	ret1 += ft_printf("size + zero + prec:%05.3o\n", nb);
	ret1 += ft_printf("size + minus + prec:%-5.3o\n", nb);
	ret1 += ft_printf("MINE = size + hash + zero + prec:%#05.3o\n", nb);
	ret1 += ft_printf("MINE = size + hash + zero + prec:%0#5.3o\n", nb);
	ret1 += ft_printf("MINE = size + hash + minus + prec:%-#7.3o\n\n", nb);

	ret2 += printf("SYST = test o:%o\n", nb);
	ret2 += printf("hash:%#o\n", nb);
	ret2 += printf("precision / grande:%.5o\n", nb);
	ret2 += printf("Prec + hash / grande:%#.5o\n", nb);
	ret2 += printf("Prec + hash / petite:%#.1o\n", nb);
	ret2 += printf("Prec + 0:%0.5o\n", nb);
	ret2 += printf("Prec + minus:%-.5o\n", nb);
	ret2 += printf("Size:%5o\n", nb);
	ret2 += printf("size + prec:%7.3o\n", nb);
	ret2 += printf("size + minus:%-5o\n", nb);
	ret2 += printf("size + zero:%05o\n", nb);
	ret2 += printf("SYST = size + zero + hash:%#05o\n", nb);
	ret2 += printf("size + zero + prec:%05.3o\n", nb);
	ret2 += printf("size + minus + prec:%-5.3o\n", nb);
	ret2 += printf("SYST = size + hash + zero + prec:%#05.3o\n", nb);
	ret2 += printf("SYST = size + hash + zero + prec:%0#5.3o\n", nb);
	ret2 += printf("SYST = size + hash + minus + prec:%-#7.3o\n\n", nb);

	printf("res mine : %d\n", ret1);
	printf("res syst : %d\n\n", ret2);

	return (0);
}