/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:31:04 by myener            #+#    #+#             */
/*   Updated: 2018/11/19 17:47:45 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!(s3 = malloc(sizeof(*s3) * ((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	i = 0;
	while (s3)
	{
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
	}
	s3[i] = '\0';
	return (s3);
}
