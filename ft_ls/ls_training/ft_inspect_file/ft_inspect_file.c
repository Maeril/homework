/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:27:50 by myener            #+#    #+#             */
/*   Updated: 2019/04/11 17:41:32 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_inspect_file.h"

int		ft_inspect_file(const char *name)
{
	struct stat		*buf;
	struct passwd	*pw;
	struct group	*gr;
	char			*tm_out;

	stat(name, buf);
	pw = getpwuid(buf->st_uid);
	gr = getgrgid(buf->st_gid);
	tm_out = ctime(&buf->st_mtime);
	// printf("coucou\n");
	// tmp = ft_itoa(time(&buf->st_mtime));
	// printf("current time is %s", tmp);

	// if (data->ret)
	// {
		// printf("Nom: %s\n", file->d_name);
		// printf("Type: %hhu\n", file->d_type);
		printf("Modes: %d\n", buf->st_mode);
		// printf("Nombre de liens: %d\n", stat->st_nlink);
		printf("Proprietaire: %s\n", pw->pw_name);
		printf("Groupe: %s\n", gr->gr_name);
		// printf("Taille: %d octets\n", stat->st_size);
		printf("Date de derniere modification: %s\n", tm_out);
		return (1);
	// }
	return (0);
}

int		main(int argc, char **argv)
{
	const char	*name;

	name = argv[1];
	if (argc == 2)
		return (ft_inspect_file(name));
	return (0);
}

// pour time/ctime: https://www.gnu.org/software/libc/manual/html_node/General-Time-String-Parsing.html#General-Time-String-Parsing
// pour les permissions: https://stackoverflow.com/questions/10323060/printing-file-permissions-like-ls-l-using-stat2-in-c