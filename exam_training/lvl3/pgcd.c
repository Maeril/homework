/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:54:25 by myener            #+#    #+#             */
/*   Updated: 2019/04/15 23:13:37 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int		ft_abs(int nb)
{
	return(nb < 0 ? -nb : nb);
}

void	ft_putnbr(int nb)
{
	unsigned int b;
	b = 0;
	if(nb < 0)
	{
		b = -nb;
		ft_putchar('-');
	}
	else
		b = nb;
	if (b >= 10)
		{
			ft_putnbr(b / 10);
			ft_putchar(b % 10 + '0');
		}
	else if (b < 10)
		ft_putchar(b + '0');
}

void	pgcd(const char *str1, const char *str2)
{
	int		s1;
	int		s2;
	int		stk;

	s1 = atoi(str1);
	s2 = atoi(str2);
	while ((s1 % s2) != 0)
	{
		stk = s1 % s2;
		s1 = s2;
		s2 = stk;
	}
	ft_putnbr(s2);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(argv[1], argv[2]);
	return (0);
}
