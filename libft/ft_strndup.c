/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:18:19 by myener            #+#    #+#             */
/*   Updated: 2018/11/20 18:15:56 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *len)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *str, size_t n)
{
	int		i;
	char	*dest;

	if (!(dest = malloc(sizeof(*str) * (ft_strlen(str) + 1))))
		return (0);
	i = 0;
	while (str[i] <= n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = str[i];
	return (dest);
}
