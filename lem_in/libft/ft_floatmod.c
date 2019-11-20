/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatmod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:53:47 by myener            #+#    #+#             */
/*   Updated: 2019/03/11 15:20:30 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_floatmod(float x, float y)
{
	x -= y * ft_abs(x / y);
	return ((x >= 0) ? x : (x + y));
}
