/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:50:30 by myener            #+#    #+#             */
/*   Updated: 2018/11/19 17:23:51 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (!(str = malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == start)
		{
			while (s[i] <= len)
			{
				str[i] = s[i]
				i++;
			}
		}
		i++;
	}
	return (str);
}
