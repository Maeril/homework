/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:39:13 by myener            #+#    #+#             */
/*   Updated: 2019/03/17 23:00:58 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_uintlen(unsigned long long int n)
{
	int	e;

	e = 1;
	while ((n / 10) > 0)
	{
		n /= 10;
		e++;
	}
	return (e);
}
