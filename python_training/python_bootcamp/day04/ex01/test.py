# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 00:15:58 by myener            #+#    #+#              #
#    Updated: 2020/07/11 19:33:31 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from FileLoader import FileLoader
loader = FileLoader()
data = loader.load("./athlete_events.csv")
from YoungestFella import youngestFella
print(youngestFella(data, 2004))