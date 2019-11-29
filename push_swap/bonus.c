/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:17:02 by myener            #+#    #+#             */
/*   Updated: 2019/11/29 14:19:29 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_screen(void)
{
	const char *clear_ansi;

	clear_ansi = "\e[1;1H\e[2J";
	write(STDOUT_FILENO, clear_ansi, 12);
}

int			pile_print_graph(t_pslist *head, t_psflag *flag, int nb)
{
	int			i;
	t_pslist	*curr;

	i = 0;
	curr = head;
	if (flag->visual)
	{
		flag->t > 5 ? clear_screen() : 0;
		while (curr && curr->next)
		{
			i = 0;
			while (i < curr->data)
			{
				nb ? ft_putstr("\e[44m") : ft_putstr("\e[43m");
				ft_putstr("\e[1m \e[0m");
				i++;
			}
			ft_putchar('\n');
			curr = curr->next;
		}
		ft_putchar('\n');
	}
	return (1);
}

char		**visual_flag_remover(char **tab)
{
	int		i;
	int		j;
	char	**out;
	char	**out2;

	if (!(out = malloc(sizeof(char*) * ((ft_tablen(tab) - 1) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < (ft_tablen(tab) - 1))
	{
		if (i == 1)
			i++;
		out[j] = tab[i];
		i++;
		j++;
	}
	out[j] = NULL;
	out2 = ft_spacesplit(out[1]);
	return (out2);
}

char		**trim_comments(char **in, int i)
{
	int		j;
	int		len;
	char	**out;

	j = 0;
	len = i;
	if (!(out = malloc(sizeof(char*) * ((len - 2) + 1))))
		return (NULL);
	i = 1;
	while (in[i] && i < (len - 1))
	{
		out[j] = ft_strdup(in[i]);
		i++;
		j++;
	}
	out[j] = NULL;
	ft_strdel(in);
	return (out);
}

void		instructions_displayer(int code, int nb)
{
	if (code == 1)
	{
		ft_printf("\033[1;36mNow fetching the commands.\n");
		ft_putstr("\033[0;36m(In manual mode, You may ");
		ft_printf("conclude your input by pressing ctrl + D.)\033[0m\n");
	}
	else if (code == 2)
	{
		ft_putstr("\033[1;36m\e[4m");
		ft_printf("The_following_commands_were_generated");
		ft_putstr("\e[0m\033[1;36m:\033[0m\n");
	}
	else if (code == 3)
	{
		ft_printf("\033[0;36mFor a total of");
		ft_printf("\033[1;31m %d\033[0;36m instructions.\033[0m\n", nb);
	}
}
