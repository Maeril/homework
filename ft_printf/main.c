/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/04 23:31:24 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <float.h>

 int			main(void)
{
 	// // String simple s
 	// printf("syst: %10s\n", "hello");
 	// ft_printf("mine: %10s\n\n", "hello");

	// // Char simple c
 	// printf("syst: %c\n", 'o');
 	// ft_printf("mine: %c\n\n", 'o');

	// // String simple s
 	// printf("syst: %s\n", "un autre test");
 	// ft_printf("mine: %s\n\n", "un autre test");

	// // Int simple d
 	// printf("syst: %d\n", 1056);
 	// ft_printf("mine: %d\n\n", 1056);

	// // Int simple i
 	// printf("syst: %i\n", 1056);
 	// ft_printf("mine: %i\n\n", 1056);

 	// // Octal simple o
 	// printf("syst: %o\n", 8);
	// ft_printf("mine: %o\n\n", 8);

	// // Hexl simple x
 	// printf("syst: %x\n", 10);
	// ft_printf("mine: %x\n\n", 10);

 	// // Hexu simple X
 	// printf("syst: %X\n", 10);
	// ft_printf("mine: %X\n\n", 10);

	// // Unsign simple u
	// printf("syst: %u\n", -42);
	// ft_printf("mine: %u\n\n", -42);

	// Ptr simple p !
	printf("Pointers simples (p)) :\n\n");
	printf("syst: %p\n", "test");
	ft_printf("mine: %p\n\n", "test");

	// // Pourcentage simple %
	// printf("syst: %8%\n");
	// ft_printf("mine: %8%\n\n");

	// // Width simple c
 	// printf("syst: %5c\n", 'h');
 	// ft_printf("mine: %5c\n\n", 'h');

	// // Width & minus
	// printf("syst: %-5c\n", 'x');
 	// ft_printf("mine: %-5c\n\n", 'x');

	// // Width, minus & zero (minus override zero)
	// printf("syst: %-05c\n", 'G');
 	// ft_printf("mine: %-05c\n\n", 'G');

	// // Width simple s
 	// printf("syst: %10s\n", "bjr");
 	// ft_printf("mine: %10s\n\n", "bjr");

	// // Width simple X
 	// printf("syst: %10X\n", 10);
 	// ft_printf("mine: %10X\n\n", 10);

	// // Width simple o
 	// printf("syst: %#8o\n", 8);
 	// ft_printf("mine: %#8o\n\n", 8);

	// // Float simple f
 	// printf("syst: %f\n", 3.295);
 	// ft_printf("mine: %f\n\n", 3.295);

	// // Test printf f;
	// printf("syst: ABC %5f DEF\n", 3.295);
	// ft_printf("mine: ABC %5f DEF\n\n", 3.295);

	// // Int d & Plus
 	// printf("syst: %5d\n", 36);
 	// ft_printf("mine: %5d\n\n", 36);

	// // Int i & Plus
 	// printf("syst: %5i\n", 36);
 	// ft_printf("mine: %5i\n\n", 36);

	// // Octal & Precision
 	// printf("syst: %#5o\n", 36);
 	// ft_printf("mine: %#5o\n\n", 36);

	// // Unsign & Precision
 	// printf("syst: %.5u\n",-42);
 	// ft_printf("mine: %.5u\n\n", -42);

	// // Hexl & Precision
 	// printf("syst: %05x\n", 10);
 	// ft_printf("mine: %05x\n\n", 10);

	// // Hexu & Precision
 	// printf("syst: %05X\n", 10);
 	// ft_printf("mine: %05X\n\n", 10);

	 // Float & Plus !
	printf("Float et Precision (10f) :\n\n");
 	printf("syst: % 10f\n", 10.5);
 	ft_printf("mine: % 10f\n\n", 10.5);

	// Str & Precision !
	printf("Str et Precision (.6s) :\n\n");
 	printf("syst: %.6s\n", "bonjour");
 	ft_printf("mine: %.6s\n\n", "bonjour");

	// Sharp & precision
 	printf("syst: %.9f\n", 2.295);
 	ft_printf("mine: %.9f\n\n", 2.295);

	// Width & plus
	printf("syst: %+d\n", 74);
 	ft_printf("mine: %+d\n\n", 74);

	// Sharp simple #
 	printf("syst: %#o\n", 100);
 	ft_printf("mine: %#o\n\n", 100);

	// Width et sharp !
	printf("Hexl Width Precision et Sharp (#10.5o) :\n\n");
 	printf("syst: %#10.5x\n", 10);
 	ft_printf("mine: %#10.5x\n\n", 10);

 	// Octal Minus Precision & Width
	printf("Hexl Width Precision et Minus (#10.5o) :\n\n");
	printf("syst: %-10.5x\n", 55);
 	ft_printf("mine: %-10.5x\n\n", 55);

 	// Octal Precision & Width !
	printf("Octal Precision et Width (10.5o) :\n\n");
 	printf("syst: %10.5o\n", 55);
 	ft_printf("mine: %10.5o\n\n", 55);

 	// Octal & Width !
	printf("Octal et Width (5o) :\n\n");
 	printf("syst: %15o\n", 36);
 	ft_printf("mine: %15o\n\n", 36);

	// Octal & Precision II
	printf("Octal Sharp Width et Precision (#5.o) :\n\n");
 	printf("syst: %#5.o\n", 9);
 	ft_printf("mine: %#5.o\n\n", 9);

	return (0);
 }