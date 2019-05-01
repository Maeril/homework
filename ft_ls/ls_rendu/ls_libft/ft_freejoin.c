/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:31:04 by myener            #+#    #+#             */
/*   Updated: 2019/05/01 12:00:40 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_freejoin(const char *s1, const char *s2)
{
	char	*dst;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	if (!(dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	dst = ft_strcpy(dst, s1);
	dst = ft_strcat(dst, s2);
	tmp = dst;
	free(dst);
	return (tmp);
}
