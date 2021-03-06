/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:37:03 by myener            #+#    #+#             */
/*   Updated: 2019/06/18 18:09:38 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			permissionprinter(struct stat *buf)
{
	ft_printf((S_ISBLK(buf->st_mode)) ? "b" : "");
	ft_printf((S_ISCHR(buf->st_mode)) ? "c" : "");
	ft_printf((S_ISDIR(buf->st_mode)) ? "d" : "");
	ft_printf((S_ISFIFO(buf->st_mode)) ? "p" : "");
	ft_printf((S_ISREG(buf->st_mode)) ? "-" : "");
	ft_printf((S_ISLNK(buf->st_mode)) ? "l" : "");
	ft_printf((S_ISSOCK(buf->st_mode)) ? "s" : "");
	ft_printf((buf->st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((buf->st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((buf->st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((buf->st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((buf->st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((buf->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((buf->st_mode & S_IROTH) ? "r" : "-");
	ft_printf((buf->st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((buf->st_mode & S_IXOTH) ? "x " : "- ");
}

void				time_formatter(struct stat *buf, int sizelen)
{
	char	*tm;
	int		i;

	tm = ctime(&buf->st_mtime);
	tm = ft_strchr(tm, ' ');
	i = (ft_strlen(tm) - 9);
	tm[i] = '\0';
	ft_printf(sizelen <= 2 ? "%s " : "%s ", tm);
}

int					get_file_info(struct stat *buf)
{
	struct passwd	*pw;
	struct group	*gr;
	int				sizelen;

	if (!(pw = getpwuid(buf->st_uid)))
		return (0);
	if (!(gr = getgrgid(buf->st_gid)))
		return (0);
	permissionprinter(buf);
	ft_printf("%d\t", buf->st_nlink);
	ft_printf("%s ", pw->pw_name);
	ft_printf("%s ", gr->gr_name);
	ft_putnbr_long(buf->st_size);
	ft_putchar('\t');
	sizelen = ft_intlen(buf->st_size);
	time_formatter(buf, sizelen);
	return (0);
}

int					ends_with_slash(const char *name)
{
	int		i;

	i = 0;
	while (name[i])
		i++;
	return (name[i] == '/' ? 1 : 0);
}

t_lsdata			*ls_pm_saver(t_lsdata *list, t_lsflag *flag)
{
	if (flag->l)
	{
		ft_putstr("\033[0mtotal ");
		ft_putnbr(flag->blocks_nb);
		ft_putchar('\n');
	}
	return (list);
}
