/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:48:05 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/12 16:32:29 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data		clean_data(t_data data)
{
		data.unsign = 0;
		data.minus = 0;
		data.plus = 0;
		data.zero = 0;
		data.space = 0;
		data.width = 0;
		data.precision = 0;
		data.h = 0;
		data.ll = 0;
		data.l = 0;
		data.hh = 0;
		data.c = 0;
		data.s = 0;
		data.p = 0;
		data.d = 0;
		data.i = 0;
		data.o = 0;
		data.u = 0;
		data.x = 0;
		data.big_x = 0;
		data.integer = 0;
		data.str = 0;
		data.car = 0;
		data.unint = 0;
		data.signcar = 0;
		data.sh = 0;
		data.lg = 0;
		data.lglg = 0;
		data.unsigncar = 0;
		data.unsignsh = 0;
		data.unsignlg = 0;
		data.unsignlglg = 0;

	return (data);
}

