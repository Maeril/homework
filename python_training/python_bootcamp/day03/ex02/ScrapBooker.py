# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ScrapBooker.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 00:03:05 by myener            #+#    #+#              #
#    Updated: 2020/07/08 18:17:36 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

class ScrapBooker:
	def	crop(self, array, dimensions, position):
		if array.shape[0] < dimensions[0] or array.shape[1] < dimensions[1]:
            raise ValueError("Dimensions can not be larger than the original image")
        elif position[0] + dimensions[0] > array.shape[0] or position[1] + dimensions[1] > array.shape[1]:
            raise ValueError("Crop dimensions out of bounds")
    	ret = array[position[0]:dimensions[1], position[1]:dimensions[1]]
		return ret
	def thin(self, array, n, axis):
		return np.delete(array, n, axis)
	def juxtapose(self, array, n, axis):
		ret = array
		for i in range(1, n):
			ret = np.concatenate((array, ret), axis)
		return ret
	def mosaic(self, array, dimensions):
		return np.tiles(array, dimensions)