/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:28:24 by myener            #+#    #+#             */
/*   Updated: 2019/04/12 18:38:00 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INSPECT_FILE_H

# define FT_INSPECT_FILE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#include "ls_libft/libft.h"
#include "ls_libft/ft_printf/ft_printf.h"


int			ft_printf(const char *format, ...);

#endif
