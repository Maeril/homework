# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    guess.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/16 20:01:29 by myener            #+#    #+#              #
#    Updated: 2020/06/16 20:34:42 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
from time import sleep
from random import randrange

def		is_arg_int(str):
	try:
		int(str)
		return True
	except ValueError:
		return False

nb = randrange(1, 99)
number_tries = 1;
print("This is an interactive guessing game!\nYou have to enter a number between 1 and 99 to find out the secret number.\nType 'exit' to end the game.\nGood luck!")
sleep(1)
user_input = input("\nWhat's your guess between 1 and 99?\n>> ")
while (user_input != nb):
	while ((is_arg_int(user_input) == False and (user_input != "exit")) or (is_arg_int(user_input) == True and (int(user_input) < 1 or int(user_input) > 99))):
		user_input = input("\nPlease enter a valid number between 1 and 99\n>> ")
	if (is_arg_int(user_input) == True and int(user_input) < nb):
		user_input = input("\nToo low!\n>> ")
		number_tries += 1
	elif (is_arg_int(user_input) == True and int(user_input) > nb):
		user_input = input("\nToo high!\n>> ")
		number_tries += 1
	elif (user_input == "exit"):
		sys.exit("\nGoodbye!")
	else:
		break
if (int(user_input) == nb):
	if (nb == 42):
		print("The answer to the ultimate question of life, the universe and everything is 42.")
	if (number_tries == 1):
		print("Congratulations! You got it on your first try!")
	else:
		print("Congratulations, you've got it!\nYou won in", number_tries, "attempts!")
	sys.exit()