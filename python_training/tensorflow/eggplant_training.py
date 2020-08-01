# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    eggplant_training.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/31 00:28:12 by myener            #+#    #+#              #
#    Updated: 2020/07/31 22:24:29 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import tensorflow as tf
import numpy as np

filename_dataset = tf.data.Dataset.list_files("./tf_files/eggplants/*.jpeg")
image_dataset = filename_dataset.map(lambda x: tf.decode_jpeg(tf.read_file(x)))

iterator = image_dataset.make_one_shot_iterator()
next_image = iterator.get_next()

with tf.Session() as sess:
	try:
		while True:
			image_array = sess.run([next_image])
    		print(image_tensor)
	except tf.errors.OutOfRangeError:
		pass


