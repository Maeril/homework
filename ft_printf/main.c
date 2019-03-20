/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/20 18:53:45 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>

int			main(void)
{
	long		nb;
	nb = 5643256546946846;
	ft_printf("##MINE = space% ld \n", nb);
	ft_printf("##MINE = plus:%+ld \n", nb);
	ft_printf("##MINE = precision:%.5ld \n", nb);
	ft_printf("##MINE = space + prec:% .5ld \n", nb);
	ft_printf("##MINE = Plus + prec / grande:%+.5ld \n", nb);
	ft_printf("##MINE = Prec + 0:%0.5ld \n", nb);
	ft_printf("##MINE = Prec + minus:%-.5ld \n", nb);
	ft_printf("##MINE = size:%5ld \n", nb);
	ft_printf("##MINE = size + space:% 5ld \n", nb);
	ft_printf("##MINE = size + plus:%+5ld \n", nb);
	ft_printf("##MINE = size + minus:%-5ld \n", nb);
	ft_printf("##MINE = size + 0:%05ld \n", nb);
	ft_printf("##MINE = size + 0 + plus:%+05ld \n", nb);
	ft_printf("##MINE = size + 0 + plus:%0+5ld \n", nb);
	ft_printf("##MINE = size + 0 + prec:%05.3ld \n", nb);
	ft_printf("##MINE = size + minus + prec:%-5.3ld \n", nb);
	ft_printf("##MINE = size + plus + 0 + prec:%+05.3ld \n", nb);
	ft_printf("##MINE = size + espace + zero + prec:%0 5.3ld \n", nb);
	ft_printf("##MINE = size + espace + zero + prec:% 05.3ld \n", nb);
	ft_printf("##MINE = size + minus + plus + prec:%-+5.3ld \n\n\n", nb);

	printf("SYSTEM = space% ld \n", nb);
	printf("SYSTEM = plus:%+ld \n", nb);
	printf("SYSTEM = precision:%.5ld \n", nb);
	printf("SYSTEM = space + prec:% .5ld \n", nb);
	printf("SYSTEM = Plus + prec / grande:%+.5ld \n", nb);
	printf("SYSTEM = Prec + 0:%0.5ld \n", nb);
	printf("SYSTEM = Prec + minus:%-.5ld \n", nb);
	printf("SYSTEM = size:%5ld \n", nb);
	printf("SYSTEM = size + space:% 5ld \n", nb);
	printf("SYSTEM = size + plus:%+5ld \n", nb);
	printf("SYSTEM = size + minus:%-5ld \n", nb);
	printf("SYSTEM = size + 0:%05ld \n", nb);
	printf("SYSTEM = size + 0 + plus:%+05ld \n", nb);
	printf("SYSTEM = size + 0 + plus:%0+5ld \n", nb);
	printf("SYSTEM = size + 0 + prec:%05.3ld \n", nb);
	printf("SYSTEM = size + minus + prec:%-5.3ld \n", nb);
	printf("SYSTEM = size + plus + 0 + prec:%+05.3ld \n", nb);
	printf("SYSTEM = size + espace + zero + prec:%0 5.3ld \n", nb);
	printf("SYSTEM = size + espace + zero + prec:% 05.3ld \n", nb);
	printf("SYSTEM = size + minus + plus + prec:%-+5.3ld \n", nb);
	return (0);
}

			// printf("space = %d\n\n", data.flag->space);
			// printf("zero = %d\n\n", data.flag->zero);
			// printf("len = %d\n\n", len);
