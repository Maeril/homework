# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 18:53:44 by myener            #+#    #+#              #
#    Updated: 2020/07/08 20:33:18 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from matplotlib import pyplot
from ImageProcessor import ImageProcessor
imp = ImageProcessor()
arr = imp.load("./img.png")
print(f"type of arr: {arr.dtype}")
# Loading image of dimensions 200 x 200
from ColorFilter import ColorFilter
cf = ColorFilter()
invert_arr = cf.invert(arr)
print("première case de arr:")
print(arr[ 1, 1, :])
print("première case de invert_arr:")
print(invert_arr[ 1, 1, :])
pyplot.imshow(cf.invert(arr))
pyplot.show()
# pyplot.imshow(cf.to_green(arr))
# pyplot.show()
# pyplot.imshow(cf.to_red(arr))
# pyplot.imshow(cf.to_blue(arr))
# pyplot.imshow(cf.to_celluloid(arr))
# pyplot.imshow(cf.to_celluloid(arr, 8))
# pyplot.imshow(cf.to_celluloid(arr, 2))
# pyplot.imshow(cf.to_grayscale(arr, 'm'))
# pyplot.imshow(cf.to_grayscale(arr, 'weigthed'))