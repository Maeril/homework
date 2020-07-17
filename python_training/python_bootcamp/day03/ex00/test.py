# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 16:55:10 by myener            #+#    #+#              #
#    Updated: 2020/07/07 23:17:29 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from NumPyCreator import NumPyCreator
npc = NumPyCreator()

print(npc.from_list([[1,2,3],[6,3,4]]))
print(npc.from_tuple(("a", "b", "c")))
print(npc.from_iterable(range(5)))
shape=(3,5)
print(npc.from_shape(shape, 2))
print(npc.random(shape))
print(npc.identity(4))