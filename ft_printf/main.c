/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/02/17 21:38:18 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


 int			main(void)
{
 	// // width et sharp
 	// printf("%#10.5o\n", 7);
 	// ft_printf("%#10.5o\n", 7);

 	// width et sharp
 	printf("%s\n", "bjr");
 	ft_printf("%s\n", "bjr");

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

//  	// // Octal Basique
//  	ft_printf("%o\n", 500);
//  	printf("%o\n", 500);

//  	ft_printf("%5.o\n", 9);
//  	printf("%#5.o\n", 9);

// 	// ft_printf("%.9c", 'b'); undefined !!
// 	// printf("%.9c", 'b');

//  	return (0);
 }