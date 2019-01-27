/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:57:02 by mribouch          #+#    #+#             */
/*   Updated: 2019/01/27 21:58:34 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"


void	ft_print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] != 0)
	{
		ft_putstr(map[j++]);
		ft_putchar('\n');
	}
}

int	ft_get_map_size(char *str)
{
	int	res;

	res = ft_sqrt_fillit(ft_num_tetri(str) * 4);
	return (res);
}


char	**ft_create_map(int nbt, char *str)
{
	int		size_m;
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	size_m = ft_get_map_size(str);
	if (!(map = malloc(sizeof(char *) * (size_m + 1))))
		return (0);
	while (i <= size_m)
		if (!(map[i++] = malloc(sizeof(char) * (size_m + 1))))
			return (0);
	i = 0;
	while (j <= size_m)
	{
		while (i < size_m)
			map[j][i++] = '.';
		map[j][i] = '\0';
		i = 0;
		j++;
	}
	map[j] = 0;
	return (map);
}

int	main(void)
{
	char	*str;
	int		i;
	int		j;
	i = 0;
	j = 0;
	str = ft_strnew(19);
	str = "##..\n##..\n....\n....\n\n#...\n#...\n#...\n#...\n\n..##\n.##.\n....\n....\n\n....\n....\n....\n....\n\n....\n....\n....\n....\n";
	ft_create_map(ft_get_map_size(str), str);
	ft_print_map(ft_create_map(ft_get_map_size(str), str));
	ft_putnbr(ft_get_map_size(str));
	return (0);
}
