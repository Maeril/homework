/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 12:52:20 by myener            #+#    #+#             */
/*   Updated: 2018/11/15 11:25:50 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;

	i = 0;
	while ((const char*)src[i] && i < n)
	{
		if ((const char*)src[i] == (unsigned char)c)
			return (dst[i + 1]);
		(char*)dst[i] = (const char*)src[i];
		i++;
	}
	return (NULL);
}

int		main(void)
{
	const char	src[5] = "test";
	char		dst[5];

	printf("Before ft_memcpy dest = %s\n", dst);
	ft_memccpy(dst, src, 0 strlen(src) + 1);
	printf("After ft_memcpy dest = %s\n", dst);

	char	dstx[5];

	printf("Before memccpy dest = %s\n", dstx);
	memccpy(dstx, src, strlen(src) + 1);
	printf("After memccpy dest = %s\n", dstx);
	return (0);
}
