/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabetical_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:04:49 by myener            #+#    #+#             */
/*   Updated: 2019/04/19 15:18:02 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_num_files(struct dirent *repo, DIR *dir)
{
	int		i;

	i  = 0;
	while ((repo = readdir(dir)) != NULL)
		i++;
	return(i);
}

char	*get_file_names(struct dirent *repo, DIR *dir)
{
	char	*stock;
	int		i;

	stock = ft_strnew(1);
	while ((repo = readdir(dir)) != NULL)
	{
		stock = ft_free_join(stock, repo->d_name);
		stock = ft_free_join(stock, " ");
	}
	return(stock);
}

