# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    multipli.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 18:34:45 by myener            #+#    #+#              #
#    Updated: 2020/02/17 01:57:30 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/python3.7
# -*-coding:utf-8 -*

import os

def table(nb, max):
	i = 1 # perso je l'init a 1 comme on va demarrer la table à 1.
	while i <= max:
		print(i, "*", nb, "=", i * nb)
		i += 1

# test: si la fonction est executée seule et pas appelée, elle affiche uniquement
# la table de 7.
if __name__ == "__main__":
	table(7)