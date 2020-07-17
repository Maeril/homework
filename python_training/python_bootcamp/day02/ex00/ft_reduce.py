# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_reduce.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 22:09:03 by myener            #+#    #+#              #
#    Updated: 2020/07/05 22:39:49 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_reduce(function_to_apply, list_of_inputs):
	value = 0

	for i in zip(list_of_inputs):
		value += function_to_apply(i)
	return value