/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/28 17:00:38 by myener           ###   ########.fr       */
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
	nb = 45.123456789;

	// ret1 += ft_printf("MINE : test basique:\n");
	// ret1 += ft_printf("MINE : f simple:%f\n", nb);
    // ret1 += ft_printf("MINE : space:% f\n", nb);
    // ret1 += ft_printf("MINE : plus:%+f\n", nb);
    // ret1 += ft_printf("MINE : hash:%#f\n", nb);
    // ret1 += ft_printf("MINE : precision:%.2f\n", nb);
    // ret1 += ft_printf("MINE : big prec:%.14f\n", nb);
    // ret1 += ft_printf("MINE : precision + hash:%#.f\n", nb);
    // ret1 += ft_printf("MINE : space + prec:% .5f\n", nb);
    // ret1 += ft_printf("MINE : space + prec + hash:%# .0f\n", nb);
    // ret1 += ft_printf("MINE : space + prec + hash:% #.0f\n", nb);
    // ret1 += ft_printf("MINE : Plus + prec / grande:%+.5f\n", nb);
    // ret1 += ft_printf("MINE : Plus + prec / petite:%+.0f\n", nb);
    // ret1 += ft_printf("MINE : Plus + prec + hash:%#+.0f\n", nb);
    // ret1 += ft_printf("MINE : Prec + 0:%0.5f\n", nb);
    // ret1 += ft_printf("MINE : Prec + minus:%-.5f\n", nb);
    // ret1 += ft_printf("MINE : size:%5f\n", nb);
    // ret1 += ft_printf("MINE : size + space:% 5f\n", nb);
    // ret1 += ft_printf("MINE : size + plus:%+5f\n", nb);
    // ret1 += ft_printf("MINE : size + space:%# 5f\n", nb);
    // ret1 += ft_printf("MINE : size + plus:%#+5f\n", nb);
    // ret1 += ft_printf("MINE : size + minus:%-5f\n", nb);
    // ret1 += ft_printf("MINE : size + 0:%05f\n", nb);
    // ret1 += ft_printf("MINE : size + 0 + plus:%+05f\n", nb);
    // ret1 += ft_printf("MINE : size + 0 + plus:%0+5f\n", nb);
    // ret1 += ft_printf("MINE : size + 0 + prec:%05.3f\n", nb);
    // ret1 += ft_printf("MINE : size + 0 + prec + hash:%0#5.0f\n", nb);
    // ret1 += ft_printf("MINE : size + minus + prec:%-5.3f\n", nb);
    // ret1 += ft_printf("MINE : size + minus + prec + hash:%-#5.0f\n", nb);
    ret1 += ft_printf("MINE : size + plus + 0 + prec:%+05.3f\n", nb);
    ret1 += ft_printf("MINE : size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
    ret1 += ft_printf("MINE : size + espace + 0 + prec:%0 5.3f\n", nb);
    ret1 += ft_printf("MINE : size + espace + 0 + prec:% 05.3f\n", nb);
    ret1 += ft_printf("MINE : size + espace + zero + prec + hash:%#0 5.0f\n", nb);
    ret1 += ft_printf("MINE : size + minus + plus + prec:%-+5.3f\n", nb);
    ret1 += ft_printf("MINE : size + minus + plus + prec + hash:%-#+5.0f\n\n", nb);

	printf("\n\n");

	// ret2 += printf("SYST : test basique:\n");
	// ret2 += printf("SYST : f simple:%f\n", nb);
	// ret2 += printf("SYST : space:% f\n", nb);
	// ret2 += printf("SYST : plus:%+f\n", nb);
	// ret2 += printf("SYST : hash:%#f\n", nb);
	// ret2 += printf("SYST : precision:%.2f\n", nb);
	// ret2 += printf("SYST : big prec:%.14f\n", nb);
	// ret2 += printf("SYST : precision + hash:%#.f\n", nb);
	// ret2 += printf("SYST : space + prec:% .5f\n", nb);
	// ret2 += printf("SYST : space + prec + hash:%# .0f\n", nb);
	// ret2 += printf("SYST : space + prec + hash:% #.0f\n", nb);
	// ret2 += printf("SYST : Plus + prec / grande:%+.5f\n", nb);
	// ret2 += printf("SYST : Plus + prec / petite:%+.0f\n", nb);
	// ret2 += printf("SYST : Plus + prec + hash:%#+.0f\n", nb);
	// ret2 += printf("SYST : Prec + 0:%0.5f\n", nb);
	// ret2 += printf("SYST : Prec + minus:%-.5f\n", nb);
	// ret2 += printf("SYST : size:%5f\n", nb);
	// ret2 += printf("SYST : size + space:% 5f\n", nb);
	// ret2 += printf("SYST : size + plus:%+5f\n", nb);
	// ret2 += printf("SYST : size + space:%# 5f\n", nb);
	// ret2 += printf("SYST : size + plus:%#+5f\n", nb);
	// ret2 += printf("SYST : size + minus:%-5f\n", nb);
	// ret2 += printf("SYST : size + 0:%05f\n", nb);
	// ret2 += printf("SYST : size + 0 + plus:%+05f\n", nb);
	// ret2 += printf("SYST : size + 0 + plus:%0+5f\n", nb);
	// ret2 += printf("SYST : size + 0 + prec:%05.3f\n", nb);
	// ret2 += printf("SYST : size + 0 + prec + hash:%0#5.0f\n", nb);
	// ret2 += printf("SYST : size + minus + prec:%-5.3f\n", nb);
	// ret2 += printf("SYST : size + minus + prec + hash:%-#5.0f\n", nb);
	ret2 += printf("SYST : size + plus + 0 + prec:%+05.3f\n", nb);
	ret2 += printf("SYST : size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	ret2 += printf("SYST : size + espace + 0 + prec:%0 5.3f\n", nb);
	ret2 += printf("SYST : size + espace + 0 + prec:% 05.3f\n", nb);
	ret2 += printf("SYST : size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	ret2 += printf("SYST : size + minus + plus + prec:%-+5.3f\n", nb);
	ret2 += printf("SYST : size + minus + plus + prec + hash:%-#+5.0f\n\n", nb);

	printf("res mine : %d\n", ret1);
	printf("res syst : %d\n\n", ret2);

	return (0);
}