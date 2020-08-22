# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vec_cost.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:41:01 by myener            #+#    #+#              #
#    Updated: 2020/08/20 22:55:39 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

def cost_(y, y_hat):
	"""Computes the mean squared error of two non-empty numpy.ndarray, without any for loop. The two arrays must have the same dimensions.
	Args:
	  y: has to be an numpy.ndarray, a vector.
	  y_hat: has to be an numpy.ndarray, a vector.
	Returns:
	  The mean squared error of the two vectors as a float.
	  None if y or y_hat are empty numpy.ndarray.
	  None if y and y_hat does not share the same dimensions.
	Raises:
	  This function should not raise any Exceptions.
	"""
	return ((((y_hat - y) * (y_hat - y))) / (2 * len(y)))

X = np.array([0, 15, -9, 7, 12, 3, -21])
Y = np.array([2, 14, -13, 5, 12, 4, -19])

# Example 1:
print(cost_(X, Y))
# Output:
# 4.285714285714286

# Example 2:
print(cost_(X, X))
# Output:
# 0.0