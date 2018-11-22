/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:52:20 by myener            #+#    #+#             */
/*   Updated: 2018/11/22 15:01:19 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*src2;
	char		*dst2;

	src2 = (const char*)src;
	dst2 = (char*)dst;
	while (*src2 && n--)
	{
		*dst2++ = *src2;
		if (*src2 == c)
			return (dst2);
		src2++;
	}
	return (0);
}

int		main()
{
	char	s[] = "bonjour";
	size_t	n;
	char	*dst; 

	n = 5;
	if (!(dst = (char*)malloc(sizeof(*s) * (n + 1))))
		return (0);

	printf("the excerpt is %s\n", ft_memccpy(dst, s, 'j', n));
	printf("the excerpt is %s\n", memccpy(dst, s, 'j', n));
}
