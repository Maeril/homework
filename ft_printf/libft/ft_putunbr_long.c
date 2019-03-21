/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:08:08 by myener            #+#    #+#             */
/*   Updated: 2019/03/21 12:22:23 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putunbr_long(unsigned long long int nb)
{
	if (nb >= 10)
		ft_putunbr_long(nb / 10);
	ft_putchar(nb % 10 + '0');
}
