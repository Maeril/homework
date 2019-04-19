/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:31:04 by myener            #+#    #+#             */
/*   Updated: 2019/04/19 14:50:06 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_free_join(const char *s1, const char *s2)
{
	char	*s1_bis;
	char	*s3;
	int		i;
	int		j;

	s1_bis = NULL;
	s1_bis = ft_strcpy(s1_bis, s1);
	if (!s1_bis || !s2)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen(s1_bis) + ft_strlen(s2))))
		return (NULL);
	i = 0;
	while (s1_bis[i])
	{
		s3[i] = s1_bis[i];
		i++;
	}
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	ft_strdel(&s1_bis);
	return (s3);
}
