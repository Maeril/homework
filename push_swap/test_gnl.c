/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:10:04 by myener            #+#    #+#             */
/*   Updated: 2019/07/16 19:46:32 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int main(void)
{
    char** instructions;
    size_t size;
    ssize_t read;

	size = 0;
    while ((read=get_next_line(0, instructions)) > 0)
        ft_putstr(*instructions);
    free(instructions);
    return 0;
}
