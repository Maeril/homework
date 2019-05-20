/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:50:55 by myener            #+#    #+#             */
/*   Updated: 2019/05/06 22:47:21 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_space(char c)
{
	return(c == ' ' || c == '\t');
}

void	ft_putstr(char *str)
{
	int i = 0;

	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}

int		count_words(char *str)
{
	int		wordcount = 0;

	while (*str)
	{
		while (is_space(*str) && *str)
			str++;
		if (!is_space(*str) && *str)
		{
			wordcount++;
			while (!is_space(*str) && *str)
				str++;
		}
	}
	wordcount += 1;
	return (wordcount);
}

char	*saveword(char *str)
{
	char	*word;
	int		size;
	int		i = 0;

	while (!is_space(str[i]) && str[i])
		i++;
	word = malloc(sizeof(char) * (i + 2));
	size = i;
	i = 0;
	while (i <= size && !is_space(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	rev_wstr(char *str)
{
	int		i = 0;
	int 	k = 0;
	char	**tab;
	int		wc = count_words(str);

	tab = malloc(sizeof(char *) * wc + 1);
	while (*str)
	{
		while (is_space(*str) && *str)
			str++;
		if (!is_space(*str) && *str)
		{
			tab[i] = saveword(str);
			i++;
			while (!is_space(*str) && *str)
				str++;
		}
	}
	tab[i] = NULL;
	i--;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		if (i != 0)
			ft_putchar(' ');
		i--;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	return (0);
}