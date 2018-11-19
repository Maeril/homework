/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:57:15 by myener            #+#    #+#             */
/*   Updated: 2018/11/15 11:35:58 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int	i;

	if (!(str = malloc(sizeof((*s) * (ft_strlen(s) + 1))))
		return (NULL);	
	i = 0;	
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
