# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/19 04:08:41 by myener            #+#    #+#              #
#    Updated: 2020/08/20 20:17:00 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from matrix import Matrix

# m0 = Matrix([[0.0, 1.0, 2.0, 3.0], [4.0, 5.0, 6.0, 7.0]])
# print(m0.data)
# print(m0.shape)

# m1 = Matrix((3, 3))
# print(m1.data)
# print(m1.shape)

# m2 = Matrix([[0.0, 1.0, 2.0], [3.0, 4.0, 5.0], [6.0, 7.0, 8.0]], (3, 3))
# print(m2.data)
# print(m2.shape)

m3 = Matrix([[0.0, 1.0, 2.0, 3.0],
                [0.0, 2.0, 4.0, 6.0]])

m4 = Matrix([[0.0, 1.0],
            [2.0, 3.0],
            [4.0, 5.0],
            [6.0, 7.0]])

m5 = Matrix([[0.0, 1.0],
            [2.0, 3.0]])

m6 = Matrix([[10.0, 1.0],
            [2.0, 3.0]])

# print(m3.data)
# print(m3.shape)

# print(m4.data)
# print(m4.shape)

# print(m3.data + m4.data)
print(m3 * m4)
print(m3 + m4)
print(m3 - m4)

print (m5 * m6)
print (m5 + m6)
print (m5 - m6)