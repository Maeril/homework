/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/04/05 17:59:17 by myener           ###   ########.fr       */
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

	// ft_printf("%f\n", 1235.123);
	// ft_printf("%-5f\n", 1235.123);
	// ft_printf("%d\n", 1235);
	// ft_printf("%i\n", 1235);
	// ft_printf("%o\n", 1235);
	// ft_printf("%x\n", 1235);
	// ft_printf("%X\n", 1235);
	// ft_printf("%s\n", "bonjour");
	// ft_printf("%p\n", 1235);
	// ft_printf("%%\n");
	// ft_printf("%c\n", 'a');
	ret1 += ft_printf("%f %020d\n", 123.123, 0);
	ret2 += printf("%f %020d\n", 123.123, 0);

	printf("ret1 = %d\n", ret1);
	printf("ret2 = %d\n", ret2);

	return (0);
}
