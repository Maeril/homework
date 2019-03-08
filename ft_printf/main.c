/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/08 15:24:48 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <float.h>

 int			main(void)
{
	// printf("Int simple (d)) :\n\n");
 	// printf("syst: %d\n", 1056);
 	// ft_printf("mine: %d\n\n", 1056);

	// printf("Int simple (i)) :\n\n");
 	// printf("syst: %i\n", 1056);
 	// ft_printf("mine: %i\n\n", 1056);

	// printf("Int Width et Precision (5.2d) :\n\n");
 	// printf("syst: %5.25d\n", 36);
 	// ft_printf("mine: %5.25d\n\n", 36);

	// printf("Int et Width et Espace ( 5i) :\n\n");
 	// printf("syst: % 5i\n", 36);
 	// ft_printf("mine: % 5i\n\n", 36);

	// printf("Int et Plus (+d) :\n\n");
	// printf("syst: %+d\n", 74);
 	// ft_printf("mine: %+d\n\n", 74);

	// printf("Unsign simple (u)) :\n\n");
	// printf("syst: %30.5u\n", -42);
	// ft_printf("mine: %30.5u\n\n", -42);

	// printf("Unsign et Precision (.5u) :\n\n");
 	// printf("syst: %10.50u\n",-42);
 	// ft_printf("mine: %10.50u\n\n", -42);

	printf("Pourcentage et Width (8) :\n\n");
	printf("syst: %8%\n");
	ft_printf("mine: %8%\n\n");

	printf("Pourcentage Precision et Width (8) :\n\n");
	printf("syst: %1.10%\n");
	ft_printf("mine: %1.10%\n\n");

	printf("Pourcentage et Precision (8) :\n\n");
	printf("syst: %-%\n");
	ft_printf("mine: %-%\n\n");

	// printf("Float simple (f) :\n\n");
 	// printf("syst: %f\n", 3.295);
 	// ft_printf("mine: %f\n\n", 3.295);

	// printf("Float Width et Espace ( 10f) :\n\n");
 	// printf("syst: % 10f\n", 10.5);
 	// ft_printf("mine: % 10f\n\n", 10.5);

	// printf("Float et Precision (.9f) :\n\n");
 	// printf("syst: %.9f\n", 2.295);
 	// ft_printf("mine: %.9f\n\n", 2.295);

	// printf("Float et Width (5f) :\n\n");
	// printf("syst: ABC %5f DEF\n", 3.295);
	// ft_printf("mine: ABC %5f DEF\n\n", 3.295);

	// printf("Hexu simple (X)) :\n\n");
 	// printf("syst: %X\n", 10);
	// ft_printf("mine: %X\n\n", 10);

	// printf("Hexu Width et Zero (05X) :\n\n");
 	// printf("syst: %#05.2X\n", 10);
 	// ft_printf("mine: %#05.2X\n\n", 10);

	// printf("Hexu et Width (10X) :\n\n");
 	// printf("syst: %10X\n", 10);
 	// ft_printf("mine: %10X\n\n", 10);

	// printf("Hexl simple (x)) :\n\n");
 	// printf("syst: %x\n", 10);
	// ft_printf("mine: %x\n\n", 10);

	// printf("Hexl Width Precision et Sharp (#10.5x) :\n\n");
 	// printf("syst: %#10.5x\n", 10);
 	// ft_printf("mine: %#10.5x\n\n", 10);

	// printf("Hexl Width Precision et Minus (-10.5x) :\n\n");
	// printf("syst: %-10.5x\n", 55);
 	// ft_printf("mine: %-10.5x\n\n", 55);

	// printf("Hexl Width et Precision (10.5x) :\n\n");
	// printf("syst: %010.5x\n", 55);
 	// ft_printf("mine: %010.5x\n\n", 55);

	// printf("Hexl Width et Zero (05x) :\n\n");
 	// printf("syst: %05x\n", 10);
 	// ft_printf("mine: %05x\n\n", 10);

	// printf("Octal Precision et Width (10.5o) :\n\n");
 	// printf("syst: %10.5o\n", 55);
 	// ft_printf("mine: %10.5o\n\n", 55);

	// printf("Octal et Width (5o) :\n\n");
 	// printf("syst: %5o\n", 6);
 	// ft_printf("mine: %5o\n\n", 6);

	// printf("Octal simple (o)) :\n\n");
 	// printf("syst: %o\n", 8);
	// ft_printf("mine: %o\n\n", 8);

	// printf("Octal Sharp Width et Precision (#5.o) :\n\n");
 	// printf("syst: %-#5.o\n", 5);
 	// ft_printf("mine: %-#5.o\n\n", 5);

	// printf("Octal Width et Precision (5.1o) :\n\n");
 	// printf("syst: %5.1o\n", 36);
 	// ft_printf("mine: %5.1o\n\n", 36);

	// printf("Octal Sharp et Width (#8o) :\n\n");
 	// printf("syst: %#8o\n", 8);
 	// ft_printf("mine: %#8o\n\n", 8);

	return (0);
 }

// 				DONE AND GONE:				 //
/*  ______________________________________

	printf("String simple (s)) :\n\n");
 	printf("syst: %10s\n", "hello");
 	ft_printf("mine: %10s\n\n", "hello");

	printf("Char simple (c)) :\n\n");
 	printf("syst: %c\n", 'o');
 	ft_printf("mine: %c\n\n", 'o');

	printf("String simple (s)) :\n\n");
 	printf("syst: %s\n", "un autre test");
 	ft_printf("mine: %s\n\n", "un autre test");

	printf("Char et Width (5c) :\n\n");
 	printf("syst: %5c\n", 'h');
 	ft_printf("mine: %5c\n\n", 'h');

	printf("Char Width et Minus (-5c) :\n\n");
	printf("syst: %-5c\n", 'h');
 	ft_printf("mine: %-5c\n\n", 'h');

	printf("Char Zero Width et Minus (-05c) :\n\n");
	printf("syst: %010c\n", 'h');
 	ft_printf("mine: %010c\n\n", 'h');

	printf("String et Width (10s) :\n\n");
 	printf("syst: %10s\n", "bjr");
 	ft_printf("mine: %10s\n\n", "bjr");

	printf("Str et Precision (.5s) :\n\n");
 	printf("syst: %.5s\n", "bonjour");
 	ft_printf("mine: %.5s\n\n", "bonjour");

	printf("Pointeur simple (p)) :\n\n");
	printf("syst: %p\n", ptr);
	ft_printf("mine: %p\n\n", ptr);

	printf("Pointeur et Width (5c) :\n\n");
 	printf("syst: %50p\n", ptr);
 	ft_printf("mine: %50p\n\n", ptr);

	printf("Pointeur Width et Minus (-5c) :\n\n");
	printf("syst: %-55p\n", ptr);
 	ft_printf("mine: %-55p\n\n", ptr);

	printf("Pointeur Zero Width et Minus (-05c) :\n\n");
	printf("syst: %025p\n", ptr);
 	ft_printf("mine: %025p\n\n", ptr);



	 ______________________________________	*/
