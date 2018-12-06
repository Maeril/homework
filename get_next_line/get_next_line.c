/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:14:37 by myener            #+#    #+#             */
/*   Updated: 2018/12/06 12:31:18 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	size_t			i;
	int				readsize;
	char			buffer[BUFF_SIZE];
	static char		*stock;

	if (fd == -1 || !line || !BUFF_SIZE)
		return (-1);
	i = 0;
	if (!stock)
		stock = ft_strdup("");
	while ((readsize = read(fd, buffer, BUFF_SIZE)))
	{
		if (!(ft_strchr(stock, '\n')))
			buffer[readsize] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	while (stock[i] != '\n')
		i++;
	*line = ft_strndup(stock, i);
	stock = ft_strdup(stock + i + 1);
	if (readsize == 0)
		return (1);
	return (0);
}
