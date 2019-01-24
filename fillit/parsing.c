/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:10:30 by myener            #+#    #+#             */
/*   Updated: 2019/01/24 14:16:42 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block     *parsing_block(char tab[5][5], t_block *block_tab, char **line)
{
	int     i;
	int     j;
	int     k;
    t_block *tmp;

	i = 0;
	k = 0;
    while ((tab[i] == '.' || tab[i] == '#') && tab[i])
    {
    	while (i <= 3)
	    {

	    	j = 0;
		    while(j <= 3)
		    {
                if (tab[i][j] == '#')
                {
                    block_tab[k].x = i;
                    block_tab[k].y = j;
                    k++;
                }
                j++;
		    }
		    i++;
	    }
        tmp = block_tab;
        block_tab = block_tab->next;
        return (tmp);
    }
    return (error);
}

int counter_forme
{
    char    *tab
    while (parsing_block
    {
      c++;
    }
    return (c);
}

???   read_file(int fd)

{
    char    **line;
    get_next_line(fd, line);
    parsing_block(&line);

}

int        main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2)
    {
        ft_putstr("ERROR");
        return (-1);
    }
    fd = open(argv[1], O_RDONLY);
    read_file(fd, line);
    return (0);
}