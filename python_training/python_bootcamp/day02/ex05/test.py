# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 16:16:37 by myener            #+#    #+#              #
#    Updated: 2020/07/07 16:34:33 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from TinyStatistician import TinyStatistician
tstat = TinyStatistician()
a = [1, 42, 300, 10, 59]

print(tstat.mean(a))
# 82,4
print(tstat.median(a))
# 42.0
print(tstat.quartile(a, 25))
# 10.0
print(tstat.quartile(a, 75))
# 59.0
print(tstat.var(a))
# 12279.439999999999
print(tstat.std(a))
# 110.81263465868862