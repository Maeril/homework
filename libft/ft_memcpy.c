/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:13:50 by myener            #+#    #+#             */
/*   Updated: 2018/11/15 11:24:44 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;

	i = 0;
	while (i != n)
	{
		(char*)dst[i] = (const char*)src[i];
		i++;
	}
	return (dst);
}

int		main(void)
{
	const char	src[5] = "test";
	char		dst[5];

	printf("Before ft_memcpy dest = %s\n", dst);
	ft_memcpy(dst, src, strlen(src) + 1);
	printf("After ft_memcpy dest = %s\n", dst);

	char	dstx[5];

	printf("Before memcpy dest = %s\n", dstx);
	memcpy(dstx, src, strlen(src) + 1);
	printf("After memcpy dest = %s\n", dstx);
	return (0);
}
