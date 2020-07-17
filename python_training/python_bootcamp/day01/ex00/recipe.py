# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/16 22:38:56 by myener            #+#    #+#              #
#    Updated: 2020/07/02 06:09:03 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Recipe:
	def __init__(self, name, cooking_lvl, cooking_time, ingredients, description, recipe_type):
    	self.name = None
    	self.cooking_lvl = 0
    	self.cooking_time = 0
    	self.ingredients = []
    	self.description = None
    	self.recipe_type = None

def __str__(self):
    """Return the string to print with the recipe info"""
    txt = (self.name, self.description)
    return txt