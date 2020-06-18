# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test3.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:49:48 by myener            #+#    #+#              #
#    Updated: 2020/02/17 01:39:42 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os, sys, string

def main():
	pattern = string.join(sys.argv[1:])
	filename = os.environ['HOME'] + '/.telbase'
	prog = regex.compile(pattern, regex.casefold)
	f = open(filename, 'r')
	while 1:
		line = f.readline()
		if not line: break # End of file
		if prog.search(line) >= 0:
			print(string.strip(line))
main()