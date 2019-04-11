/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:48:35 by myener            #+#    #+#             */
/*   Updated: 2019/04/11 15:36:45 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_dir.h"

int		ft_list_dir(const char *name)
{
	DIR				*dir;
	struct dirent	*repo;

	dir = opendir(name);
	if (readdir(dir))
	{
		while ((repo = readdir(dir)) != NULL)
			printf("%s ", repo->d_name);
		return (1);
	}
	closedir(dir);
	return (0);
}

int		main(int argc, char **argv)
{
	const char	*name;

	name = argv[1];
	if (argc == 2)
		return (ft_list_dir(name));
	return (0);
}
