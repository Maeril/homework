# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    prediction.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 01:15:44 by myener            #+#    #+#              #
#    Updated: 2020/08/20 22:16:21 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from tools import add_intercept

def predict(x, theta):
	"""Computes the vector of prediction y_hat from two non-empty numpy.ndarray.
	Args:
	  x: has to be an numpy.ndarray, a vector of dimension m * 1.
	  theta: has to be an numpy.ndarray, a vector of dimension 2 * 1.
	Returns:
	  y_hat as a numpy.ndarray, a vector of dimension m * 1.
	  None if x or theta are empty numpy.ndarray.
	  None if x or theta dimensions are not appropriate.
	Raises:
	  This function should not raise any Exceptions.
	"""
	return np.dot(add_intercept(x), theta)



# x = np.arange(1,6)

# #Example 1:
# theta1 = np.array([5, 0])
# print(predict(x, theta1))
# Ouput:
# array([5., 5., 5., 5., 5.])
# Do you remember why y_hat contains only 5's here?


#Example 2:
# theta2 = np.array([0, 1])
# print(predict(x, theta2))
# Output:
# array([1., 2., 3., 4., 5.])
# Do you remember why y_hat == x here?


#Example 3:
# theta3 = np.array([5, 3])
# print(predict(x, theta3))
# Output:
# array([ 8., 11., 14., 17., 20.])


#Example 4:
# theta4 = np.array([-3, 1])
# print(predict(x, theta4))
# Output:
# array([-2., -1.,  0.,  1.,  2.])