# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    HowManyMedals.py                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 00:25:05 by myener            #+#    #+#              #
#    Updated: 2020/07/12 02:14:11 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pandas as pd

def howManyMedals(df, name):
	Dict = {}
	G = df.loc[(df["Name"] == name) & (df["Medal"] == "Gold")]
	S = df.loc[(df["Name"] == name) & (df["Medal"] == "Silver")]
	B = df.loc[(df["Name"] == name) & (df["Medal"] == "Bronze")]
	TotalYears = df.loc[(df["Name"] == name) & ((df["Medal"] == "Gold") | (df["Medal"] == "Silver") | (df["Medal"] == "Bronze"))]
	i = TotalYears["Year"].min()
	j = 0
	for i in TotalYears["Year"]:
		# print(i)
		# Dict[j] = {'G': G.loc[(df["Name"] == name) & (df["Year"] == i)]}
	return Dict