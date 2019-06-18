/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 16:38:48 by myener            #+#    #+#             */
/*   Updated: 2019/06/18 14:36:28 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		bad_arg_checker(char **argv)
{
	int i;
	int	j;

	i = 0;
	while (argv[i] != NULL) /* go through the string list */
	{
		j = 0;
		while (argv[i][j] != '\0') /* go through each character of each string */
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9')) /* if one isn't a number, return 1 (true)*/
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

	list.data = 0;
	if (argc == 1) /* if no parameter is passed, return */
		return (0);
	else if (argc >= 2)
	{
		if (bad_arg_checker(argv) == 1) /* if there's a bad argument, output an error message and return */
		{
			write(2, "Error\n", 6);
			return (0);
		}
		else if (bad_arg_checker == 0) /* if all is good then we can proceed */
		{
			if (argv[1] == "./checker")
				checker(&list, argv);
			/*else if (argv[1] == "./push_swap")*/
		}
	}
	return (0);
}