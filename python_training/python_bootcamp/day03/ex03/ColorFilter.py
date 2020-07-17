# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ColorFilter.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 18:19:44 by myener            #+#    #+#              #
#    Updated: 2020/07/08 20:32:50 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

class ColorFilter:
	def _dtype_to_int(selfself, array):
		if array.dtype == np.float32:  # Si le résultat n'est pas un tableau d'entiers
			array = (array * 255).astype(np.uint8)
		if array.dtype == np.float64:  # Si le résultat n'est pas un tableau d'entiers
			array = (array * 255 * 255).astype(np.uint16)
		return array
	def invert(self, array):
		return 255 - array
	def to_blue(self, array):
		ret = array
		ret[:,:] = [0, 0, 255]
		return ret
	def to_green(self, array):
		ret = array
		ret[:,:] = [0, 255, 0]
		return ret
	def to_red(self, array):
		ret = array
		ret[:,:] = [255, 0, 0]
		return ret
	# def celluloid(array):
