# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ex01_02.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/28 10:23:28 by myener            #+#    #+#              #
#    Updated: 2020/08/28 10:39:20 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import MySQLdb as db
import csv
import sys

connection = db.connect (host = "souscritootest.cuarmbocgsq7.eu-central-1.rds.amazonaws.com", \
user = "testread", passwd = "testread", db = "souscritootest")

data = connection.cursor()

data.execute ("select * from Clients_CRM")

with open("query.csv", "w", newline='') as csv_file:
	csv_writer = csv.writer(csv_file)
    csv_writer.writerow([i[0] for i in data.description])
    csv_writer.writerows(data)

data.execute ("select * from Calls")

# Not too sure how to concatenate both tables before inputing in csv so I had to double the actions
with open("query.csv", "w", newline='') as csv_file:
	csv_writer = csv.writer(csv_file)
    csv_writer.writerow([i[0] for i in data.description])
    csv_writer.writerows(data)

data.close ()
connection.close ()
sys.exit()