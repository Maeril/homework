# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    YoungestFella.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 00:25:05 by myener            #+#    #+#              #
#    Updated: 2020/07/11 22:47:29 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pandas as pd

def youngestFella(df, year):
	M = df.loc[(df["Year"] == year) & (df["Sex"] == 'M')]["Age"].min()
	F = df.loc[(df["Year"] == year) & (df["Sex"] == 'F')]["Age"].min()
	return {'f' : F, 'm': M}