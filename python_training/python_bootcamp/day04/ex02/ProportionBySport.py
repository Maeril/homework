# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ProportionBySport.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/10 00:25:05 by myener            #+#    #+#              #
#    Updated: 2020/07/11 23:27:08 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pandas as pd

def proportionBySport(df, year, sport, gender):
	GenderTotal = len(df.loc[(df["Year"] == year) & (df["Sex"] == gender)]["Name"].unique())
	SportGenderTotal = len(df.loc[(df["Year"] == year)  & (df["Sport"] == sport) & (df["Sex"]== gender)]["Name"].unique())
	return SportGenderTotal / GenderTotal