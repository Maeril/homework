/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:27:50 by myener            #+#    #+#             */
/*   Updated: 2019/04/17 17:25:24 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inspect_file.h"

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
	ft_printf((buf.st_mode & S_IXOTH) ? "x" : "-");
}

static const char	*typefinder(struct stat buf)
{
	const char	*str;

	str = NULL;
	if (S_ISBLK(buf.st_mode))
		str = "Peripherique blocs";
	if (S_ISCHR(buf.st_mode))
		str = "Peripherique caracteres";
	if (S_ISDIR(buf.st_mode))
		str = "Dossier";
	if (S_ISFIFO(buf.st_mode))
		str = "Fifo";
	if (S_ISREG(buf.st_mode))
		str = "Fichier";
	if (S_ISLNK(buf.st_mode))
		str = "Lien symbolique";
	if (S_ISSOCK(buf.st_mode))
		str = "Socket";
	return (str ? str : 0);
}

int		ft_inspect_file(const char *name)
{
	struct stat		buf;
	struct passwd	*pw;
	struct group	*gr;
	char			*tm;
	const char		*type;

	stat(name, &buf);
	pw = getpwuid(buf.st_uid);
	gr = getgrgid(buf.st_gid);
	tm = ctime(&buf.st_mtime);
	type = typefinder(buf);

	ft_printf("Nom: %s\n", name);
	ft_printf("Type: %s\n", type);
	ft_printf("Modes: ");
	permissionprinter(buf);
	ft_printf("\n");
	ft_printf("Nombre de liens: %d\n", buf.st_nlink);
	ft_printf("Proprietaire: %s\n", pw->pw_name);
	ft_printf("Groupe: %s\n", gr->gr_name);
	ft_printf("Taille: %lld octets\n", buf.st_size);
	ft_printf("Date de derniere modification: %s", tm);
	return (0);
}

int		main(int argc, char **argv)
{
	const char	*name;

	name = argv[1];
	if (argc == 2)
		ft_inspect_file(name);
	return (0);
}