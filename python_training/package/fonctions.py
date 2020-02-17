# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    fonctions.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 02:08:10 by myener            #+#    #+#              #
#    Updated: 2020/02/17 02:10:55 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/bin/python3.7
# -*-coding:utf-8 -*

import os

def table(nb, max=10):
	i = 1 # perso je l'init a 1 comme on va demarrer la table à 1.
	while i <= max:
		print(i, "*", nb, "=", i * nb)
		i += 1