# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 00:15:58 by myener            #+#    #+#              #
#    Updated: 2020/07/12 01:53:53 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from FileLoader import FileLoader
loader = FileLoader()
data = loader.load("./athlete_events.csv")
from HowManyMedals import howManyMedals
print(howManyMedals(data, 'Kjetil Andr Aamodt'))