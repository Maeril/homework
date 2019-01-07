# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    03.sh                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/05 00:51:08 by myener            #+#    #+#              #
#    Updated: 2019/01/05 01:23uwu6 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

clear
sleep 1
echo "H-hello owo"
sleep 2
echo "What is your blood type ?"
echo "Please enter the corresponding digit. uwu"
echo " "
echo "1) AB    2) A    3) B    4) O"
echo " "
read -p ">> " ans
case $ans in
  1)
   clear
   echo "Did u know ?"
   echo " "
   echo " "
	echo "Your best trait is: CREATIVITY"
   echo " "
	echo "Your worst trait is: CRITICALITY"
   echo " "
   sleep 4
   clear
   echo "Now u know !"
   sleep 2
   echo " "
   echo "Bye-bye uwu"
   sleep 2
   clear
   exit
   ;;

  2)
   clear
   echo "Did u know ?"
   echo " "
   echo " "
	echo "Your best trait is: WARMNESS"
   echo " "
	echo "Your worst trait is: OBSESSIVENESS"
   echo " "
   sleep 4
   clear
   echo "Now u know !"
   sleep 2
   echo " "
   echo "Bye-bye uwu"
   sleep 2
   clear
   exit
   ;;

  3)
   clear
   echo "Did u know ?"
   echo " "
   echo " "
	echo "Your best trait is: PASSION"
   echo " "
	echo "Your worst trait is: IRRESPONSIBILITY"
   echo " "
   sleep 4
   clear
   echo "Now u know !"
   sleep 2
   echo " "
   echo "Bye-bye uwu"
   sleep 2
   clear
   exit
   ;;

  4)
   clear
   echo "Did u know ?"
   echo " "
   echo " "
	echo "Your best trait is: SELF-DETERMINATION"
   echo " "
	echo "Your worst trait is: ARROGANCE"
   echo " "
   sleep 4
   clear
   echo "Now u know !"
   sleep 2
   echo " "
   echo "Bye-bye uwu"
   sleep 2
   clear
   exit
   ;;

   *)
	echo "Sorry, I didn't catch that... Please relaunch the script uwu"
   echo " "
   sleep 3
   exit
	;;
esac