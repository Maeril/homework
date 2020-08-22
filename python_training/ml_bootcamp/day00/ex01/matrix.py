# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    matrix.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/12 02:29:03 by myener            #+#    #+#              #
#    Updated: 2020/08/20 20:17:02 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Matrix:
	def __init__(self, *arg):
		arguments = locals()
		self.data = []
		self.shape = ()
		if len(arguments) == 2 and isinstance(arg[0], list):
			self.data = arg[0]
			self.shape = (len(arg[0]), len(arg[0][0]))
		elif len(arguments) == 2 and isinstance(arg[0], tuple):
			x, y = arg[0]
			self.data = [[0.0 for i in range(x)] for j in range(y)]
			self.shape = arg[0]
		elif len(arguments) == 3 and isinstance(arg[0], list) and isinstance(arg[1], tuple):
			self.data = arg[0]
			self.shape = arg[1]
		else:
			raise AttributeError

	def	matrixadd(self, A, B):
		rows_A = len(A)
		cols_A = len(A[0])
		rows_B = len(B)
		cols_B = len(B[0])
		#if matrices have the same dimensions :
		ret = None
		if (cols_A == cols_B and rows_A == rows_B):
			ret = ([[0 for row in range(cols_A)] for col in range(rows_A)])
			for i in range(rows_A):
				for j in range(cols_A):
						ret[i][j] += A[i][j] + B[i][j]
		return ret

	def __add__(self, operator):
		if isinstance(operator, Matrix) is False:
			return
		return self.matrixadd(self.data, operator.data)

	def __radd__(self, operator):
		self.__add__(operator)

	def	matrixsub(self, A, B):
		rows_A = len(A)
		cols_A = len(A[0])
		rows_B = len(B)
		cols_B = len(B[0])
		#if matrices have the same dimensions :
		ret = None
		if (cols_A == cols_B and rows_A == rows_B):
			ret = ([[0 for row in range(cols_A)] for col in range(rows_A)])
			for i in range(rows_A):
				for j in range(cols_A):
						ret[i][j] += A[i][j] - B[i][j]
		return ret

	def __sub__(self, operator):
		if isinstance(operator, Matrix) is False:
			return
		return self.matrixsub(self.data, operator.data)

	def __rsub__(self, operator):
		self.__sub__(operator)

	def	matrixmul(self, A, B):
		rows_A = len(A)
		cols_A = len(A[0])
		rows_B = len(B)
		cols_B = len(B[0])
		#if matrices are square and equal or have compatible dimensions :
		# print(rows_A, cols_A, rows_B, cols_B)
		if (cols_A == rows_B):
			ret = ([[0 for row in range(cols_B)] for col in range(rows_A)])
			for i in range(rows_A):
				for j in range(cols_B):
					for k in range(cols_A):
						ret[i][j] += A[i][k] * B[k][j]
		return ret

	def __mul__(self, operator):
		if isinstance(operator, Matrix) is False:
			return
		return self.matrixmul(self.data, operator.data)

	def __rmul__(self, operator):
		self.__mul__(operator)
	# def __truediv__(self, operator):
	# 	if isinstance(operator, list) or isinstance(operator, tuple) or isinstance(operator, type(self)):
	# 		ret = []
	# 		if (len(operator.values) != len(self.values)):
	# 			raise IndexError
	# 		for i in range(len(self.values)):
	# 			ret.append(self.values[i] / operator.values[i])
	# 		ret = Vector(ret)
	# 		return ret
	# 	elif isinstance(operator, int):
	# 		ret = self
	# 		ret.values = [(i / operator) for i in self.values]
	# 		return ret
	# 	else:
	# 		raise AttributeError
	# def __rtruediv__(self, operator):
	# 	self.__truediv__(operator)
	# def __mul__(self, operator):
	# 	if isinstance(operator, list) or isinstance(operator, tuple) or isinstance(operator, type(self)):
	# 		ret = []
	# 		if (len(operator.values) != len(self.values)):
	# 			raise IndexError
	# 		for i in range(len(self.values)):
	# 			ret.append(self.values[i] * operator.values[i])
	# 		ret = Vector(ret)
	# 		return ret
	# 	elif isinstance(operator, int):
	# 		ret = self
	# 		ret.values = [(i * operator) for i in self.values]
	# 		return ret
	# 	else:
	# 		raise AttributeError
	# def __rmul__(self, operator):
	# 	self.__mul__(operator)
    # def __str__
  	# def __repr__