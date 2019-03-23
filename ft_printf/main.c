/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/23 18:18:19 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>

int			main(void)
{
	long		nb;
	int			ret1;
	int			ret2;

	nb = -45;

	ret1 = 0;
	ret1 += ft_printf("space% d\n", nb);
	ret1 += ft_printf("plus:%+d\n", nb);
	ret1 += ft_printf("precision:%.5d\n", nb);
	ret1 += ft_printf("space + prec:% .5d\n", nb);
	ret1 += ft_printf("Plus + prec / grande:%+.5d\n", nb);
	ret1 += ft_printf("Plus + prec / petite:%+.0d\n", nb);
	ret1 += ft_printf("Prec + 0:%0.5d\n", nb);
	ret1 += ft_printf("Prec + minus:%-.5d\n", nb);
	ret1 += ft_printf("size:%5d\n", nb);
	ret1 += ft_printf("size + space:% 5d\n", nb);
	ret1 += ft_printf("size + plus:%+5d\n", nb);
	ret1 += ft_printf("size + minus:%-5d\n", nb);
	ret1 += ft_printf("size + 0:%05d\n", nb);
	ret1 += ft_printf("size + 0 + plus:%+05d\n", nb);
	ret1 += ft_printf("size + 0 + plus:%0+5d\n", nb);
	ret1 += ft_printf("size + 0 + prec:%05.3d\n", nb);
	ret1 += ft_printf("size + minus + prec:%-5.3d\n", nb);
	ret1 += ft_printf("size + plus + 0 + prec:%+05.3d\n", nb);
	ret1 += ft_printf("size + espace + zero + prec:%0 5.3d\n", nb);
	ret1 += ft_printf("size + espace + zero + prec:% 05.3d\n", nb);
	ret1 += ft_printf("size + minus + plus + prec:%-+5.3d\n\n", nb);

	ret2 = 0;
	ret2 += printf("space% d\n", nb);
	ret2 += printf("plus:%+d\n", nb);
	ret2 += printf("precision:%.5d\n", nb);
	ret2 += printf("space + prec:% .5d\n", nb);
	ret2 += printf("Plus + prec / grande:%+.5d\n", nb);
	ret2 += printf("Plus + prec / petite:%+.0d\n", nb);
	ret2 += printf("Prec + 0:%0.5d\n", nb);
	ret2 += printf("Prec + minus:%-.5d\n", nb);
	ret2 += printf("size:%5d\n", nb);
	ret2 += printf("size + space:% 5d\n", nb);
	ret2 += printf("size + plus:%+5d\n", nb);
	ret2 += printf("size + minus:%-5d\n", nb);
	ret2 += printf("size + 0:%05d\n", nb);
	ret2 += printf("size + 0 + plus:%+05d\n", nb);
	ret2 += printf("size + 0 + plus:%0+5d\n", nb);
	ret2 += printf("size + 0 + prec:%05.3d\n", nb);
	ret2 += printf("size + minus + prec:%-5.3d\n", nb);
	ret2 += printf("size + plus + 0 + prec:%+05.3d\n", nb);
	ret2 += printf("size + espace + zero + prec:%0 5.3d\n", nb);
	ret2 += printf("size + espace + zero + prec:% 05.3d\n", nb);
	ret2 += printf("size + minus + plus + prec:%-+5.3d\n\n", nb);

	printf("\nres mine : %d\n", ret1);
	printf("res syst : %d\n\n\n", ret2);

	return (0);
}

			// printf("space = %d\n\n\n", data.flag->space);
			// printf("zero = %d\n\n\n", data.flag->zero);
			// printf("len = %d\n\n\n", len);



	// ret += ft_printf("space% hhd \n", nb); // manque 1 a la valeur de ret
	// ret += ft_printf("plus:%+hhd \n", nb);
	// ret += ft_printf("precision:%.5hhd \n", nb);
	// ret += ft_printf("space + prec:% .5hhd \n", nb); // manque 1 a la valeur de ret
	// ret += ft_printf("Plus + prec / grande:%+.5hhd \n", nb);
	// ret += ft_printf("Prec + 0:%0.5hhd \n", nb);
	// ret += ft_printf("Prec + minus:%-.5hhd \n", nb);
	// ret += ft_printf("size:%5hhd \n", nb);
	// ret += ft_printf("size + space:% 5hhd \n", nb);
	// ret += ft_printf("size + plus:%+5hhd \n", nb);
	// ret += ft_printf("size + minus:%-5hhd \n", nb);
	// ret += ft_printf("size + 0:%05hhd \n", nb);
	// ret += ft_printf("size + 0 + plus:%+05hhd \n", nb);
	// ret += ft_printf("size + 0 + plus:%0+5hhd \n", nb);
	// ret += ft_printf("size + 0 + prec:%05.3hhd \n", nb);
	// ret += ft_printf("size + minus + prec:%-5.3hhd \n", nb); // manque 1 espace
	// ret += ft_printf("size + plus + 0 + prec:%+05.3hhd \n", nb);
	// ret += ft_printf("size + espace + zero + prec:%0 5.3hhd \n", nb);
	// ret += ft_printf("size + espace + zero + prec:% 05.3hhd \n", nb);
	// ret += ft_printf("size + minus + plus + prec:%-+5.3hhd \n", nb); // manque 1 espace


	// ret += printf("space% hhd \n", nb);
	// ret += printf("plus:%+hhd \n", nb);
	// ret += printf("precision:%.5hhd \n", nb);
	// ret += printf("space + prec:% .5hhd \n", nb);
	// ret += printf("Plus + prec / grande:%+.5hhd \n", nb);
	// ret += printf("Prec + 0:%0.5hhd \n", nb);
	// ret += printf("Prec + minus:%-.5hhd \n", nb);
	// ret += printf("size:%5hhd \n", nb);
	// ret += printf("size + space:% 5hhd \n", nb);
	// ret += printf("size + plus:%+5hhd \n", nb);
	// ret += printf("size + minus:%-5hhd \n", nb);
	// ret += printf("size + 0:%05hhd \n", nb);
	// ret += printf("size + 0 + plus:%+05hhd \n", nb);
	// ret += printf("size + 0 + plus:%0+5hhd \n", nb);
	// ret += printf("size + 0 + prec:%05.3hhd \n", nb);
	// ret += printf("size + minus + prec:%-5.3hhd \n", nb);
	// ret += printf("size + plus + 0 + prec:%+05.3hhd \n", nb);
	// ret += printf("size + espace + zero + prec:%0 5.3hhd \n", nb);
	// ret += printf("size + espace + zero + prec:% 05.3hhd \n", nb);
	// ret += printf("size + minus + plus + prec:%-+5.3hhd \n", nb);