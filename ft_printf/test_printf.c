/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:55:27 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 17:42:00 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			main(void)
{
	printf("essai numero %5.6d\n", 1);
	printf("essai numero %5.......6d\n", 1);
/* warning : conversion invalide, se comportent comme si 5.6 */
	printf("%010.2d\n", 1);
	printf("%03.10d\n", 1);
	printf("%05.10d\n", 1);
	printf("%05.2d\n", 1);
	printf("%5.2d\n", 1);
	printf("% s\n", "aa");
	printf("% c\n", 'a');
	printf("% o\n", 2);
	printf("% u\n", 2);
	printf("% x\n", 2);
	printf("% X\n", 2);
	printf("s = %05s\n", "aa");
	printf("c = %05c\n", 'a');
	return (0);
}
