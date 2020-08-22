# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cost.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 21:18:49 by myener            #+#    #+#              #
#    Updated: 2020/08/20 23:57:08 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np
from prediction import predict

def cost_elem_(y, y_hat):
	"""
	Description:
		Calculates all the elements (1/2*M)*(y_pred - y)^2 of the cost function.
	Args:
      y: has to be an numpy.ndarray, a vector.
      y_hat: has to be an numpy.ndarray, a vector.
	Returns:
		J_elem: numpy.ndarray, a vector of dimension (number of the training examples,1).
	Raises:
		This function should not raise any Exception.
	"""
	if isinstance(y,(np.ndarray, np.generic)) is False or y.size == 0 or isinstance(y_hat,(np.ndarray, np.generic)) is False or y_hat.size == 0:
		return None
	J_elem = np.ndarray((len(y), 1))
	for i in range(len(y)):
		J_elem[i] = (((y_hat[i] - y[i]) ** 2) / len(y)) / 2
	return J_elem


def cost_(y, y_hat):
	"""
	Description:
		Calculates the value of cost function.
	Args:
      y: has to be an numpy.ndarray, a vector.
      y_hat: has to be an numpy.ndarray, a vector.
	Returns:
		J_value : has to be a float.
	Raises:
		This function should not raise any Exception.
	"""
	J_elem = cost_elem_(y, y_hat)
	J_value = 0.0
	for i in range(len(J_elem)):
		J_value += J_elem[i]
	return J_value

# x1 = np.array([[0.], [1.], [2.], [3.], [4.]])
# theta1 = np.array([[2.], [4.]])
# y_hat1 = predict(x1, theta1)
# y1 = np.array([[2.], [7.], [12.], [17.], [22.]])

# # Example 1:
# print(cost_elem_(y1, y_hat1), "\n\n")

# # # Output:
# # array([[0.], [0.1], [0.4], [0.9], [1.6]])

# # Example 2:
# print(cost_(y1, y_hat1), "\n\n")

# # # Output:
# # 3.0

# x2 = np.array([[0.2, 2., 20.], [0.4, 4., 40.], [0.6, 6., 60.], [0.8, 8., 80.]])
# theta2 = np.array([[0.05], [1.], [1.], [1.]])
# y_hat2 = predict(x2, theta2)
# y2 = np.array([[19.], [42.], [67.], [93.]])

# # Example 3:
# print(cost_elem_(y2, y_hat2), "\n\n")

# # # Output:
# # array([[1.3203125], [0.7503125], [0.0153125], [2.1528125]])

# # Example 4:
# print(cost_(y2, y_hat2), "\n\n")

# # # Output:
# # 4.238750000000004

# x3 = np.array([0, 15, -9, 7, 12, 3, -21])
# theta3 = np.array([[0.], [1.]])
# y_hat3 = predict(x3, theta3)
# y3 = np.array([2, 14, -13, 5, 12, 4, -19])

# # Example 5:
# print(cost_(y3, y_hat3), "\n\n")

# # # Output:
# # 4.285714285714286

# # Example 6:
# print(cost_(y3, y3), "\n\n")

# # # Output:
# # 0.0