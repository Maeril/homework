/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:32:32 by myener            #+#    #+#             */
/*   Updated: 2019/05/27 20:54:55 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(unsigned int nb)
{
	int i;

	if (nb == 1)
		printf("1");
	i = 2;
	while (nb >= i)
	{
		if ((nb % i) == 0)
		{
			printf("%d", i);
			nb /= i;
			if (i != nb)
				printf("*");
			i--;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	fprime(atoi(av[1]));
}