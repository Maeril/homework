# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    eval.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 16:41:00 by myener            #+#    #+#              #
#    Updated: 2020/07/05 21:17:03 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Evaluator:
	def zip_evaluate(coefs, words):
		if (len(coefs) != len(words)):
			return (-1)
		count = 0
		for nb, word in zip(coefs, words):
			count += nb * len(word)
		return (count)
	def enumerate_evaluate(coefs, words):
		if (len(coefs) != len(words)):
			return (-1)
		count = 0
		for index, (value1, value2) in enumerate(zip(coefs, words)):
			count += value1 * len(value2)
		return (count)