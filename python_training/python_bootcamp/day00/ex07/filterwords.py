# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    filterwords.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 21:06:32 by myener            #+#    #+#              #
#    Updated: 2020/06/16 18:28:14 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import re
import sys
import string

def		is_arg_int(str):
	try:
		int(str)
		return True
	except ValueError:
		return False

if (is_arg_int(sys.argv[2]) == False or is_arg_int(sys.argv[1]) == True):
	sys.exit("ERROR")
words_list = [re.sub('^[{0}]+|[{0}]+$'.format(string.punctuation), '', w) for w in sys.argv[1].split() if len(w) > int(sys.argv[2])]
print(words_list)
