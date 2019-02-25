/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/02/25 18:30:11 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


 int			main(void)
{
 	// String simple s
 	printf("syst: %s\n", "henlo");
 	ft_printf("mine: %s\n\n", "henlo");

	// Char simple c
 	printf("syst: %c\n", 'o');
 	ft_printf("mine: %c\n\n", 'o');

	// String simple s
 	printf("syst: %s\n", "un autre test");
 	ft_printf("mine: %s\n\n", "un autre test");

	// Int simple d
 	printf("syst: %d\n", 1056);
 	ft_printf("mine: %d\n\n", 1056);

	// Int simple i
 	printf("syst: %i\n", 1056);
 	ft_printf("mine: %i\n\n", 1056);

 	// Octal simple o
 	printf("syst: %o\n", 8);
	ft_printf("mine: %o\n\n", 8);

	// Hexl simple x
 	printf("syst: %x\n", 10);
	ft_printf("mine: %x\n\n", 10);

 	// Hexu simple X
 	printf("syst: %X\n", 10);
	ft_printf("mine: %X\n\n", 10);

	// Unsign simple u
	printf("syst: %u\n", -42);
	ft_printf("mine: %u\n\n", -42);

	// Ptr simple p
	printf("syst: %p\n", "test");
	ft_printf("mine: %p\n\n", "test");

	// Pourcentage simple %
	printf("syst: %%\n");
	ft_printf("mine: %%\n\n");

	// Width simple c
 	printf("syst: %5c\n", 'h');
 	ft_printf("mine: %5c\n\n", 'h');

	// Width & minus
	printf("syst: %-5c\n", 'x');
 	ft_printf("mine: %-5c\n\n", 'x');

	// Width, minus & zero (minus override zero)
	printf("syst: %-05c\n", 'G');
 	ft_printf("mine: %-05c\n\n", 'G');

	// Width simple s
 	printf("syst: %5s\n", "bonjour");
 	ft_printf("mine: %5s\n\n", "bonjour");

	// Width simple X
 	printf("syst: %10X\n", 10);
 	ft_printf("mine: %10X\n\n", 10);

	// Width & plus
	// printf("syst: %+d\n", 74);
 	// ft_printf("mine: %+5c\n\n", 'G');

	// // Sharp simple #
 	// printf("syst: %#o\n", 100);
 	// ft_printf("mine: %#o\n\n", 100);

	//  // Sharp simple #
 	// printf("syst: %#o\n", 100);
 	// ft_printf("mine: %#o\n\n", 100);

	// // Width et sharp
 	// printf("syst: %#10.5o\n", 7);
 	// ft_printf("mine: %#10.5o\n\n", 7);

	// // Sharp & precision
 	// printf("syst: %#.2o\n", 987);
 	// ft_printf("mine: %#.2o\n\n", 987);

 	// // Minus Precision & Width
 	// printf("syst: %-10.5o\n", 55);
 	// ft_printf("mine: %-10.5o\n\n", 55);

 	// // Octal Precision & Width
 	// printf("syst: %10.5o\n", 55);
 	// ft_printf("mine: %10.5o\n\n", 55);

 	// // Octal & Width
 	// printf("syst: %5o\n", 36);
 	// ft_printf("mine: %5o\n\n", 36);

 	// // Octal & Precision I
 	// printf("syst: %.5o\n", 36);
 	// ft_printf("mine: %.5o\n\n", 36);

	// // Octal & Precision II
 	// printf("syst: %#5.o\n", 9);
 	// ft_printf("mine: %5.o\n\n", 9);

	return (0);
 }