# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Kmeans.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 21:49:43 by myener            #+#    #+#              #
#    Updated: 2020/07/08 23:54:44 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
import numpy as np

class KmeansClustering:
    def __init__(self, max_iter=20, ncentroid=5):
        self.ncentroid = ncentroid # number of centroids
        self.max_iter = max_iter # number of max iterations to update the centroids
        self.centroids = [] # values of the centroids

arr = np.genfromtxt('solar_system_census.csv', delimiter=',')
data = arr[1::]
data = np.delete(data, 0, 1)
data_shuffled = data
np.random.shuffle(data_shuffled)
venus_centroid = data_shuffled[0]
mars_centroid = data_shuffled[1]
belt_centroid = data_shuffled[2]
earth_centroid = data_shuffled[3]
# print(data)
mean = np.mean(data, axis=0)
height_mean = round(mean[0], 2)
weight_mean = round(mean[1], 2)
bone_mean = round(mean[2], 2)
print(f"Accross the Solar System, the average height is {height_mean} cm, average weight is {weight_mean} kgs, and the average bone density is {bone_mean} g/cm².\n")

    def fit(self, X):
        """
        Run the K-means clustering algorithm.
        For the location of the initial centroids, random pick ncentroids from the dataset.
        Args:
          X: has to be an numpy.ndarray, a matrice of dimension m * n.
        Returns:
          None.
        Raises:
          This function should not raise any Exception.
        """

    def predict(self, X):
        """
        Predict from wich cluster each datapoint belongs to.
        Args:
          X: has to be an numpy.ndarray, a matrice of dimension m * n.
        Returns:
          the prediction has a numpy.ndarray, a vector of dimension m * 1.
        Raises:
          This function should not raise any Exception.
        """