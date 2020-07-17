# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    book.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/16 22:38:53 by myener            #+#    #+#              #
#    Updated: 2020/07/02 05:30:35 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import datetime
import recipe

class Book:
	def __init__(self, name, last_update, creation_date, recipes_list):
    	self.name = None
    	self.last_update = datetime.datetime.now()
    	self.creation_date = datetime.datetime.now()
    	self.recipes_list = {"starter", "lunch", "dessert"}

def get_recipe_by_name(self, name):
    """Print a recipe with the name `name` and return the instance"""
    pass

def get_recipes_by_types(self, recipe_type):
    """Get all recipe names for a given recipe_type """
	pass

def add_recipe(self, recipe):
    """Add a recipe to the book and update last_update"""
    pass