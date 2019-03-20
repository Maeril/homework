/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/20 18:38:11 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>

int			main(void)
{
	int		nb = 0;

	ft_printf("##MINE = space% d\n", nb);
    ft_printf("##MINE = plus:%+d\n", nb);
    ft_printf("##MINE = precision:%.5d\n", nb);
    ft_printf("##MINE = space + prec:% .5d\n", nb);
    ft_printf("##MINE = Plus + prec / grande:%+.5d\n", nb);
    ft_printf("##MINE = Plus + prec / petite:%+.0d\n", nb);
    ft_printf("##MINE = Prec + 0:%0.5d\n", nb);
    ft_printf("##MINE = Prec + minus:%-.5d\n", nb);
    ft_printf("##MINE = size:%5d\n", nb);
    ft_printf("##MINE = size + space:% 5d\n", nb);
    ft_printf("##MINE = size + plus:%+5d\n", nb);
    ft_printf("##MINE = size + minus:%-5d\n", nb);
    ft_printf("##MINE = size + 0:%05d\n", nb);
    ft_printf("##MINE = size + 0 + plus:%+05d\n", nb);
    ft_printf("##MINE = size + 0 + plus:%0+5d\n", nb);
    ft_printf("##MINE = size + 0 + prec:%05.3d\n", nb);
    ft_printf("##MINE = size + minus + prec:%-5.3d\n", nb);
    ft_printf("##MINE = size + plus + 0 + prec:%+05.3d\n", nb);
    ft_printf("##MINE = size + espace + zero + prec:%0 5.3d\n", nb);
    ft_printf("##MINE = size + espace + zero + prec:% 05.3d\n", nb);
    ft_printf("##MINE = size + minus + plus + prec:%-+5.3d\n\n", nb);

    printf("SYSTEM = space% d\n", nb);
    printf("SYSTEM = plus:%+d\n", nb);
    printf("SYSTEM = precision:%.5d\n", nb);
    printf("SYSTEM = space + prec:% .5d\n", nb);
    printf("SYSTEM = Plus + prec / grande:%+.5d\n", nb);
    printf("SYSTEM = Plus + prec / petite:%+.0d\n", nb);
    printf("SYSTEM = Prec + 0:%0.5d\n", nb);
    printf("SYSTEM = Prec + minus:%-.5d\n", nb);
    printf("SYSTEM = size:%5d\n", nb);
    printf("SYSTEM = size + space:% 5d\n", nb);
    printf("SYSTEM = size + plus:%+5d\n", nb);
    printf("SYSTEM = size + minus:%-5d\n", nb);
    printf("SYSTEM = size + 0:%05d\n", nb);
    printf("SYSTEM = size + 0 + plus:%+05d\n", nb);
    printf("SYSTEM = size + 0 + plus:%0+5d\n", nb);
    printf("SYSTEM = size + 0 + prec:%05.3d\n", nb);
    printf("SYSTEM = size + minus + prec:%-5.3d\n", nb);
    printf("SYSTEM = size + plus + 0 + prec:%+05.3d\n", nb);
    printf("SYSTEM = size + espace + zero + prec:%0 5.3d\n", nb);
    printf("SYSTEM = size + espace + zero + prec:% 05.3d\n", nb);
    printf("SYSTEM = size + minus + plus + prec:%-+5.3d\n", nb);

	nb = -45;

    ft_printf("##MINE = space% d\n", nb);
    ft_printf("##MINE = plus:%+d\n", nb);
    ft_printf("##MINE = precision:%.5d\n", nb);
    ft_printf("##MINE = space + prec:% .5d\n", nb);
    ft_printf("##MINE = Plus + prec / grande:%+.5d\n", nb);
    ft_printf("##MINE = Plus + prec / petite:%+.0d\n", nb);
    ft_printf("##MINE = Prec + 0:%0.5d\n", nb);
    ft_printf("##MINE = Prec + minus:%-.5d\n", nb);
    ft_printf("##MINE = size:%5d\n", nb);
    ft_printf("##MINE = size + space:% 5d\n", nb);
    ft_printf("##MINE = size + plus:%+5d\n", nb);
    ft_printf("##MINE = size + minus:%-5d\n", nb);
    ft_printf("##MINE = size + 0:%05d\n", nb);
    ft_printf("##MINE = size + 0 + plus:%+05d\n", nb);
    ft_printf("##MINE = size + 0 + plus:%0+5d\n", nb);
    ft_printf("##MINE = size + 0 + prec:%05.3d\n", nb);
    ft_printf("##MINE = size + minus + prec:%-5.3d\n", nb);
    ft_printf("##MINE = size + plus + 0 + prec:%+05.3d\n", nb);
    ft_printf("##MINE = size + espace + zero + prec:%0 5.3d\n", nb);
    ft_printf("##MINE = size + espace + zero + prec:% 05.3d\n", nb);
    ft_printf("##MINE = size + minus + plus + prec:%-+5.3d\n\n", nb);

    printf("SYSTEM = space% d\n", nb);
    printf("SYSTEM = plus:%+d\n", nb);
    printf("SYSTEM = precision:%.5d\n", nb);
    printf("SYSTEM = space + prec:% .5d\n", nb);
    printf("SYSTEM = Plus + prec / grande:%+.5d\n", nb);
    printf("SYSTEM = Plus + prec / petite:%+.0d\n", nb);
    printf("SYSTEM = Prec + 0:%0.5d\n", nb);
    printf("SYSTEM = Prec + minus:%-.5d\n", nb);
    printf("SYSTEM = size:%5d\n", nb);
    printf("SYSTEM = size + space:% 5d\n", nb);
    printf("SYSTEM = size + plus:%+5d\n", nb);
    printf("SYSTEM = size + minus:%-5d\n", nb);
    printf("SYSTEM = size + 0:%05d\n", nb);
    printf("SYSTEM = size + 0 + plus:%+05d\n", nb);
    printf("SYSTEM = size + 0 + plus:%0+5d\n", nb);
    printf("SYSTEM = size + 0 + prec:%05.3d\n", nb);
    printf("SYSTEM = size + minus + prec:%-5.3d\n", nb);
    printf("SYSTEM = size + plus + 0 + prec:%+05.3d\n", nb);
    printf("SYSTEM = size + espace + zero + prec:%0 5.3d\n", nb);
    printf("SYSTEM = size + espace + zero + prec:% 05.3d\n", nb);
    printf("SYSTEM = size + minus + plus + prec:%-+5.3d\n", nb);

	return (0);
}

			// printf("space = %d\n", data.flag->space);
			// printf("zero = %d\n", data.flag->zero);
			// printf("len = %d\n", len);
