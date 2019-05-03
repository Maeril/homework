/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:50:55 by myener            #+#    #+#             */
/*   Updated: 2019/05/03 16:46:19 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
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
	while (i <= size)
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
	int		j = 0;
	int 	k = 0;
	char	**tab;
	int		wc = count_words(str);

	tab = malloc(sizeof(char *) * count_words(str) + 1);
	while (*str)
	{
		while (is_space(*str) && *str)
			str++;
		if (!is_space(*str) && *str)
		{
			printf("word saved is %s\n", saveword(str));
			tab[i] = saveword(str);
			i++;
			while (!is_space(*str) && *str)
				str++;
		}
	}
	tab[i] = NULL;
	while (tab[j])
		j++;
	j--;
	while (tab[j])
	{
		ft_putstr(tab[j]);
		j--;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	return (0);
}