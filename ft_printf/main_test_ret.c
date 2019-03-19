/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_ret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/19 16:06:09 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <stdarg.h>

int			main(void)
{
	printf("system ret value = %d\n", printf("res syst: %.0x %.x\n", 4, 0));
	printf("my ret value = %d\n", ft_printf("res mine: %.0x %.x\n", 4, 0));

	printf("test 0 simple = %d\n", 0);
	return (0);
}