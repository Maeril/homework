/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/04/03 15:06:13 by myener           ###   ########.fr       */
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

	float		nb;
	ret1 += ft_printf("%f\n", 1235.123);
	ret2 += printf("%f\n", 1235.123);
	// ret1 += ft_printf("%-5f\n", 1235.123);
	// ret2 += printf("%-5f\n", 1235.123);

	printf("\nres mine : %d\n", ret1);
	printf("res syst : %d\n\n", ret2);

	return (0);
}
