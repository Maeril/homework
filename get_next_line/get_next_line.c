/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:14:37 by myener            #+#    #+#             */
/*   Updated: 2018/12/04 17:48:30 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     		get_next_line(const int fd, char **line)
{
	size_t			i;
	char			buffer[BUFF_SIZE];
	static char*	stock;


	if (fd == -1 || !line || !BUFF_SIZE)
		return (-1);
	i = 0;
	stock = ft_strdup("");
	while ((read(fd, buffer, BUFF_SIZE)) && !(ft_strchr(stock, '\n')))
	{
		stock = ft_strjoin(stock, buffer);
	}
	while (stock[i] != '\n')
		i++;
	*line = ft_strndup(stock, i);
	printf("[%s]", stock);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (argv[1])
	{
	get_next_line(fd, &line);
	printf("%s\n", line);
	}
	return (0);
}