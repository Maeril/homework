# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    whois.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 20:14:48 by myener            #+#    #+#              #
#    Updated: 2020/06/10 20:33:30 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys

def is_arg_int(str):
	try:
		int(str)
		return True
	except ValueError:
		return False

if len(sys.argv) == 1:
	sys.exit()
if is_arg_int(sys.argv[1]) and len(sys.argv) < 3:
	num = int(sys.argv[1])
	if (num == 0):
		print("I'm Zero.")
	elif (num % 2) == 0:
		print("I'm Even.")
	else:
		print("I'm Odd.")
else:
	sys.exit("ERROR")