# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    csvreader.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 00:13:32 by myener            #+#    #+#              #
#    Updated: 2020/07/07 15:02:26 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class CsvReader:
	def __init__(self, filename=None, sep=',', header=False, skip_top=0, skip_bottom=0):
		self.filename = filename
		self.sep = sep
		self.has_header = header
		self.skip_top = skip_top
		self.skip_bottom = skip_bottom

	def __enter__(self):
		try:
			self.f = open(self.filename, 'r')
		except FileNotFoundError:
			f.close()
			return None
		if self.has_header is True:
			self.header = self.file.readline().split(self.sep)
		self.data = []
		return self

	def __exit__(self, type, value, traceback):
		self.f.close()

	def	get_data(self):
		return self.data

	def get_header(self):
		return self.header if self.has_header is True else None