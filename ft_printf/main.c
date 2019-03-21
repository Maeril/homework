/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/21 16:43:25 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>

int			main(void)
{
	long		nb;
	int			ret;
	nb = 125;

	ret = 0;
	// ret += ft_printf("space% hhd \n", nb); // manque 1 a la valeur de ret
	ret += ft_printf("plus:%+hhd \n", nb);
	ret += ft_printf("precision:%.5hhd \n", nb);
	// ret += ft_printf("space + prec:% .5hhd \n", nb); // manque 1 a la valeur de ret
	ret += ft_printf("Plus + prec / grande:%+.5hhd \n", nb);
	ret += ft_printf("Prec + 0:%0.5hhd \n", nb);
	ret += ft_printf("Prec + minus:%-.5hhd \n", nb);
	ret += ft_printf("size:%5hhd \n", nb);
	ret += ft_printf("size + space:% 5hhd \n", nb);
	ret += ft_printf("size + plus:%+5hhd \n", nb);
	ret += ft_printf("size + minus:%-5hhd \n", nb);
	ret += ft_printf("size + 0:%05hhd \n", nb);
	ret += ft_printf("size + 0 + plus:%+05hhd \n", nb);
	ret += ft_printf("size + 0 + plus:%0+5hhd \n", nb);
	ret += ft_printf("size + 0 + prec:%05.3hhd \n", nb);
	// ret += ft_printf("size + minus + prec:%-5.3hhd \n", nb); // manque 1 espace
	ret += ft_printf("size + plus + 0 + prec:%+05.3hhd \n", nb);
	ret += ft_printf("size + espace + zero + prec:%0 5.3hhd \n", nb);
	ret += ft_printf("size + espace + zero + prec:% 05.3hhd \n", nb);
	// ret += ft_printf("size + minus + plus + prec:%-+5.3hhd \n", nb); // manque 1 espace
	printf("res mine : %d\n\n\n", ret);

	ret = 0;
	// ret += printf("space% hhd \n", nb);
	ret += printf("plus:%+hhd \n", nb);
	ret += printf("precision:%.5hhd \n", nb);
	// ret += printf("space + prec:% .5hhd \n", nb);
	ret += printf("Plus + prec / grande:%+.5hhd \n", nb);
	ret += printf("Prec + 0:%0.5hhd \n", nb);
	ret += printf("Prec + minus:%-.5hhd \n", nb);
	ret += printf("size:%5hhd \n", nb);
	ret += printf("size + space:% 5hhd \n", nb);
	ret += printf("size + plus:%+5hhd \n", nb);
	ret += printf("size + minus:%-5hhd \n", nb);
	ret += printf("size + 0:%05hhd \n", nb);
	ret += printf("size + 0 + plus:%+05hhd \n", nb);
	ret += printf("size + 0 + plus:%0+5hhd \n", nb);
	ret += printf("size + 0 + prec:%05.3hhd \n", nb);
	// ret += printf("size + minus + prec:%-5.3hhd \n", nb);
	ret += printf("size + plus + 0 + prec:%+05.3hhd \n", nb);
	ret += printf("size + espace + zero + prec:%0 5.3hhd \n", nb);
	ret += printf("size + espace + zero + prec:% 05.3hhd \n", nb);
	// ret += printf("size + minus + plus + prec:%-+5.3hhd \n", nb);
	printf("res syst : %d\n\n\n", ret);

	return (0);
}

			// printf("space = %d\n\n\n", data.flag->space);
			// printf("zero = %d\n\n\n", data.flag->zero);
			// printf("len = %d\n\n\n", len);
