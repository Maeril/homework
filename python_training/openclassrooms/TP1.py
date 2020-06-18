# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    TP1.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 17:14:17 by myener            #+#    #+#              #
#    Updated: 2020/02/12 17:53:32 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

a = input("Saisissez l'année à tester puis appuyez sur [Entrée]: ") # choppe l'annee en input
a = int(a) # convertit l'input user de str a int en utilisant le type comme fonction
if a % 4 != 0:
	print("Cette année n'est pas bissextile !")
else:
	if (a % 100 == 0):
		print("Cette année est bien bissextile :)") if (a % 400 == 0) \
		else print("Cette année n'est pas bissextile !")
	else:
		print("Cette année est bien bissextile :)")