/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:46:09 by myener            #+#    #+#             */
/*   Updated: 2018/11/15 11:26:16 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_memcmp(const void *s1, const void *s2, size_t n)
{
	return (&ft_strcmp((unsigned char*)s1, (unsigned char*)s2));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*dst2;
	const char	*src2;

	dst2 = (char*)dst;
	src2 = (const char*)src;
	i = 0;
	while (i != n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);

}

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
