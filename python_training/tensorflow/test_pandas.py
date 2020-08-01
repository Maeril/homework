# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_pandas.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/30 22:55:33 by myener            #+#    #+#              #
#    Updated: 2020/07/30 23:23:34 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from __future__ import print_function

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# print(pd.__version__)

california_housing_dataframe = pd.read_csv("https://download.mlcc.google.com/mledu-datasets/california_housing_train.csv", sep=",")
print(california_housing_dataframe.describe())
print(california_housing_dataframe.head())
print(california_housing_dataframe.hist("housing_median_age"))
# plt.show()

city_names = pd.Series(['San Francisco', 'San Jose', 'Sacramento'])
population = pd.Series([852469, 1015785, 485199])

cities = pd.DataFrame({ 'City name': city_names, 'Population': population })
print(type(cities['City name']))

print(np.log(population))