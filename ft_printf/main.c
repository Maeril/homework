/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/04/08 20:52:49 by myener           ###   ########.fr       */
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

	return (0);
}
