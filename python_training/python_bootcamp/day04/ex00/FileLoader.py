# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    FileLoader.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/09 22:48:40 by myener            #+#    #+#              #
#    Updated: 2020/07/10 00:22:09 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import pandas as pd

class FileLoader:
	def load(self, path):
		df = pd.read_csv(path)
		print(f"Loading dataset of dimensions {df.shape[0]} x {df.shape[1]}")
		return df
	def display(self, df, n):
		if n >= 0:
			print (pd.DataFrame.head(df, n))
		else:
			print (pd.DataFrame.tail(df, n))
