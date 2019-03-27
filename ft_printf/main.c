/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/27 15:44:41 by myener           ###   ########.fr       */
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

	double		nb;
	nb = -12547.58;

	// ret1 += ft_printf("test basique:");
	// ret1 += ft_printf("f simple:%f\n\n", nb);
    ret1 += ft_printf("MINE : space:% f\n\n", nb);
    // ret1 += ft_printf("plus:%+f\n\n", nb);
    // ret1 += ft_printf("hash:%#f\n\n", nb);
    // ret1 += ft_printf("precision:%.2f\n\n", nb);
    // ret1 += ft_printf("big prec:%.14f\n\n", nb);
    // ret1 += ft_printf("precision + hash:%#.0f\n\n", nb);
    // ret1 += ft_printf("space + prec:% .5f\n\n", nb);
    // ret1 += ft_printf("space + prec + hash:%# .0f\n\n", nb);
    // ret1 += ft_printf("space + prec + hash:% #.0f\n\n", nb);
    // ret1 += ft_printf("Plus + prec / grande:%+.5f\n\n", nb);
    // ret1 += ft_printf("Plus + prec / petite:%+.0f\n\n", nb);
    // ret1 += ft_printf("Plus + prec + hash:%#+.0f\n\n", nb);
    // ret1 += ft_printf("Prec + 0:%0.5f\n\n", nb);
    // ret1 += ft_printf("Prec + minus:%-.5f\n\n", nb);
    // ret1 += ft_printf("size:%5f\n\n", nb);
    // ret1 += ft_printf("size + space:% 5f\n\n", nb);
    // ret1 += ft_printf("size + plus:%+5f\n\n", nb);
    // ret1 += ft_printf("size + space:%# 5f\n\n", nb);
    // ret1 += ft_printf("size + plus:%#+5f\n\n", nb);
    // ret1 += ft_printf("size + minus:%-5f\n\n", nb);
    // ret1 += ft_printf("size + 0:%05f\n\n", nb);
    // ret1 += ft_printf("size + 0 + plus:%+05f\n\n", nb);
    // ret1 += ft_printf("size + 0 + plus:%0+5f\n\n", nb);
    // ret1 += ft_printf("size + 0 + prec:%05.3f\n\n", nb);
    // ret1 += ft_printf("size + 0 + prec + hash:%0#5.0f\n\n", nb);
    // ret1 += ft_printf("size + minus + prec:%-5.3f\n\n", nb);
    // ret1 += ft_printf("size + minus + prec + hash:%-#5.0f\n\n", nb);
    // ret1 += ft_printf("size + plus + 0 + prec:%+05.3f\n\n", nb);
    // ret1 += ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n\n", nb);
    // ret1 += ft_printf("size + espace + zero + prec:%0 5.3f\n\n", nb);
    // ret1 += ft_printf("size + espace + zero + prec:% 05.3f\n\n", nb);
    // ret1 += ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n\n", nb);
    // ret1 += ft_printf("size + minus + plus + prec:%-+5.3f\n\n", nb);
    // ret1 += ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n\n\n", nb);

	// ret2 += printf("test basique:");
	// ret2 += printf("f simple:%f\n\n", nb);
	ret2 += printf("SYST : space:% f\n\n", nb);
	// ret2 += printf("plus:%+f\n\n", nb);
	// ret2 += printf("hash:%#f\n\n", nb);
	// ret2 += printf("precision:%.2f\n\n", nb);
	// ret2 += printf("big prec:%.14f\n\n", nb);
	// ret2 += printf("precision + hash:%#.0f\n\n", nb);
	// ret2 += printf("space + prec:% .5f\n\n", nb);
	// ret2 += printf("space + prec + hash:%# .0f\n\n", nb);
	// ret2 += printf("space + prec + hash:% #.0f\n\n", nb);
	// ret2 += printf("Plus + prec / grande:%+.5f\n\n", nb);
	// ret2 += printf("Plus + prec / petite:%+.0f\n\n", nb);
	// ret2 += printf("Plus + prec + hash:%#+.0f\n\n", nb);
	// ret2 += printf("Prec + 0:%0.5f\n\n", nb);
	// ret2 += printf("Prec + minus:%-.5f\n\n", nb);
	// ret2 += printf("size:%5f\n\n", nb);
	// ret2 += printf("size + space:% 5f\n\n", nb);
	// ret2 += printf("size + plus:%+5f\n\n", nb);
	// ret2 += printf("size + space:%# 5f\n\n", nb);
	// ret2 += printf("size + plus:%#+5f\n\n", nb);
	// ret2 += printf("size + minus:%-5f\n\n", nb);
	// ret2 += printf("size + 0:%05f\n\n", nb);
	// ret2 += printf("size + 0 + plus:%+05f\n\n", nb);
	// ret2 += printf("size + 0 + plus:%0+5f\n\n", nb);
	// ret2 += printf("size + 0 + prec:%05.3f\n\n", nb);
	// ret2 += printf("size + 0 + prec + hash:%0#5.0f\n\n", nb);
	// ret2 += printf("size + minus + prec:%-5.3f\n\n", nb);
	// ret2 += printf("size + minus + prec + hash:%-#5.0f\n\n", nb);
	// ret2 += printf("size + plus + 0 + prec:%+05.3f\n\n", nb);
	// ret2 += printf("size + plus + 0 + prec + hash:%0+#5.0f\n\n", nb);
	// ret2 += printf("size + espace + zero + prec:%0 5.3f\n\n", nb);
	// ret2 += printf("size + espace + zero + prec:% 05.3f\n\n", nb);
	// ret2 += printf("size + espace + zero + prec + hash:%#0 5.0f\n\n", nb);
	// ret2 += printf("size + minus + plus + prec:%-+5.3f\n\n", nb);
	// ret2 += printf("size + minus + plus + prec + hash:%-#+5.0f\n\n\n", nb);

	printf("res mine : %d\n\n", ret1);
	printf("res syst : %d\n\n\n", ret2);

	return (0);
}