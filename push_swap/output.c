/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 19:21:03 by myener            #+#    #+#             */
/*   Updated: 2019/08/07 16:17:07 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		input_checker(char *in) // tell whether there's something after the \n
// {
// 	int		i;

// 	i = 0;
// 	while (in[i])
// 	{
// 		if (in[i] == '\n' && in[i + 1] && in[i + 1] != '\0')
// 			return (1); // return the nb of the line in which it is found
// 		i++;
// 	}
// 	return (0);
// }

void	ps_displayer(char **out)
{
	int	i;

	i = 0;
	while (out[i])
	{
		if (ft_strcmp(out[i], "na"))
			ft_putendl(out[i]);
		free(out[i]);
		i++;
	}
}

int		ps_output(int i)
{
	if (i == 1)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	else if (i == 2)
		write(1, "KO\n", 3); /* output "KO" means the list isn't in ascending order */
	else if (i == 3)
		write(1, "OK\n", 3);
	return (0);
}