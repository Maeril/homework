# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 21:50:49 by myener            #+#    #+#              #
#    Updated: 2020/07/09 22:46:01 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
import numpy as np
from random import sample

k = 4 #the number of centroids
arr = np.genfromtxt('solar_system_census.csv', delimiter=',')
data = arr[1::]
data = np.delete(data, 0, 1)
data = data.astype(int, order='K', casting='unsafe', subok=True, copy=False)
# np.int(data)
# print(data)
# mean = np.mean(data, axis=0)
centroids = sample(list(data), k)
centroids = np.array([*centroids]) # turn into np 2d array for plotting
# np.int(centroids)
# centroids = np.floor(centroids)
centroids = centroids.astype(int, order='K', casting='unsafe', subok=True, copy=False)
print (centroids)
distance = 0
data_distances = np.empty_like(data, subok=True)
for i in range(len(data)):
	for j in range(k):
		# print(f"data[{i}]: {data[i]}\ncentroids[{j}]: {centroids[j]}")
		tmp = round(np.linalg.norm(data[i] - centroids[j]), 2)
		# print(f"distance from centroid {j}: {tmp}")
		if j == 0:
			distance = tmp
			index = 0
		elif j > 0 and tmp < distance:
			distance = tmp
			index = j
	data_distances[i] = index
	# print(f"\nThe closest centroid here is number {index} with {distance}.")
	# print("\n\n")
# data_distances.resize((len(data), 1))
print(data_distances)
c_0 = np.ma.masked_where((data_distances > 0), data)
test = sample(list(c_0), 1)
print(f"test = {test}")
# len = len(data_distances)
# print(f"len = {len}")
# height_mean = round(mean[0], 2)
# weight_mean = round(mean[1], 2)
# bone_mean = round(mean[2], 2)
# print(f"\n\nAccross the Solar System, the average height is {height_mean} cm, average weight is {weight_mean} kgs, and the average bone density is {bone_mean} g/cm².\n")

# People are more slender on Venus than on Earth.
# People of the Martian Republic are taller than on Earth.
# Citizens of the Belt are the tallest of the solar system and have the lowest bone density due to the lack of gravity.

# venus_cluster < weight_mean
# mars_cluster > height_mean
# belt_cluster > height_mean AND < bone_mean
# earth_cluster = what's left

# step 1: remov
# for citizen in data:
	# print(citizen[1])


plt.scatter(data[:,0], data[:,1], 6, c=data[:,1])
# plt.scatter(centroids[:,0], centroids[:,1], 12, c='r')
plt.title("Solar System Census Heightmap")
plt.xlabel("Height")
plt.ylabel("Population")
plt.colorbar()
# plt.show()

# print(data)