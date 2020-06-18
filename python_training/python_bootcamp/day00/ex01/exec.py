# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    exec.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 19:09:27 by myener            #+#    #+#              #
#    Updated: 2020/06/10 20:13:49 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

arguments = str()
for i in sys.argv[1:]:
    arguments += i + ' '
arguments = arguments[:-1]
arguments = arguments[::-1]
print(arguments.swapcase())
