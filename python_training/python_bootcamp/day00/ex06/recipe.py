# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    recipe.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/14 00:05:57 by myener            #+#    #+#              #
#    Updated: 2020/06/14 20:51:04 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cookbook = {"Sandwich": {"ingredients": ("ham", "bread", "cheese", "tomatoes"), "meal type": "lunch", "prep time": 10},
          "Cake": {"ingredients": ("flour", "sugar", "eggs"), "meal type": "dessert", "prep time": 60},
		  "Salad": {"ingredients": ("avocado", "arugula", "tomatoes", "spinach"), "meal type": "lunch", "prep time": 15}}

def		is_arg_int(str):
	try:
		int(str)
		return True
	except ValueError:
		return False

def		add_recipe(recipe_name, ingredients, meal_type, prep_time):
	if (recipe_name not in cookbook):
		cookbook[recipe_name] = {"ingredients": ingredients, "meal type": meal_type, "prep_time": prep_time}
	else:
		print("Recipe already exists !")

def		print_recipe(recipe):
	if (recipe in cookbook):
		print(recipe) # prints first layer of dictionary key
		for i in cookbook[recipe]:
			print(i, ':', cookbook[recipe][i])
	else:
		print("Recipe not found :(")

def		delete_recipe(recipe):
	if (recipe in cookbook):
		del(cookbook[recipe]) # prints first layer of dictionary key
	else:
		print("Recipe not found :(")

def		print_cookbook():
	for i, nested_dict in cookbook.items():
		print(i, ':') # prints first layer of dictionary key
		for j in nested_dict:
			print(j, ':', nested_dict[j]) # prints second layer of dictionary key + its values
		print('', end='\n')

print("Please select an option by typing the corresponding number:")
input_number = input("1: Add a recipe \n2: Delete a recipe \n3: Print a recipe\n4: Print the cookbook\n5: Quit\n>> ")
while (is_arg_int(input_number) == False) or ((is_arg_int(input_number) == True) and (int(input_number) > 5) or (int(input_number) < 1)):
	input_number = input("\nThis option does not exist, please type the corresponding number.\nTo exit, enter 5.\n>> ")
input_number = int(input_number)
while (input_number != 5):
	if (input_number == 4):
		print("\nPrinting cookbook:\n")
		print_cookbook()
	elif (input_number == 3):
		recipe_name = input("Please enter the name of the recipe you wish to see:\n>> ")
		print_recipe(recipe_name)
	elif (input_number == 2):
		recipe_name = input("Please enter the name of the recipe you wish to delete:\n>> ")
		delete_recipe(recipe_name)
	elif (input_number == 1):
		recipe_name = input("Please enter the name of the recipe you wish to create:\n>> ")
		ingredients = input("Please enter the ingredients:\n>> ")
		meal_type = input("What's the meal type ?\n>> ")
		prep_time = input("What's the meal's prep time ?\n>> ")
		while (is_arg_int(prep_time) == False) or ((is_arg_int(prep_time) == True) and (int(prep_time) > 60) or (int(prep_time) < 1)):
			prep_time = input("\nIncorrect prep time, please try again.\n>> ")
		prep_time = int(prep_time)
		add_recipe(recipe_name, '(' + ingredients + ')', meal_type, prep_time)
	input_number = input(">> ")
	while (is_arg_int(input_number) == False) or ((is_arg_int(input_number) == True) and (int(input_number) > 5) or (int(input_number) < 1)):
		input_number = input("\nThis option does not exist, please type the corresponding number.\nTo exit, enter 5.\n>> ")
	input_number = int(input_number)

if (input_number == 5):
	print("\nCookbook closed.")
exit()
