# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    testing.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 02:37:53 by myener            #+#    #+#              #
#    Updated: 2020/07/03 04:48:08 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from vector import Vector

v1 = Vector([0.0, 1.0, 2.0, 3.0])
v2 = Vector([0.0, 0.0, 2.0, 6.0])
v3 = Vector([9.0, 1.0, 2.0, 3.0])
v4 = Vector([0.0, 1.0, 7.0, 5.0])
v5 = Vector([0.0, 90.0, 2.0, 3.0])
print("v1:", v1)
print("v2:", v2)
print("v3:", v3)
print("v4:", v4)
print("v5:", v5)
print("\nADDITIONS:")
v6 = v1 + v2
print(v6)
v6 = v3 + v4
print(v6)
v6 = v5 + 4
print(v6)
v6 = 7 + v5
print(v6)
v6 = v2 + 5
print(v6)
v6 = 12 + v1
print(v6)
print("\nSUBSTRACTIONS:")
v6 = v1 - v2
print(v6)
v6 = v3 - v4
print(v6)
v6 = v5 - 4
print(v6)
v6 = 7 - v5
print(v6)
v6 = v2 - 5
print(v6)
v6 = 12 - v1
print(v6)
print("\nDIVISIONS:")
v6 = v1 / v2
print(v6)
v6 = v3 / v4
print(v6)
v6 = v5 / 4
print(v6)
v6 = 7 / v5
print(v6)
v6 = v2 / 5
print(v6)
v6 = 12 / v1
print(v6)
print("\nMULTIPLICATIONS:")
v6 = v5 * 4
print(v6)
v6 = 7 * v5
print(v6)
v6 = v2 * 5
print(v6)
v6 = 12 * v1
print(v6)