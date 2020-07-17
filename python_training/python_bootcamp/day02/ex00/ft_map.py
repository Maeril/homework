# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_map.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 22:08:40 by myener            #+#    #+#              #
#    Updated: 2020/07/05 22:38:26 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_map(function_to_apply, list_of_inputs):
	iter = []

	for i in zip(list_of_inputs):
		iter.append(function_to_apply(i))
		yield function_to_apply(i)
	return iter