# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    generator.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 06:37:15 by myener            #+#    #+#              #
#    Updated: 2020/07/03 08:21:04 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from datetime import datetime

def generator(text, sep=" ", option=None):
	'''Option is an optional arg, sep is mandatory'''
	if (isinstance(text, str) is False):
		print("Error: text is not a string")
		return
	if (option == None):
		for i in text.split(sep):
			yield (i)
	elif (option == "shuffle"):
		word_list = set()
		timey = int(datetime.utcnow().timestamp())
		wimey = int(str(timey)[-1])
		text_split = text.split(sep)
		while len(word_list) < len(text_split):
			for i in text_split:
				if text_split.index(i) == wimey:
					if i not in word_list:
						word_list.add(i)
						yield (i)
	elif (option == "unique"):
		word_list = set()
		for i in text.split(sep):
			if i not in word_list:
				word_list.add(i)
				yield (i)
	elif (option == "ordered"):
		for i in sorted(text.split(sep)):
			yield (i)
	else:
		print("Unsupported option")
		return