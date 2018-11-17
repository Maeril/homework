/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:53:40 by myener            #+#    #+#             */
/*   Updated: 2018/11/15 11:38:30 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char	buffer;
	
	i = 0;
	ft_memcpy(&buffer, src, len);
	ft_memcpy(dst, &buffer, len);
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
	
	turn (NULL);

}
