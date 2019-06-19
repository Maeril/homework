/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:19:42 by myener            #+#    #+#             */
/*   Updated: 2019/06/18 18:17:16 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		flag_manager(t_lsflag *flag, struct stat *buf,
						t_lsdata *list)
{
	int			dot;

	dot = (list->fn[0] == '.') ? 1 : 0;
	if (flag->l && (flag->a || (!flag->a && !dot)))
	{
		get_file_info(buf);
	}
}

int			is_flag(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' && str[1] != '-')
	{
		while (str[i])
		{
			if (str[i] == 'l' || str[i] == 'a' || str[i] == 'r'
				|| str[i] == 'R' || str[i] == 't')
				return (1);
			i++;
		}
	}
	else if (str[0] == '-' && str[1] == '-')
	{
		ft_putstr("ls: illegal option -- -\n");
		ft_putstr("usage: ./ft_ls [-alrRt] [file ...]\n");
	}
	return (0);
}

void		ls_parser(t_lsflag *flag, char *str)
{
	int		i;

	i = 1;
	while ((str[i] && str[i] != ' ') || str[i])
	{
		if (str[i] != 'R' && str[i] != 'a' && str[i] != 'l'
			&& str[i] != 'r' && str[i] != 't')
		{
			flag->c_intrus = str[i];
			flag->intrus = 1;
			break ;
		}
		str[i] == 'R' ? flag->big_r = 1 : 0;
		str[i] == 'a' ? flag->a = 1 : 0;
		str[i] == 'l' ? flag->l = 1 : 0;
		str[i] == 'r' ? flag->r = 1 : 0;
		str[i] == 't' ? flag->t = 1 : 0;
		flag->flag = (flag->big_r || flag->a || flag->l || flag->r || flag->t);
		if ((flag->rt = (flag->r && flag->t)))
		{
			flag->r = 0;
			flag->t = 0;
		}
		i++;
	}
}

int			blocks_counter(t_lsdata *list)
{
	long long int blocks;

	blocks = 0;
	while (list->next != NULL)
	{
		blocks += list->blocks;
		list = list->next;
	}
	return (blocks);
}

void		inex_file(const char *name, t_lsflag *flag)
{
	struct stat		buf;

	lstat(name, &buf);
	if ((S_ISDIR(buf.st_mode)) && !flag->intrus)
		ft_printf("ls: %s: Permission denied", name);
	else if ((S_ISREG(buf.st_mode)) && !flag->intrus)
	{
		(flag->l == 1) ? get_file_info(&buf) : 0;
		ft_printf("%s ", name);
	}
	else if (flag->intrus || name[0] == '-')
	{
		ft_printf("ls: illegal option -- %c", flag->intrus ?
		flag->c_intrus : name[1]);
		ft_putstr("usage: ./ft_ls [-alrRt] [file ...]");
	}
	else
		ft_printf("ls: %s: No such file or directory", name);
}
