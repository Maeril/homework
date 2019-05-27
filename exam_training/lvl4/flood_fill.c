/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 21:03:36 by myener            #+#    #+#             */
/*   Updated: 2019/05/27 15:59:29 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

static void	place(t_point *size, int i, int j, char c, char **tab)
{
	tab[i][j] = 'F';
	if (j + 1 < size->y)
 	    if (tab[i][j + 1] == c)
 	        place(size, i, j + 1, c, tab);
	if (i + 1 < size->x)
 	    if (tab[i + 1][j] == c)
 	        place(size, i + 1, j, c, tab);
 	if (j - 1 >= 0)
 	    if (tab[i][j - 1] == c)
 	        place(size, i, j - 1, c, tab);
 	if (i - 1 >= 0)
 	    if (tab[i - 1][j] == c)
 	        place(size, i - 1, j, c, tab);
}

void		flood_fill(char **tab, t_point size, t_point begin)
{
	char c = tab[begin.x][begin.y];

	if (c == 'F')
		return ;
	place(&size, begin.x, begin.y, c, tab);
}

// int main(void)
// {
//     char **area;
//     t_point size = { 8, 5 };
//     t_point begin = { 2, 2 };
//     char *zone[] = {
//         "11111111",
//         "10001001",
//         "10010001",
//         "10110001",
//         "11100001"
//     };
//     area = make_area(zone);
//     print_tab(area);
//     flood_fill(area, size, begin);
//     ft_putchar('\n');
//     print_tab(area);
//     return (0);
// }
