/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 23:34:58 by myener            #+#    #+#             */
/*   Updated: 2019/02/18 15:48:49 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


 int			main(void)
{
 	// // width et sharp
 	// printf("%#10.5o\n", 7);
 	// ft_printf("%#10.5o\n", 7);

 	printf("String simple s:\n");
 	ft_printf("%s\n", "bjr");
 	printf("%s\n", "bjr");
	printf("-------------------------\n\n");

	printf("Decimal simple d:\n");
 	ft_printf("%d\n", 24);
 	printf("%d\n", 24);
	printf("-------------------------\n\n");

 	// printf("Sharp # et precision:\n");
 	// ft_printf("%#.2o\n", 987);
 	// printf("%#.2o\n", 987);
	// printf("-------------------------\n\n");

 	// printf("Sharp # simple:\n");
 	// ft_printf("%#o\n", 100);
 	// printf("%#o\n", 100);
	// printf("-------------------------\n\n");

	// printf("Minus Precision Width:\n");
	// ft_printf("%-10.5o\n", 55);
	// printf("%-10.5o\n", 55);

 	// printf("Octal Precision && Width:\n");
 	// ft_printf("%10.5o\n", 55);
 	// printf("%10.5o\n", 55);
	// printf("-------------------------\n\n");

 	// printf("Octal Width:\n");
 	// ft_printf("%5o\n", 36);
 	// printf("%5o\n", 36);
	// printf("-------------------------\n\n");

 	// printf("Octal Precision:\n");
 	// ft_printf("%.5o\n", 36);
 	// printf("%.5o\n", 36);
	// printf("-------------------------\n\n");

 	// printf("Octal Basique:\n");
 	// ft_printf("%o\n", 500);
 	// printf("%o\n", 500);

 	return (0);
 }