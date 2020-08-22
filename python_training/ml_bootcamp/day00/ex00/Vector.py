# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Vector.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/12 02:29:03 by myener            #+#    #+#              #
#    Updated: 2020/08/19 04:08:19 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Vector:
	def __init__(self, arg):
		self.values = []
		self.size = 0
		if isinstance(arg, list):
			self.values = arg
			self.size = len(arg)
		elif isinstance(arg, tuple):
			nb1, nb2 = arg
			self.values = [float(i) for i in list(range(nb1, nb2))]
			self.size = len(self.values)
		elif isinstance(arg, int):
			nb1 = arg
			self.values = [float(i) for i in list(range(0, nb1))]
			self.size = nb1
		else:
			raise AttributeError
	def __add__(self, operator):
		if isinstance(operator, list) or isinstance(operator, tuple) or isinstance(operator, type(self)):
			ret = []
			if (len(operator.values) != len(self.values)):
				raise IndexError
			for i in range(len(self.values)):
				ret.append(self.values[i] + operator.values[i])
			ret = Vector(ret)
			return ret
		elif isinstance(operator, int):
			ret = self
			ret.values = [(i + operator) for i in self.values]
			return ret
		else:
			raise AttributeError
	def __radd__(self, operator):
		self.__add__(operator)
	def __sub__(self, operator):
		if isinstance(operator, list) or isinstance(operator, tuple) or isinstance(operator, type(self)):
			ret = []
			if (len(operator.values) != len(self.values)):
				raise IndexError
			for i in range(len(self.values)):
				ret.append(self.values[i] - operator.values[i])
			ret = Vector(ret)
			return ret
		elif isinstance(operator, int):
			ret = self
			ret.values = [(i - operator) for i in self.values]
			return ret
		else:
			raise AttributeError
	def __rsub__(self, operator):
		self.__sub__(operator)
	def __truediv__(self, operator):
		if isinstance(operator, list) or isinstance(operator, tuple) or isinstance(operator, type(self)):
			ret = []
			if (len(operator.values) != len(self.values)):
				raise IndexError
			for i in range(len(self.values)):
				ret.append(self.values[i] / operator.values[i])
			ret = Vector(ret)
			return ret
		elif isinstance(operator, int):
			ret = self
			ret.values = [(i / operator) for i in self.values]
			return ret
		else:
			raise AttributeError
	def __rtruediv__(self, operator):
		self.__truediv__(operator)
	def __mul__(self, operator):
		if isinstance(operator, list) or isinstance(operator, tuple) or isinstance(operator, type(self)):
			ret = []
			if (len(operator.values) != len(self.values)):
				raise IndexError
			for i in range(len(self.values)):
				ret.append(self.values[i] * operator.values[i])
			ret = Vector(ret)
			return ret
		elif isinstance(operator, int):
			ret = self
			ret.values = [(i * operator) for i in self.values]
			return ret
		else:
			raise AttributeError
	def __rmul__(self, operator):
		self.__mul__(operator)
    # def __str__
  	# def __repr__