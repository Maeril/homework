/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:30:15 by myener            #+#    #+#             */
/*   Updated: 2018/11/21 13:57:11 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	int	i;
	int	j;

	if (!*find)
		return (str);
	i = 0;
	while (str[i] != len)
	{
		j = 1;
		if (str[i] == find[0])
		{
			while (find[j] != '\0' && str[i + j] == find[j])
				j++;
			if (find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
