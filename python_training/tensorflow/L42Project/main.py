# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/31 15:08:08 by myener            #+#    #+#              #
#    Updated: 2020/08/31 15:58:33 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Creer un perceptron multicouches

import numpy as np
import tensorflow as tf
from matplotlib import pyplot as plt
from tensorflow.keras.datasets import mnist
from sklearn.preprocessing import LabelBinarizer
from sklearn.model_selection import train_test_split
import cv2 #opencv

(x_train, y_train), (x_test, y_test) = mnist.load_data()
lb = LabelBinarizer()
labels = lb.fit_transform(labels)
(x_train, x_test, y_train, y_test) = train_test_split(data,
	labels, test_size=0.2, random_state=42)
