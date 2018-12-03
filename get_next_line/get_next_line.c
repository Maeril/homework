/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:14:37 by myener            #+#    #+#             */
/*   Updated: 2018/12/03 23:16:27 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*dest;

	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (((char*)s) + ft_strlen((char*)s));
	while (s[i])
	{
		if (s[i] == c)
			return (((char*)s) + i);
		i++;
	}
	return (NULL);
}

int     	get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE];
	static char*	stock;

	if (fd == -1)
		return (1);
	stock = read (fd, &line, BUFF_SIZE);
	while (stock != 0)
	{
		write(1, &line, stock);
		stock = read (fd, &line, BUFF_SIZE);
	}
	if (ft_strchr(stock, '\n') == 1)
		&line = ft_strndup((const char*)stock, ((int*)ft_strchr(stock, '\n')));
	return (0);
}