# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    matrix.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 02:45:43 by myener            #+#    #+#              #
#    Updated: 2020/07/03 06:36:55 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# for now only works with matrices of same dimensions

class Matrix:
	def __init__(self, arg):
		self.data = [[]]
		self.shape = (0,0)

		if isinstance(arg, list):
			for i in arg:
				if isinstance(i, list) is False:
					exit()
					for j in arg[i]:
						if isinstance(i, float) is False:
							exit()
			self.data = arg
			self.shape = (len(arg), len(arg[1]))
		elif isinstance(arg, tuple):
			self.data = [0] * arg[0]
			for k in range(arg[0]):
				self.data[k] = [0] * arg[1]
			self.shape = arg
		else:
			raise AttributeError

	def __str__(self):
		return self.__class__.__name__ + ": " + str(self.data)

	def __repr__(self):
		return self.__class__.__name__ + ": " + str(self.data)

	def	matrixadd(self, A, B):
		rows_A = len(A)
		cols_A = len(A[0])
		rows_B = len(B)
		cols_B = len(B[0])

		C = [[0 for row in range(cols_B)] for col in range(rows_A)]
		for i in range(rows_A):
			for j in range(cols_B):
				for k in range(cols_A):
					C[i][j] += A[i][k] + B[k][j]
		return C

	def __add__(self, operator):
		if isinstance(operator, Matrix) is False or len(self.data) != len(operator.data):
			return
		return self.matrixadd(self.data, operator.data)

	def __radd__(self, operator):
		self.__add__(operator)

	def	matrixsub(self, A, B):
		rows_A = len(A)
		cols_A = len(A[0])
		rows_B = len(B)
		cols_B = len(B[0])

		C = [[0 for row in range(cols_B)] for col in range(rows_A)]
		for i in range(rows_A):
			for j in range(cols_B):
				for k in range(cols_A):
					C[i][j] += A[i][k] - B[k][j]
		return C

	def __sub__(self, operator):
		if isinstance(operator, Matrix) is False or len(self.data) != len(operator.data):
			return
		return self.matrixsub(self.data, operator.data)

	def __rsub__(self, operator):
		self.__sub__(operator)

	def	matrixdiv(self, A, B):
		rows_A = len(A)
		cols_A = len(A[0])
		rows_B = len(B)
		cols_B = len(B[0])

		if cols_A != rows_B and cols_A != rows_A:
		  print ("Cannot divide the two matrices. Incorrect dimensions.")
		  return
		C = [[0 for row in range(cols_B)] for col in range(rows_A)]
		for i in range(rows_A):
			for j in range(cols_B):
				for k in range(cols_A):
					if (A[i][k] == 0 or B[k][j] == 0):
						print("Cannot divide by zero !")
						return
					C[i][j] += A[i][k] / B[k][j]
		return C

	def __truediv__(self, operator):
		return self.matrixdiv(self.data, operator.data)

	def __rtruediv__(self, operator):
		self.__truediv__(operator)

	def	matrixmult(self, A, B):
		rows_A = len(A)
		cols_A = len(A[0])
		rows_B = len(B)
		cols_B = len(B[0])

		if cols_A != rows_B:
		  print ("Cannot multiply the two matrices. Incorrect dimensions.")
		  return
		C = [[0 for row in range(cols_B)] for col in range(rows_A)]
		for i in range(rows_A):
			for j in range(cols_B):
				for k in range(cols_A):
					C[i][j] += A[i][k] * B[k][j]
		return C

	def __mul__(self, operator):
		if isinstance(operator, int):
			ret = []
			for i in self.data:
				ret.append(i * operator)
			return Matrix(ret)
		if isinstance(operator, Matrix) is False or len(self.data) != len(operator.data):
			return
		return (self.matrixmult(self.data, operator.data))

	def __rmul__(self, operator):
		self.__mul__(operator)