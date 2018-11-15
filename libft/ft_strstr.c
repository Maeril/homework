/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:41:44 by myener            #+#    #+#             */
/*   Updated: 2018/11/14 14:36:36 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *find)
{
	int	i;
	int	j;

	if (!*find)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 1;
		if (str[i] == find[0])
		{
			while (find[j] != '\0' && str[i + j] == find[j])
				j++;
			if (find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
