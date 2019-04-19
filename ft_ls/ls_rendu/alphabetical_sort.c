/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphabetical_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 13:04:49 by myener            #+#    #+#             */
/*   Updated: 2019/04/19 14:34:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_file_names(struct dirent *repo, DIR *dir)
{
	char	*stock;
	int		i;

	while ((repo = readdir(dir)) != NULL)
	{
	}
}