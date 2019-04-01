/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/04/01 17:39:34 by myener           ###   ########.fr       */
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

    nb = 1.0/0.0;
	// ret1 += ft_printf("MINE = %f\n", nb);
	ret2 += printf("SYST = %f\n", nb);
	// ret1 += ft_printf("MINE = %12f\n", nb);
	ret2 += printf("SYST = %12f\n", nb);
	// ret1 += ft_printf("MINE = %-12f\n", nb);
	ret2 += printf("SYST = %-12f\n", nb);
	// ret1 += ft_printf("MINE = %5.9f\n", nb);
	ret2 += printf("SYST = %5.9f\n", nb);

    nb = -1.0/0.0;
	// ret1 += ft_printf("MINE = %f\n", nb);
	ret2 += printf("SYST = %f\n", nb);
	// ret1 += ft_printf("MINE = %12f\n", nb);
	ret2 += printf("SYST = %12f\n", nb);
	// ret1 += ft_printf("MINE = %-12f\n", nb);
	ret2 += printf("SYST = %-12f\n", nb);
	// ret1 += ft_printf("MINE = %5.9f\n", nb);
	ret2 += printf("SYST = %5.9f\n", nb);

	nb = 0.0/0.0;
	// ret1 += ft_printf("MINE = %f\n", nb);
	ret2 += printf("SYST = %f\n", nb);
	// ret1 += ft_printf("MINE = %12f\n", nb);
	ret2 += printf("SYST = %12f\n", nb);
	// ret1 += ft_printf("MINE = %-12f\n", nb);
	ret2 += printf("SYST = %-12f\n", nb);
	// ret1 += ft_printf("MINE = %5.9f\n", nb);
	ret2 += printf("SYST = %5.9f\n", nb);

	printf("res mine : %d\n", ret1);
	printf("res syst : %d\n\n", ret2);

	return (0);
}