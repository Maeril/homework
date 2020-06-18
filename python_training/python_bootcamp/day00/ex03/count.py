# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    count.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/10 20:35:02 by myener            #+#    #+#              #
#    Updated: 2020/06/10 21:55:12 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import string

def text_analyzer(blabla = ""):
	if (len(blabla) == 0):
		text = input("What is the text to analyse?\n")
	elif (len(blabla) > 0):
		text = blabla
	else:
		sys.exit("ERROR")
	upper,lower,punct,space = 0,0,0,0
	for i in text:
		if (i >= 'A' and i <= 'Z'):
			upper += 1
		elif (i >= 'a' and i <= 'z'):
			lower += 1
		elif (i in string.punctuation):
			punct += 1
		elif (i == ' '):
			space += 1
	print("The text contains ", len(text), "characters:\n")
	if (upper > 0):
		print("- ", upper, " upper letters\n")
	if (lower > 0):
		print("- ", lower, " lower letters\n")
	if (punct > 0):
		print("- ", punct, " punctuation marks\n")
	if (space > 0):
		print("- ", space, " spaces\n")
