# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testing.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 02:37:53 by myener            #+#    #+#              #
#    Updated: 2020/07/03 06:36:09 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from matrix import Matrix

v1 = Matrix([[19.0, 1.0, 2.0], [19.0, 1.0, 2.0], [19.0, 1.0, 2.0]])
v2 = Matrix([[90.0, 0.0, 2.0, 6.0], [89.0, 0.0, 2.0, 6.0]])
v3 = Matrix([[9.0, 1.0, 2.0], [9.0, 1.0, 2.0], [9.0, 1.0, 2.0]])
v4 = Matrix([[0.0, 1.0, 7.0, 5.0], [0.0, 1.0, 7.0, 5.0], [0.0, 1.0, 7.0, 5.0]])
v5 = Matrix([[0.0, 90.0, 2.0, 3.0], [0.0, 90.0, 2.0, 3.0], [0.0, 90.0, 2.0, 3.0]])
v6 = Matrix((5, 5))
print("v1:", v1, "shape:", v1.shape)
print("v2:", v2, "shape:", v2.shape)
print("v3:", v3, "shape:", v3.shape)
print("v4:", v4)
print("v5:", v5)
print("v6:", v6)
print("\nADDITIONS:")
v6 = v1 + v3
print(v6)
# v6 = v3 + v4
# print(v6)
# v6 = v5 + 4
# print(v6)
# v6 = 7 + v5
# print(v6)
# v6 = v2 + 5
# print(v6)
# v6 = 12 + v1
# print(v6)
print("\nSUBSTRACTIONS:")
v6 = v1 - v3
print(v6)
# v6 = v3 - v4
# print(v6)
# v6 = v5 - 4
# print(v6)
# v6 = 7 - v5
# print(v6)
# v6 = v2 - 5
# print(v6)
# v6 = 12 - v1
# print(v6)
print("\nDIVISIONS:")
v6 = v1 / v3
print(v6)
# v6 = v3 / v4
# print(v6)
# v6 = v5 / 4
# print(v6)
# v6 = 7 / v5
# print(v6)
# v6 = v2 / 5
# print(v6)
# v6 = 12 / v1
# print(v6)
print("\nMULTIPLICATIONS:")
v6 = v1 * v3
print(v6)
# v6 = 7 * v5
# print(v6)
# v6 = v2 * 5
# print(v6)
# v6 = 12 * v1
# print(v6)