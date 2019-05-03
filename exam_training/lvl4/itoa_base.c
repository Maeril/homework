/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:47:30 by myener            #+#    #+#             */
/*   Updated: 2019/05/03 17:32:40 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

char	*ft_strrev(char *str)
{
	int		min;
	int		max;
	char	tmp;

	min = 0;
	max = ft_strlen(str);
	max--;
	while (min < max)
	{
		tmp = str[min];
		str[min] = str[max];
		str[max] = tmp;
		min++;
		max--;
	}
	return (str);
}

char	*ft_itoa_base(int value, int base)
{
	int		neg;
	int		i;
	char	*str;
	int		baselen;

	neg = 0;
	baselen = ft_strlen()
	if (base == 10 && value == -2147483648)
		ft_putstr("-2147483648");
	if (base == 10 && value < 0)
		neg = 1;
	str = malloc(sizeof(char) * 12 + 1);
	while ()
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("a l'endroit =	%s\n", argv[1]);
		printf("a l'envers =	%s\n", ft_strrev(argv[1]));
	}
	return (0);
}