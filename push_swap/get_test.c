/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 12:23:16 by myener            #+#    #+#             */
/*   Updated: 2019/06/24 19:42:45 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
    char *buffer = NULL;
    int read;
    size_t len;

	read = 0;
	while (read != EOF)
    	read = get_next_line(0, &buffer);
    if (-1 != read)
        puts(buffer);
    else
        printf("No line read...\n");

    printf("Size read: %d\n Len: %zu\n", read, len);
    free(buffer);
    return 0;
}
