# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    TP2.py                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/24 19:04:30 by myener            #+#    #+#              #
#    Updated: 2020/07/13 23:12:40 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from time import sleep
from random import randrange

somme_joueur = 100
while somme_joueur > 0:
	somme_joueur = int(somme_joueur)
	print("Vous disposez actuellement de", somme_joueur, "euros.\n")
	somme_misee = input("Quelle montant souhaitez-vous miser ? ")
	while True:
		try:
			somme_misee = int(somme_misee)
			break
		except ValueError:
			somme_misee = input("Vous ne pouvez miser que des chiffres. Réessayez: ")
	while somme_misee < 0:
		somme_misee = input("Vous ne pouvez pas miser une somme négative. Réessayez: ")
		somme_misee = int(somme_misee)
	while somme_misee > somme_joueur:
		somme_misee = input("Vous n'êtes pas aussi riche! Réessayez: ")
		somme_misee = int(somme_misee)
	nb_joueur = input("Sur quel numéro souhaitez-vous miser ? (de 0 à 49)")
	nb_joueur = int(nb_joueur)
	while nb_joueur < 0 and nb_joueur > 49:
		nb_joueur = input("Désolé, ce numéro n'est pas valide ! Réessayez: ")
		nb_joueur = int(nb_joueur)
	nb_roulette = randrange(0, 50)
	print("La roulette est lancée, veuillez patienter...")
	sleep(3)
	print("Numéro donné par la roulette:", nb_roulette)
	sleep(2)
	if nb_joueur == nb_roulette:
		print("C'est gagné, félicitations ! Vous remportez le triple de votre mise.")
		somme_joueur += somme_misee * 3
	elif nb_joueur % 2 == 0 and nb_roulette % 2 == 0:
		print("Les deux numéros sont noirs, Vous remportez 50% de votre mise.")
		somme_joueur += somme_misee / 2
	elif nb_joueur % 2 != 0 and nb_roulette % 2 != 0:
		print("Les deux numéros sont rouges, Vous remportez 50% de votre mise.")
		somme_joueur += somme_misee / 2
	else:
		print("Désolé, vous avez perdu votre mise...")
		somme_joueur -= somme_misee
	sleep(2)
	play_again = input("Voulez-vous rejouer ? [y/n] ")
	if play_again == 'n':
		print("Vous terminez cette partie avec", somme_joueur, "euros. À la prochaine !")
		exit()
print("Vous n'avez plus d'argent ! À la prochaine.")
