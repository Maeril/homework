/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/22 17:07:45 by myener           ###   ########.fr       */
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

	nb = -879650;

	ret1 = 0;
	ret1 += ft_printf("max int :  %d\n", INT16_MAX);
	ret1 += ft_printf("min int :  %d\n", INT16_MIN);
	ret1 += ft_printf("max int :  %d\n", INT32_MAX);
	ret1 += ft_printf("min int :  %d\n", INT32_MIN);
	ret1 += ft_printf("max long :  %ld\n", LONG_MAX);
	ret1 += ft_printf("min long :  %ld\n", LONG_MIN);
	ret1 += ft_printf("max long long :  %lld\n", __LONG_LONG_MAX__);
	ret1 += ft_printf("min long long :  %lld\n\n", -9223372036854775808);

	ret2 = 0;

	ret2 += printf("max int :  %d\n", INT16_MAX);
	ret2 += printf("min int :  %d\n", INT16_MIN);
	ret2 += printf("max int :  %d\n", INT32_MAX);
	ret2 += printf("min int :  %d\n", INT32_MIN);
	ret2 += printf("max long :  %ld\n", LONG_MAX);
	ret2 += printf("min long :  %ld\n", LONG_MIN);
	ret2 += printf("max long long :  %lld\n", __LONG_LONG_MAX__);
	ret2 += printf("min long long :  %lld\n\n", -9223372036854775808);

	printf("\nres mine : %d\n\n", ret1);
	printf("res syst : %d\n\n\n\n", ret2);

	return (0);
}

			// printf("space = %d\n\n\n\n", data.flag->space);
			// printf("zero = %d\n\n\n\n", data.flag->zero);
			// printf("len = %d\n\n\n\n", len);



	// ret += ft_printf("space% hhd \n\n", nb); // manque 1 a la valeur de ret
	// ret += ft_printf("plus:%+hhd \n\n", nb);
	// ret += ft_printf("precision:%.5hhd \n\n", nb);
	// ret += ft_printf("space + prec:% .5hhd \n\n", nb); // manque 1 a la valeur de ret
	// ret += ft_printf("Plus + prec / grande:%+.5hhd \n\n", nb);
	// ret += ft_printf("Prec + 0:%0.5hhd \n\n", nb);
	// ret += ft_printf("Prec + minus:%-.5hhd \n\n", nb);
	// ret += ft_printf("size:%5hhd \n\n", nb);
	// ret += ft_printf("size + space:% 5hhd \n\n", nb);
	// ret += ft_printf("size + plus:%+5hhd \n\n", nb);
	// ret += ft_printf("size + minus:%-5hhd \n\n", nb);
	// ret += ft_printf("size + 0:%05hhd \n\n", nb);
	// ret += ft_printf("size + 0 + plus:%+05hhd \n\n", nb);
	// ret += ft_printf("size + 0 + plus:%0+5hhd \n\n", nb);
	// ret += ft_printf("size + 0 + prec:%05.3hhd \n\n", nb);
	// ret += ft_printf("size + minus + prec:%-5.3hhd \n\n", nb); // manque 1 espace
	// ret += ft_printf("size + plus + 0 + prec:%+05.3hhd \n\n", nb);
	// ret += ft_printf("size + espace + zero + prec:%0 5.3hhd \n\n", nb);
	// ret += ft_printf("size + espace + zero + prec:% 05.3hhd \n\n", nb);
	// ret += ft_printf("size + minus + plus + prec:%-+5.3hhd \n\n", nb); // manque 1 espace


	// ret += printf("space% hhd \n\n", nb);
	// ret += printf("plus:%+hhd \n\n", nb);
	// ret += printf("precision:%.5hhd \n\n", nb);
	// ret += printf("space + prec:% .5hhd \n\n", nb);
	// ret += printf("Plus + prec / grande:%+.5hhd \n\n", nb);
	// ret += printf("Prec + 0:%0.5hhd \n\n", nb);
	// ret += printf("Prec + minus:%-.5hhd \n\n", nb);
	// ret += printf("size:%5hhd \n\n", nb);
	// ret += printf("size + space:% 5hhd \n\n", nb);
	// ret += printf("size + plus:%+5hhd \n\n", nb);
	// ret += printf("size + minus:%-5hhd \n\n", nb);
	// ret += printf("size + 0:%05hhd \n\n", nb);
	// ret += printf("size + 0 + plus:%+05hhd \n\n", nb);
	// ret += printf("size + 0 + plus:%0+5hhd \n\n", nb);
	// ret += printf("size + 0 + prec:%05.3hhd \n\n", nb);
	// ret += printf("size + minus + prec:%-5.3hhd \n\n", nb);
	// ret += printf("size + plus + 0 + prec:%+05.3hhd \n\n", nb);
	// ret += printf("size + espace + zero + prec:%0 5.3hhd \n\n", nb);
	// ret += printf("size + espace + zero + prec:% 05.3hhd \n\n", nb);
	// ret += printf("size + minus + plus + prec:%-+5.3hhd \n\n", nb);