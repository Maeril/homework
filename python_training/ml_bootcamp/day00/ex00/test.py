# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 04:08:41 by myener            #+#    #+#              #
#    Updated: 2020/08/19 04:08:51 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from vector import Vector

print("v1 = Vector([0.0, 1.0, 2.0, 3.0]):")
v1 = Vector([0.0, 1.0, 2.0, 3.0])
print(v1.values)
print(v1.size)
print("\nv2 = Vector((10, 15)):")
v2 = Vector((10, 15))
print(v2.values)
print(v2.size)
print("\nv3 = Vector(3):")
v3 = Vector(3)
print(v3.values)
print(v3.size)
print("\nv4 = v1 + 5:")
v4 = v1 + 5
print(v4.values)
print(v4.size)
print("\nv5 = v2 - 18:")
v5 = v2 - 18
print(v5.values)
print(v5.size)
print("\nv6 = v1 + v4:")
v1 = Vector([0.0, 1.0, 2.0, 3.0])
v6 = v1 + v4
print(v6.values)
print(v6.size)