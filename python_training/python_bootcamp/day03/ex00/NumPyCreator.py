# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    NumPyCreator.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 16:38:59 by myener            #+#    #+#              #
#    Updated: 2020/07/07 23:05:57 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

class NumPyCreator:
	def from_list(self, lst, dtype=None):
		return np.array(lst, dtype=dtype)
	def from_tuple(self, tpl, dtype=None):
		return np.array(tpl, dtype=dtype)
	def from_iterable(self, itr, dtype=None):
		return np.array(itr, dtype=dtype)
	def from_shape(self, shape, value=0, dtype=None):
		return np.full(shape, value, dtype=dtype)
	def random(self, shape):
		return np.random.rand(*shape)
	def identity(self, n, dtype=None):
		return np.identity(n, dtype=dtype)