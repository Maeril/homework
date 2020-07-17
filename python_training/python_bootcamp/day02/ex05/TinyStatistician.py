# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    TinyStatistician.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 15:44:44 by myener            #+#    #+#              #
#    Updated: 2020/07/07 16:37:22 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import math

class TinyStatistician:
	# def __enter__:
	# 	if not x:
	# 		return None
	def mean(self, x):
		return sum(x) / len(x) if x else None
	def median(self, x):
		if not x:
			return None
		l = len(x)
		x.sort()
		if l % 2 == 0:
			m1 = x[l // 2]
			m2 = x[l // 2 - 1]
			median = (m1 + m2) / 2
		else:
			median = x[l // 2]
		return median
	def quartile(self, x, percentile):
		if not x:
			return None
		mid = len(x) / 2
		x.sort()
		if percentile == 25:
			ret = self.median(x[:(round(mid))])
			return ret * 2 - 1
		elif percentile == 75:
			ret = self.median(x[round(mid):])
			return ret
		else:
			return None
	def var(self, x):
		if not x:
			return None
		var = sum((i - self.mean(x))**2 for i in x) / len(x)
		return (var)
	def std(self, x):
		if not x:
			return None
		l = len(x)
		m = self.mean(x)
		for i in x:
			m += (float(i) - m)**2
		m = math.sqrt((m / float(l - 1)))
		return m

