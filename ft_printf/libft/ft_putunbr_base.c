/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:41:32 by myener            #+#    #+#             */
/*   Updated: 2019/03/17 23:01:41 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putunbr_base(unsigned long long int nb, const char *base)
{
	unsigned int	bl;

	bl = ft_strlen(base);
	if (nb >= bl)
		ft_putunbr_base((nb / bl), base);
	ft_putchar(base[(nb % bl)]);
}
