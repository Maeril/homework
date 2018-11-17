/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:38:41 by myener            #+#    #+#             */
/*   Updated: 2018/11/15 14:29:03 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!(s))
		return (NULL);
	if (c == 0)
		while(s != '\0')
			s++;
		return (s);
	while (s[i] != '\0')
	{
		while (s[i] == (char)c)
		{
			s++;
			i--;
			return (s);
		}
		i++;
	}
	return (NULL);
}
