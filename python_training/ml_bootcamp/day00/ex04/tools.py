# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tools.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 00:17:31 by myener            #+#    #+#              #
#    Updated: 2020/08/20 00:44:43 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def add_intercept(x):
	"""Adds a column of 1's to the non-empty numpy.ndarray x.
	Args:
	  x: has to be an numpy.ndarray, a vector of dimension m * 1.
	Returns:
	  X as a numpy.ndarray, a vector of dimension m * 2.
	  None if x is not a numpy.ndarray.
	  None if x is a empty numpy.ndarray.
	Raises:
	  This function should not raise any Exception.
	"""
	if isinstance(x,(np.ndarray, np.generic)) is False or x.size == 0:
		return None
	vec = np.ones(len(x))
	col = np.atleast_2d(vec).T
	if (x.ndim < 2):
		x2 = np.atleast_2d(x).T
		ret = np.append(col, x2, axis=1)
	elif (x.ndim == 2):
		ret = np.append(col, x, axis=1)
	else:
		raise AttributeError
	return ret

# Example 1:
x = np.arange(1,6)
print(add_intercept(x), '\n')
# Output:
# array([[1., 1.],
#        [1., 2.],
#        [1., 3.],
#        [1., 4.],
#        [1., 5.]])


# Example 2:
y = np.arange(1,10).reshape((3,3))
print(add_intercept(y))
# Output:
# array([[1., 1., 2., 3.],
#        [1., 4., 5., 6.],
#        [1., 7., 8., 9.]])