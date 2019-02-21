/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/02/19 18:24:40 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


 int			main(void)
{
 	// // width et sharp
 	// printf("%#10.5o\n", 7);
 	// ft_printf("%#10.5o\n", 7);

 	// String simple s
 	printf("%s\n", "bj");
 	ft_printf("mine: %s\n", "bj");

	// Char simple c
 	printf("%c\n", 'o');
 	ft_printf("mine: %c\n", 'o');

	// String simple s
 	printf("%s\n", "un autre test");
 	ft_printf("mine: %s\n", "un autre test");

	// Int simple d
 	printf("%d\n", 10);
 	ft_printf("mine: %d\n", 10);

	// Int simple i
 	printf("%i\n", 10);
 	ft_printf("mine: %i\n", 10);

 	// Octal simple o
 	printf("%o\n", 500);
	ft_printf("mine: %o\n", 500);

	// Hexl simple x
 	printf("%x\n", 10);
	ft_printf("mine: %o\n", 10);

 	// Hexu simple X
 	printf("%X\n", 10);
	ft_printf("mine: %o\n", 10);

	// Unsign simple u
	printf("%u\n", 14);
	printf("%p\n", "str");

// sharp precision
//  	printf("%#.2o\n", 987);
//  	ft_printf("%#.2o\n", 987);

//  	// sharp simple
//  	printf("%#o\n", 100);
//  	ft_printf("%#o\n", 100);

//  //	Plus Precision
//  //	ft_printf("%+.6o\n", 76);
//  //	printf("%+.6o\n", 76); mis en com car provoque une erreur lors de make - si undefined on ne doit pas le gerer !!
//  	// Minus Precision Width
//  	// ft_printf("%-10.5o\n", 55);
//  	// printf("%-10.5o\n", 55);

//  	// // Octal Precision && Width
//  	ft_printf("%10.5o\n", 55);
//  	printf("%10.5o\n", 55);

//  	// // Octal Width
//  	ft_printf("%5o\n", 36);
//  	printf("%5o\n", 36);

//  	// // Octal Precision
//  	ft_printf("%.5o\n", 36);
//  	printf("%.5o\n", 36);

//  	ft_printf("%5.o\n", 9);
//  	printf("%#5.o\n", 9);

//  	return (0);
 }