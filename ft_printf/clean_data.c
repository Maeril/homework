/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:48:05 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/08 17:52:21 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

t_data		clean_data(t_data data)
{
	if (data.c == 1)
		data.c = 0;
	if (data.s == 1)
		data.s = 0;
	if (data.p == 1)
		data.p = 0;
	if (data.d == 1)
		data.d = 0;
	if (data.i == 1)
		data.i = 0;
	if (data.o == 1)
		data.o = 0;
	if (data.u == 1)
		data.u = 0;
	if (data.x == 1)
		data.x = 0;
	if (data.X == 1)
		data.X = 0;

	return (data);
}
