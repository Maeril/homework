# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    loading.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/16 20:35:36 by myener            #+#    #+#              #
#    Updated: 2020/06/16 22:37:07 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# import sys
# from time import sleep

# unit_color = '\033[5;36m\033[5;47m'
# end_color = '\033[0;0m\033[0;0m'

# count = 45
# for i in range(count):
# 	incre = int(50.0 / count * i)
# 	sys.stdout.write('\r')
# 	if (i != count - 1):
# 		sys.stdout.write('\r' + '|%s%s%s%s| %d%%' % (unit_color, '\033[7m' + ' '*incre + ' \033[27m', end_color, ' '*(50-incre), 2*incre))
# 	else:
# 		sys.stdout.write('\r' + '|%s%s%s%s| %d%%' % (unit_color, '\033[7m' + ' '*20 + 'DONE' + ' '*21) + ' \033[27m', end_color, 100)
# 	sys.stdout.flush()
# 	sleep(0.1)
# sys.stdout.write('\n')

import time
import sys

total = 1007  # total number to reach
bar_length = 30  # should be less than 100
for i in range(total+1):
    percent = 100.0 * (i / total)
    sys.stdout.write('\r')
    sys.stdout.write("Completed: [{:{}}] {:>3}%".format('\033[36;40m \033[0m'*int(percent/(100.0/bar_length)), bar_length, int(percent)))
    sys.stdout.flush()
    time.sleep(0.002)

# def		ft_progress(lst):