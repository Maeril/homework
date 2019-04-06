/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/04/06 20:21:27 by myener           ###   ########.fr       */
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

	ret1 += ft_printf("%f\n", 1235.123);
	ret1 += ft_printf("%-5f\n", 1235.123);
	ret1 += ft_printf("%d\n", 1235);
	ret1 += ft_printf("%i\n", 1235);
	ret1 += ft_printf("%o\n", 1235);
	ret1 += ft_printf("%x\n", 1235);
	ret1 += ft_printf("%X\n", 1235);
	ret1 += ft_printf("%s\n", "bonjour");
	ret1 += ft_printf("%p\n", 1235);
	ret1 += ft_printf("%%\n");
	ret1 += ft_printf("%c\n", 'a');
	ret1 += ft_printf("%020d\n", 0);
	printf("\n\n");
	ret2 += printf("%f\n", 1235.123);
	ret2 += printf("%-5f\n", 1235.123);
	ret2 += printf("%d\n", 1235);
	ret2 += printf("%i\n", 1235);
	ret2 += printf("%o\n", 1235);
	ret2 += printf("%x\n", 1235);
	ret2 += printf("%X\n", 1235);
	ret2 += printf("%s\n", "bonjour");
	ret2 += printf("%p\n", 1235);
	ret2 += printf("%%\n");
	ret2 += printf("%c\n", 'a');
	ret2 += printf("%020d\n", 0);
	printf("\n\n");
	printf("ret1 = %d\n", ret1);
	printf("ret2 = %d\n", ret2);

	return (0);
}
