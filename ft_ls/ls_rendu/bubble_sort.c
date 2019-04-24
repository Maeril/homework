/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:52:32 by myener            #+#    #+#             */
/*   Updated: 2019/04/24 20:11:51 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	bubble_sort(int *list)
{
	int	h;
	int	i;
	int tmp;

	h = 0;
	while (h < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (list[i] > list[i + 1])
			{
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
			i++;
		}
		h++;
	}
}


int		main(int argc, char **argv)
{
	int		i = 0;
	int		list[10] = {1, 5, 3, 10, 6, 8, 9, 7, 4, 2};

	bubble_sort(list);
	while (i < 10)
	{
		printf("%d ", list[i]);
		i++;
	}
	printf("\n");
	return (0);
}