/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:37:03 by myener            #+#    #+#             */
/*   Updated: 2019/04/18 16:02:06 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			permissionprinter(struct stat buf)
{
	ft_printf((S_ISBLK(buf.st_mode)) ? "b" : "");
	ft_printf((S_ISCHR(buf.st_mode)) ? "c" : "");
	ft_printf((S_ISDIR(buf.st_mode)) ? "d" : "");
	ft_printf((S_ISFIFO(buf.st_mode)) ? "p" : "");
	ft_printf((S_ISREG(buf.st_mode)) ? "-" : "");
	ft_printf((S_ISLNK(buf.st_mode)) ? "l" : "");
	ft_printf((S_ISSOCK(buf.st_mode)) ? "s" : "");
	ft_printf((buf.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((buf.st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((buf.st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((buf.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((buf.st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((buf.st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((buf.st_mode & S_IROTH) ? "r" : "-");
	ft_printf((buf.st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((buf.st_mode & S_IXOTH) ? "x " : "- ");
}

void	time_formatter(struct stat buf)
{
	char	*tm;
	int		i;

	tm = ctime(&buf.st_mtime);
	tm = ft_strchr(tm, ' ');
	i = (ft_strlen(tm) - 9);
	tm[i] = '\0';
	ft_printf("%s ", tm); // last modification time;
}

int		get_file_info(const char *name)
{
	struct stat		buf;
	struct passwd	*pw;
	struct group	*gr;

	stat(name, &buf);
	pw = getpwuid(buf.st_uid);
	gr = getgrgid(buf.st_gid);

	permissionprinter(buf);
	ft_printf("%d\t", buf.st_nlink); // nb hardlinks;
	ft_printf("%s ", pw->pw_name); // user name;
	ft_printf("%s ", gr->gr_name); // group name;
	ft_printf("%lld\t", buf.st_size); // size (octets);
	time_formatter(buf);
	ft_printf("%s\n", name); // file name;
	return (0);
}
