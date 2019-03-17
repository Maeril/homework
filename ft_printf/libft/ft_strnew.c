/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:57:15 by myener            #+#    #+#             */
/*   Updated: 2019/03/17 23:01:24 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(((void*)str), (size + 1));
	return (str);
}
