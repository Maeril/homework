# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:14:05 by myener            #+#    #+#              #
#    Updated: 2020/02/09 23:30:53 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
names = os.listdir('.')
names.sort()
for n in names:
	if n[0] != '.':
		print(n)