/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:44:14 by myener            #+#    #+#             */
/*   Updated: 2019/02/22 21:41:15 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hexlen(unsigned long long int n)
{
	int	e;

	e = 1;
	while ((n / 16) > 0)
	{
		n /= 16;
		e++;
	}
	return (e);
}
