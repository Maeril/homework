/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:14:37 by myener            #+#    #+#             */
/*   Updated: 2018/12/07 15:44:06 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_join( char *s1, const char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	ft_strdel(&s1);
	return (s3);
}

static char	*ft_free_strdup(char *str)
{
	int		i;
	char	*dest;

	if (!(dest = ft_strnew(ft_strlen(str))))
		return (0);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_free_strndup(char *str, char *dest, size_t n)
{
	size_t	i;

	if (!(dest = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n && str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int			get_next_line(const int fd, char **line)
{
	size_t			i;
	int				readsize;
	char			buffer[BUFF_SIZE + 1];
	static char		*stock;

	if (fd < 0 || fd > MAX_FD || !line || !BUFF_SIZE || read(fd, stock, 0) < 0 )
		return (-1);
	if (!stock)
		stock = ft_strnew(0);
	i = 0;
	while ((readsize = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[readsize] = '\0';
		stock = ft_free_join(stock, buffer);
		if (ft_strchr(stock, '\n'))
			break ;
	}
	if ((readsize < BUFF_SIZE) && (ft_strlen(stock) == 0))
		return (0);
	while (stock[i] != '\n' && stock[i])
		i++;
	*line = ft_free_strndup(stock, *line, i);
	if (i < ft_strlen(stock))
			stock = ft_free_strdup(stock + i + 1);
	else
		ft_strclr(stock);
	return (1);
}