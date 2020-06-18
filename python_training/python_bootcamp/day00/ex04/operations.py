# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    operations.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/12 02:04:05 by myener            #+#    #+#              #
#    Updated: 2020/06/12 02:25:50 by myener           ###   ########.fr        #
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
	sys.exit("Usage: python operations.py <number1> <number2>\nExample:\n\tpython operations.py 10 3")
elif is_arg_int(sys.argv[1]) and is_arg_int(sys.argv[2]) and len(sys.argv) == 3:
	num1 = int(sys.argv[1])
	num2 = int(sys.argv[2])
	print("Sum:\t\t", num1 + num2)
	print("Difference:\t", num1 - num2)
	print("Product:\t", num1 * num2)
	if (num2 != 0):
		print("Quotient:\t", num1 / num2)
	else:
		print("Quotient:\t ERROR (div by zero)")
	if (num2 != 0):
		print("Remainder:\t", num1 % num2)
	else:
		print("Remainder:\t ERROR (modulo by zero)")
	sys.exit()
elif len(sys.argv) < 3:
	print("InputError: not enough arguments\n")
elif len(sys.argv) > 3:
	print("InputError: too many arguments\n")
else:
	print("InputError: only numbers\n")
sys.exit("Usage: python operations.py <number1> <number2>\nExample:\n\tpython operations.py 10 3")