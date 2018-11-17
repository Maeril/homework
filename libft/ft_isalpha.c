/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:20:59 by myener            #+#    #+#             */
/*   Updated: 2018/11/14 10:27:27 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	if (((char)c >= 'A' && (char)c <= 'Z') || ((char)c >= 'a' 
	&& (char)c <= 'z'))
		return (1);
	return (0);
}
