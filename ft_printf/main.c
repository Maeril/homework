/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/04/02 17:43:43 by myener           ###   ########.fr       */
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

	ret1 += ft_printf("%.0s\n", "");
	printf("\n");
	ret2 += printf("%.0s\n", "");
	ret1 += ft_printf("%.0s\n", NULL);
	ret2 += printf("%.0s\n", NULL);
	ret1 += ft_printf("%.0s\n", "Okalm");
	ret2 += printf("%.0s\n", "Okalm");
	ret1 += ft_printf("%.0s\n", "asd34a");
	ret2 += printf("%.0s\n", "asd34a");

	printf("\nres mine : %d\n", ret1);
	printf("res syst : %d\n\n", ret2);

	return (0);
}

/*
	double		nb;

    nb = -0.000;

	ret1 += ft_printf("MINE = test basique:");
    ret1 += ft_printf("MINE = space:% f\n", nb);
    ret1 += ft_printf("MINE = plus:%+f\n", nb);
    ret1 += ft_printf("MINE = hash:%#f\n", nb);
    ret1 += ft_printf("MINE = precision:%.2f\n", nb);
    ret1 += ft_printf("MINE = big prec:%.14f\n", nb);
    ret1 += ft_printf("MINE = precision + hash:%#.0f\n", nb);
    ret1 += ft_printf("MINE = space + prec:% .5f\n", nb);
    ret1 += ft_printf("MINE = space + prec + hash:%# .0f\n", nb);
    ret1 += ft_printf("MINE = space + prec + hash:% #.0f\n", nb);
    ret1 += ft_printf("MINE = Plus + prec / grande:%+.5f\n", nb);
    ret1 += ft_printf("MINE = Plus + prec / petite:%+.0f\n", nb);
    ret1 += ft_printf("MINE = Plus + prec + hash:%#+.0f\n", nb);
    ret1 += ft_printf("MINE = Prec + 0:%0.5f\n", nb);
    ret1 += ft_printf("MINE = Prec + minus:%-.5f\n", nb);
    ret1 += ft_printf("MINE = size:%5f\n", nb);
    ret1 += ft_printf("MINE = size + space:% 5f\n", nb);
    ret1 += ft_printf("MINE = size + plus:%+5f\n", nb);
    ret1 += ft_printf("MINE = size + space:%# 5f\n", nb);
    ret1 += ft_printf("MINE = size + plus:%#+5f\n", nb);
    ret1 += ft_printf("MINE = size + minus:%-5f\n", nb);
    ret1 += ft_printf("MINE = size + 0:%05f\n", nb);
    ret1 += ft_printf("MINE = size + 0 + plus:%+05f\n", nb);
    ret1 += ft_printf("MINE = size + 0 + plus:%0+5f\n", nb);
    ret1 += ft_printf("MINE = size + 0 + prec:%05.3f\n", nb);
    ret1 += ft_printf("MINE = size + 0 + prec + hash:%0#5.0f\n", nb);
    ret1 += ft_printf("MINE = size + minus + prec:%-5.3f\n", nb);
    ret1 += ft_printf("MINE = size + minus + prec + hash:%-#5.0f\n", nb);
    ret1 += ft_printf("MINE = size + plus + 0 + prec:%+05.3f\n", nb);
    ret1 += ft_printf("MINE = size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    ret1 += ft_printf("MINE = size + espace + zero + prec:%0 5.3f\n", nb);
    ret1 += ft_printf("MINE = size + espace + zero + prec:% 05.3f\n", nb);
    ret1 += ft_printf("MINE = size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    ret1 += ft_printf("MINE = size + minus + plus + prec:%-+5.3f\n", nb);
    ret1 += ft_printf("MINE = size + minus + plus + prec + hash:%-#+5.0f\n", nb);

	printf("\n\n");

	ret2 += printf("SYST = test basique:");
	ret2 += printf("SYST = space:% f\n", nb);
	ret2 += printf("SYST = plus:%+f\n", nb);
	ret2 += printf("SYST = hash:%#f\n", nb);
	ret2 += printf("SYST = precision:%.2f\n", nb);
	ret2 += printf("SYST = big prec:%.14f\n", nb);
	ret2 += printf("SYST = precision + hash:%#.0f\n", nb);
	ret2 += printf("SYST = space + prec:% .5f\n", nb);
	ret2 += printf("SYST = space + prec + hash:%# .0f\n", nb);
	ret2 += printf("SYST = space + prec + hash:% #.0f\n", nb);
	ret2 += printf("SYST = Plus + prec / grande:%+.5f\n", nb);
	ret2 += printf("SYST = Plus + prec / petite:%+.0f\n", nb);
	ret2 += printf("SYST = Plus + prec + hash:%#+.0f\n", nb);
	ret2 += printf("SYST = Prec + 0:%0.5f\n", nb);
	ret2 += printf("SYST = Prec + minus:%-.5f\n", nb);
	ret2 += printf("SYST = size:%5f\n", nb);
	ret2 += printf("SYST = size + space:% 5f\n", nb);
	ret2 += printf("SYST = size + plus:%+5f\n", nb);
	ret2 += printf("SYST = size + space:%# 5f\n", nb);
	ret2 += printf("SYST = size + plus:%#+5f\n", nb);
	ret2 += printf("SYST = size + minus:%-5f\n", nb);
	ret2 += printf("SYST = size + 0:%05f\n", nb);
	ret2 += printf("SYST = size + 0 + plus:%+05f\n", nb);
	ret2 += printf("SYST = size + 0 + plus:%0+5f\n", nb);
	ret2 += printf("SYST = size + 0 + prec:%05.3f\n", nb);
	ret2 += printf("SYST = size + 0 + prec + hash:%0#5.0f\n", nb);
	ret2 += printf("SYST = size + minus + prec:%-5.3f\n", nb);
	ret2 += printf("SYST = size + minus + prec + hash:%-#5.0f\n", nb);
	ret2 += printf("SYST = size + plus + 0 + prec:%+05.3f\n", nb);
	ret2 += printf("SYST = size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	ret2 += printf("SYST = size + espace + zero + prec:%0 5.3f\n", nb);
	ret2 += printf("SYST = size + espace + zero + prec:% 05.3f\n", nb);
	ret2 += printf("SYST = size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	ret2 += printf("SYST = size + minus + plus + prec:%-+5.3f\n", nb);
	ret2 += printf("SYST = size + minus + plus + prec + hash:%-#+5.0f\n", nb);
	*/