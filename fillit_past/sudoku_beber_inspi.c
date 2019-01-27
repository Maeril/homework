/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_beber_inspi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:15:55 by lbenard           #+#    #+#             */
/*   Updated: 2019/01/16 16:34:03 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_solver.h"
#include "ft_strutils.h"
#include "check.h"
#include "grid.h"
#include <stdlib.h>

/*
** `int solve(int x, int y)`:
** Solves the grid using a recursive technique,
** returns 1 if the grid is finished, or 0 if we need
** to backtrack (as determined by `possible_digits_at_pos(int x, int y)`)
*/

int	solve(int x, int y)
{
	int		is_constant;
	char	*valid_digits;

	is_constant = ft_isdigit(g_grid[y][x]);
	valid_digits = possible_digits_at_pos(x, y);
	while (*valid_digits || is_constant)
	{
		if (!is_constant)
			g_grid[y][x] = *valid_digits;
		if (x == 8 && y == 8)
		{
			free(valid_digits);
			return (1);
		}
		if (solve((x + 1) % 9, y + ((x + 1 > 8) ? 1 : 0)) == 1)
			return (1);
		if (!(*(++valid_digits)))
		{
			if (!is_constant)
				g_grid[y][x] = '.';
			return (0);
		}
	}
	free(valid_digits);
	return (0);
}