/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/26 16:36:39 by myener           ###   ########.fr       */
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

	int			nb = 12;
	ret1 += ft_printf("%llx\n", nb);
	ret1 += ft_printf("test X:%llx\n", nb);
	ret1 += ft_printf("Hash:%#llx\n", nb);
	ret1 += ft_printf("prec / grande:%.5llx\n", nb);
	ret1 += ft_printf("hash + prec / grande:%#.5llx\n", nb);
	ret1 += ft_printf("hash + prec / petite:%#.1llx\n", nb);
	ret1 += ft_printf("prec + 0: %0.5llx\n", nb);
	ret1 += ft_printf("Prec + minus:%-.5llx\n", nb);
	ret1 += ft_printf("size:%5llx\n", nb);
	ret1 += ft_printf("size + prec:%7.3llx\n", nb);
	ret1 += ft_printf("size + mminus:%-5llx\n", nb);
	ret1 += ft_printf("size + 0:%05llx\n", nb);
	ret1 += ft_printf("size + 0 + hash:%#05llx\n", nb);
	ret1 += ft_printf("size + 0 + prec:%05.3llx\n", nb);
	ret1 += ft_printf("size + minus + prec:%-5.3llx\n", nb);
	ret1 += ft_printf("size + hash + 0 + prec:%#05.3llx\n", nb);
	ret1 += ft_printf("size + hash + 0 + prec:%0#5.3llx\n", nb);
	ret1 += ft_printf("size + hash + minus + prec:%-#7.3llx\n\n", nb);

	ret2 += printf("%llx\n", nb);
	ret2 += printf("test X:%llx\n", nb);
	ret2 += printf("Hash:%#llx\n", nb);
	ret2 += printf("prec / grande:%.5llx\n", nb);
	ret2 += printf("hash + prec / grande:%#.5llx\n", nb);
	ret2 += printf("hash + prec / petite:%#.1llx\n", nb);
	ret2 += printf("prec + 0: %0.5llx\n", nb);
	ret2 += printf("Prec + minus:%-.5llx\n", nb);
	ret2 += printf("size:%5llx\n", nb);
	ret2 += printf("size + prec:%7.3llx\n", nb);
	ret2 += printf("size + mminus:%-5llx\n", nb);
	ret2 += printf("size + 0:%05llx\n", nb);
	ret2 += printf("size + 0 + hash:%#05llx\n", nb);
	ret2 += printf("size + 0 + prec:%05.3llx\n", nb);
	ret2 += printf("size + minus + prec:%-5.3llx\n", nb);
	ret2 += printf("size + hash + 0 + prec:%#05.3llx\n", nb);
	ret2 += printf("size + hash + 0 + prec:%0#5.3llx\n", nb);
	ret2 += printf("size + hash + minus + prec:%-#7.3llx\n\n", nb);

	printf("res mine : %d\n", ret1);
	printf("res syst : %d\n\n", ret2);

	return (0);
}