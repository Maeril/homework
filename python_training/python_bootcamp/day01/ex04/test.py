# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 07:05:50 by myener            #+#    #+#              #
#    Updated: 2020/07/03 07:29:09 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from generator import generator

text = "HENLO you stinky birb"
for word in generator(text, sep=" "):
	print(word)
print("\nSHUFFLE:")
for word in generator(text, sep=" ", option="shuffle"):
	print(word)
print("\nUNIQUE:")
for word in generator(text, sep=" ", option="unique"):
	print(word)
print("\nORDERED:")
for word in generator(text, sep=" ", option="ordered"):
	print(word)