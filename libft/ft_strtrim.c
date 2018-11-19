/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:03:15 by myener            #+#    #+#             */
/*   Updated: 2018/11/19 18:24:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*t;

	t = (char*)s;
	i = 0;
	while (t[i] && (t[i] == ' ' || t[i] == '\n' || t[i] == '\t'))
		i++;
	j = (ft_strlen(t[i]) - 1);
	while (t[j] > 0 && (t[j] == ' ' || t[j] == '\n' || t[j] == '\t'))
		j--;
	ft_strdup(t);
	return (ft_strsub(t, i, t[j - i]))
}
