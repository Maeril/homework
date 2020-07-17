# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    vector.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 06:30:48 by myener            #+#    #+#              #
#    Updated: 2020/07/03 04:31:11 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Vector:
	def __init__(self, arg):
		self.values = []
		self.size = 0

		if isinstance(arg, list):
			for val in arg:
				if isinstance(val, float) is False:
					exit()
			self.values = arg
			self.size = len(arg)
		elif isinstance(arg, tuple):
			if len(arg) is not 2:
				exit()
			for val in arg:
				if (isinstance(val, int) is False or arg[0] >= arg[1]):
					exit()
			for i in range(arg[0], arg[1]):
				self.values.append(float(i))
			self.size = arg[1] - arg[0]
		elif isinstance(arg, int):
			if arg < 1:
				exit()
			i = 0.0
			for n in range(arg):
				self.values.append(i)
				i += 1.0
			self.size = arg
		else:
			raise AttributeError

	def __str__(self):
		return self.__class__.__name__ + ": " + str(self.values)

	def __repr__(self):
		return self.__class__.__name__ + ": " + str(self.values)

	def __add__(self, operator):
		if isinstance(operator, int) and len(self.values) is 1:
			ret = [self.values[0] + operator]
			return Vector(ret)
		if isinstance(operator, Vector) is False or len(self.values) != len(operator.values):
			return
		ret = []
		for i in range(len(self.values)):
			ret.append(self.values[i] + operator.values[i])
		return Vector(ret)

	def __radd__(self, operator):
		self.__add__(operator)

	def __sub__(self, operator):
		if isinstance(operator, int) and len(self.values) is 1:
			ret = [self.values[0] - operator]
			return Vector(ret)
		if isinstance(operator, Vector) is False or len(self.values) != len(operator.values):
			return
		ret = []
		for i in range(len(self.values)):
			ret.append(self.values[i] - operator.values[i])
		return Vector(ret)

	def __rsub__(self, operator):
		self.__sub__(operator)

	def __truediv__(self, operator):
		if isinstance(operator, Vector) is True:
			return
		ret = []
		for i in self.values:
			ret.append(i / operator)
		return Vector(ret)

	def __rtruediv__(self, operator):
		self.__truediv__(operator)

	def __mul__(self, operator):
		if isinstance(operator, int):
			ret = []
			for i in self.values:
				ret.append(i * operator)
			return Vector(ret)
		if isinstance(operator, Vector) is False or len(self.values) != len(operator.values):
			return
		ret = 0
		for i in range(len(self.values)):
			ret += self.values[i] * operator.values[i]
		return ret

	def __rmul__(self, operator):
		self.__mul__(operator)