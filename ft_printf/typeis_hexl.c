/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeis_hexl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:06:02 by myener            #+#    #+#             */
/*   Updated: 2019/02/19 18:38:09 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nb, const char *base)
{
	long	n;
	int		bl;

	n = nb;
	bl = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= bl)
		ft_putnbr_base((n / bl), base);
	ft_putchar(base[n % bl]);
}

void		typeis_hexl(va_list ap, t_data *data)
{
	if (data->type->x)
	{
		data->type->x = va_arg(ap, int);
		ft_putnbr_base(data->type->x, HEXL);
	}
}
