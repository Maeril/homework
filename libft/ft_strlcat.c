/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:51:44 by myener            #+#    #+#             */
/*   Updated: 2018/11/21 18:48:56 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "libft.h"

size_t	*ft_strlcat(char *src, const char *dest, size_t n)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i + ft_strlen((const char*)src));
}*/
