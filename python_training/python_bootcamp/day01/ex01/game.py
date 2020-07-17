# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    game.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/02 05:21:07 by myener            #+#    #+#              #
#    Updated: 2020/07/02 06:29:58 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class GotCharacter:
	def __init__(self, first_name, is_alive):
		self.first_name = first_name
		self.is_alive = True

class Targaryen(GotCharacter):
	"""A class representing the Targaryen family. They're all batshit crazy."""
	def __init__(self, first_name, is_alive=True):
		super().__init__(first_name, is_alive=is_alive)
		self.family_name = "Targaryen"
		self.house_words = "Fire and Blood"
	def	print_house_words(self):
		print(self.house_words)
	def die(self):
		self.is_alive = False