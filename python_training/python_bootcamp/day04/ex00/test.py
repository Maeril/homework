# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 00:15:58 by myener            #+#    #+#              #
#    Updated: 2020/07/10 00:22:45 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from FileLoader import FileLoader
loader = FileLoader()
data = loader.load("./solar_system_census.csv")
loader.display(data, 12)