/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/25 18:16:08 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>

int			main(void)
{
	// int		nb;
	int			ret1 = 0;
	int			ret2 = 0;

	ret1 += ft_printf("MINE: %%\n");
	ret1 += ft_printf("MINE: %%%%%d\n", -120);

	ret2 += printf("SYST: %%\n");
	ret2 += printf("SYST: %%%%%d\n", -120);

	printf("\nres mine : %d\n", ret1);
	printf("res syst : %d\n\n", ret2);

	return (0);
}

			// printf("space = %d\n\n\n", data.flag->space);
			// printf("zero = %d\n\n\n", data.flag->zero);
			// printf("len = %d\n\n\n", len);