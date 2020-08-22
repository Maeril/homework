# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    plot.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 20:35:39 by myener            #+#    #+#              #
#    Updated: 2020/08/21 00:07:53 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from tools import add_intercept
from matplotlib import pyplot as plt

def plot(x, y, theta):
	"""Plot the data and prediction line from three non-empty numpy.ndarray.
	Args:
	  x: has to be an numpy.ndarray, a vector of dimension m * 1.
	  y: has to be an numpy.ndarray, a vector of dimension m * 1.
	  theta: has to be an numpy.ndarray, a vector of dimension 2 * 1.
	Returns:
		Nothing.
	Raises:
	  This function should not raise any Exceptions.
	"""
	plt.scatter(x, y)
	plt.plot(x, np.dot(add_intercept(x), theta), 'm')
	plt.show()

x = np.arange(1,6)
y = np.array([3.74013816, 3.61473236, 4.57655287, 4.66793434, 5.95585554])

# #Example 1:
# theta1 = np.array([4.5, -0.2])
# plot(x, y, theta1)
# # Output:

# #Example 2:
# theta2 = np.array([-1.5, 2])
# plot(x, y, theta2)
# # Output:

# #Example 3:
# theta3 = np.array([3, 0.3])
# plot(x, y, theta3)
# # Output: