# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    plot.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 23:01:20 by myener            #+#    #+#              #
#    Updated: 2020/08/21 00:31:35 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
import matplotlib.pyplot as plt
from tools import add_intercept
from cost import cost_ as cost
from prediction import predict

def plot_with_cost(x, y, theta):
	"""Plot the data and prediction line from three non-empty numpy.ndarray.
	Args:
	  x: has to be an numpy.ndarray, a vector of dimension m * 1.
	  y: has to be an numpy.ndarray, a vector of dimension m * 1.
	  theta: has to be an numpy.ndarray, a vector of dimension 2 * 1.
	Returns:
		Nothing.
	Raises:
	  This function should not raise any Exception.
	"""
	y_hat = predict(x, theta)
	plt.plot(x, y_hat, 'm')
	plt.vlines(x, y, y_hat, colors='b', linestyles='dotted')
	plt.scatter(x, y, c='b')
	plt.title("Cost: "+ str(cost(y, y_hat) * 2)[1:-1])
	plt.show()

x = np.arange(1,6)
y = np.array([11.52434424, 10.62589482, 13.14755699, 18.60682298, 14.14329568])

#Example 1:
theta1= np.array([18,-1])
plot_with_cost(x, y, theta1)

#Example 2:
theta2 = np.array([14, 0])
plot_with_cost(x, y, theta2)

#Example 3:
theta3 = np.array([12, 0.8])
plot_with_cost(x, y, theta3)
