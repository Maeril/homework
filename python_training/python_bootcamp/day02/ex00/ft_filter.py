# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_filter.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 22:08:50 by myener            #+#    #+#              #
#    Updated: 2020/07/05 22:26:09 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_filter(function_to_apply, list_of_inputs):
	iter = []

	if function_to_apply is not None:
		if function_to_apply(i) for i in zip(list_of_inputs):
			iter.append(i)
	elif function_to_apply is None:
		if i for i in zip(list_of_inputs)::
			iter.append(i)
	return iter