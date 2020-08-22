# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tinystatistician.py                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 20:10:41 by myener            #+#    #+#              #
#    Updated: 2020/08/19 22:33:18 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class TinyStatistician:
	def mean(self, x):
		return (sum(x) / len(x))

	def median(self, x):
		y = x
		y.sort()
		return (float(y[int(len(y) / 2)]))

	def quartile(self, x, percentile):
		y = x
		y.sort()
		if percentile != 25 and percentile != 75:
			raise AttributeError
		return (float(y[int(len(y) / 4)]) if percentile == 25 else float(y[int((len(y) / 4) * 3)]))

	def var(self, x):
		m = sum(x) / len(x)
		return (sum((i - m) ** 2 for i in x) / len(x))

	def std(self, x):
		m = sum(x) / len(x)
		return ((sum((i - m) ** 2 for i in x) / len(x)) ** 0.5)
