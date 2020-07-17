# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ImageProcessor.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 23:17:58 by myener            #+#    #+#              #
#    Updated: 2020/07/08 20:34:31 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from matplotlib import pyplot

class ImageProcessor:
	def load(self, path):
		img = pyplot.imread(path)
		width = img.shape[0]
		length = img.shape[1]
		print(f"Loading image of dimensions {width} x {length}:\n")
		return img
	def display(self, array, interpolation="nearest"):
		return pyplot.imshow(array, interpolation=interpolation)