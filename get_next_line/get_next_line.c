/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:14:37 by myener            #+#    #+#             */
/*   Updated: 2018/12/06 23:41:42 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_free_join(const char *s1, const char *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);

	s3 = ft_strcpy(s3, s1);
	s3 = ft_strcat(s3, s2);
	free(((void*)s1));
	return (s3);
}

static char	*ft_free_strdup(const char *str)
{
	int		i;
	char	*dest;

	if (!(dest = malloc(sizeof(str) * (ft_strlen((char*)str) + 1))))
		return (0);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	free(((void*)str));
	dest[i] = '\0';
	return (dest);
}

int			get_next_line(const int fd, char **line)
{
	size_t			i;
	int				readsize;
	char			buffer[BUFF_SIZE + 1];
	static char		*stock;

	if (fd < 0 || fd > 4658 || !line || !BUFF_SIZE || read(fd, stock, 0) < 0 ||
		!(stock = ft_strnew(1)))
		return (-1);
	i = 0;
	while ((readsize = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[readsize] = '\0';
		stock = ft_free_join(stock, buffer);
		if (ft_strchr(stock, '\n'))
			break ;
	}
	if ((readsize < BUFF_SIZE) && (ft_strlen(stock) == 0))
		return (0);
	while (stock[i] != '\n')
		i++;
	*line = ft_strndup(stock, i - 1);
	if (i > ft_strlen(stock))
		stock = ft_free_strdup(stock + i + 1);
	else
		ft_strclr(stock);
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	else
	{
		char *l = NULL;
		int fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &l) > 0)
			{
				ft_putendl(l);
				//getchar();
			}
		free(l);
	}
}