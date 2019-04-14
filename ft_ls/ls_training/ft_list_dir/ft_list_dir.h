/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:59:10 by myener            #+#    #+#             */
/*   Updated: 2019/04/14 22:16:37 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_DIR_H

# define FT_LIST_DIR_H
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include "ls_libft/ft_printf/ft_printf.h"
# include "ls_libft/libft.h"

int		ft_list_dir(const char *name);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_printf(const char *format, ...);

#endif
