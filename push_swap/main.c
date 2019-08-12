/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:38:48 by myener            #+#    #+#             */
/*   Updated: 2019/08/12 16:22:50 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		bad_arg_checker(char **argv)
{
	int i;
	int	j;

	i = 1; // 1 and not 0 to jump over the executable name
	while (argv[i] != NULL) /* go through the string list */
	{
		j = 0;
		while (argv[i][j] != '\0') /* go through each character of each string */
		{
			if (argv[i][j] == '-' || argv[i][j] == '+') /* if the first character is a - or a + (still valid), */
			{
				j++; /* then jump over it to investigate further, */
				if (!argv[i][j])
					return (1);
				while (argv[i][j]) /* go through the entire string, */
				{
					if (!(argv[i][j] >= '0' && argv[i][j] <= '9')) /* and if at some point it's not a digit, */
						return (1);
					j++;
				}
				return (0); /* else all is good :) */
			}
			else if (argv[i][j] >= '0' && argv[i][j] <= '9') /* else if it's already a digit, */
			{
				// printf("coucou\n");
				while (argv[i][j]) /* go through the entire string, */
				{
					// printf("argv[i][j] = %c\n", argv[i][j]);
					if (argv[i][j + 1] && !(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')) /* and if at some point it's not a digit, */
						return (1);
					j++;
				}
				return (0); /* else all is good :) */
			}
			else if (argv[i][j] != '-' && argv[i][j] != '+' && !(argv[i][j] >= '0' && argv[i][j] <= '9')) /* else if none of that is true, */
				return (1);
			j++;
		}
		i++;
	}
	return (0); /* if all is well, return 0 (false) */
}

int		main(int argc, char **argv)
{
	t_pslist list;
	t_psflag flag;

	list.data = 0;
	flag.ch = 0;
	flag.ps = 0;
	flag.instruc = NULL;
	if (argc == 1) /* if no parameter is passed, return */
		return (0);
	else if (argc >= 2)
	{
		if (bad_arg_checker(argv) == 1) /* if there's a bad argument, output an error message and return */
			ps_output(1);
		else if (bad_arg_checker(argv) == 0) /* if all is good then we can proceed */
		{
			if ((flag.ch = (!ft_strcmp(argv[0], "./checker"))))
				checker(&list, &flag, argv);
			else if ((flag.ps =(!ft_strcmp(argv[0], "./push_swap"))))
				push_swap(&list, &flag, argv);
			else if ((flag.ps =(!ft_strcmp(argv[0], "/Users/myener/Desktop/homework/push_swap/push_swap"))))
				push_swap(&list, &flag, argv);
			else
			{
				ps_output(1);
			}
		}
	}
	return (0);
}
