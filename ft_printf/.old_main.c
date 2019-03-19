/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/03/19 19:13:13 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <float.h>

#include <limits.h>

 int			main(void)
{
	char	*ptr = "PTDR";

	printf("Int simple (d)) :\n\n");
 	printf("syst: %hhd\n", -105654561);
 	ft_printf("mine: %hhd\n\n", -105654561);

	printf("Int simple (i)) :\n\n");
 	printf("syst: %li\n", 105654561);
 	ft_printf("mine: %li\n\n", 105654561);

	printf("Int Width et Precision (5.2d) :\n\n");
 	printf("syst: %5.25hd\n", 36256664125);
 	ft_printf("mine: %5.25hd\n\n", 36256664125);

	printf("Int et Width et Espace ( 5i) :\n\n");
 	printf("syst: % 5hhi\n", 36256664125);
 	ft_printf("mine: % 5hhi\n\n", 36256664125);

	printf("Int et Plus (+d) :\n\n");
	printf("syst: %+hhd\n", 74564555);
 	ft_printf("mine: %+hhd\n\n", 74564555);

	printf("Unsign simple - hh CHAR (u)) :\n\n");
	printf("syst: %5.u\n", -10565456);
	ft_printf("mine: %5.u\n\n", -10565456);

	printf("Unsign et Precision - hh CHAR (.5u) :\n\n");
 	printf("syst: %10.50hhu\n",-42);
 	ft_printf("mine: %10.50hhu\n\n", -42);

	printf("Pourcentage et Width (8) :\n\n");
	printf("syst: %8%\n");
	ft_printf("mine: %8%\n\n");

	printf("Pourcentage Precision et Width (8) :\n\n");
	printf("syst: %1.10%\n");
	ft_printf("mine: %1.10%\n\n");

	printf("Pourcentage et Precision (8) :\n\n");
	printf("syst: %-%\n");
	ft_printf("mine: %-%\n\n");

	printf("\n//////////////////////////////////////////////\n\n");

	printf("Float simple (f) :\n\n");
 	printf("syst: %f\n", 3.295);
 	ft_printf("mine: %f\n\n", 3.295);

	printf("Float Width et Espace ( 10f) :\n\n");
 	printf("syst: % f\n", 10.5);
 	ft_printf("mine: % f\n\n", 10.5);

	printf("Float et Precision (.19f) :\n\n");
 	printf("syst: %.18f\n", 2.295);
 	ft_printf("mine: %.18f\n\n", 2.295);

	printf("Float et Width (25f) :\n\n");
	printf("syst: ABC %25f DEF\n", 3.295);
	ft_printf("mine: ABC %25f DEF\n\n", 3.295);

	printf("\n//////////////////////////////////////////////\n\n");

	printf("Hexu simple (X)) :\n\n");
 	printf("syst: %X\n", -1054654654564);
	ft_printf("mine: %X\n\n", -1054654654564);

	printf("Hexu Width et Zero (05X) :\n\n");
 	printf("syst: %010.5hhX\n", 554454);
 	ft_printf("mine: %010.5hhX\n\n", 554454);

	printf("Hexu et Width (10X) :\n\n");
 	printf("syst: %10X\n", 10);
 	ft_printf("mine: %10X\n\n", 10);

	printf("Hexl simple (x)) :\n\n");
 	printf("syst: %x\n", 1054654654564);
	ft_printf("mine: %x\n\n", 1054654654564);

	printf("Hexl Width Precision et Sharp - l LONG (#10.5x) :\n\n");
 	printf("syst: %#10.5lx\n", 10416534553514654651);
 	ft_printf("mine: %#10.5lx\n\n", 10416534553514654651);

	printf("Hexl Width Precision et Minus - hh CHAR (-10.5x) :\n\n");
	printf("syst: %-10.5hhx\n", 55);
 	ft_printf("mine: %-10.5hhx\n\n", 55);

	printf("Hexl Width et Precision - hh CHAR (10.5x) :\n\n");
	printf("syst: %010.5hhx\n", 554454);
 	ft_printf("mine: %010.5hhx\n\n", 554454);

	printf("Hexl Width et Zero (05x) :\n\n");
 	printf("syst: %05x\n", 10);
 	ft_printf("mine: %05x\n\n", 10);

	// printf("Octal Precision et Width (10.5o) :\n\n");
 	// printf("syst: %10.5o\n", 55);
 	// ft_printf("mine: %10.5o\n\n", 55);

	// printf("Octal et Width (5o) :\n\n");
 	// printf("syst: %5o\n", 6);
 	// ft_printf("mine: %5o\n\n", 6);

	// printf("Octal simple - ll LONG LONG (o)) :\n\n");
 	// printf("syst: %llo\n", 8);
	// ft_printf("mine: %llo\n\n", 8);

	// printf("Octal Sharp Width et Precision - h SHORT (#5.o) :\n\n");
 	// printf("syst: %-#5.ho\n", -105654561);
 	// ft_printf("mine: %-#5.ho\n\n", -105654561);

	// printf("Octal Width et Precision (5.1o) :\n\n");
 	// printf("syst: %5.1o\n", 36);
 	// ft_printf("mine: %5.1o\n\n", 36);

	// printf("Octal Sharp et Width (#8o) :\n\n");
 	// printf("syst: %#8o\n", 8);
 	// ft_printf("mine: %#8o\n\n", 8);

	// printf("\n//////////////////////////////////////////////\n\n");

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

	// return (0);
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
