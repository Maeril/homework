# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    logging.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 23:56:54 by myener            #+#    #+#              #
#    Updated: 2020/07/07 15:22:35 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import time
from random import randint

def log(func):
    log = open("machine.log", "w")
    def log(*args, **kwargs):
        start = time.time()
        ret = func(*args, **kwargs)
        name = " ".join([word.capitalize() for word in func.__name__.split('_')])
        fmt = "(cmaxtime)Running: {:20s}\t[ exec-time = {:0.3f} {:2s} ]\n"
        with open("logging.log", 'a') as f:
            exec_time = time.time() - start
            f.write(fmt.format(name, exec_time, "s" if exec_time >= 1 else "ms"))
        return ret
    return log

class CoffeeMachine():

    water_level = 100

    @log
    def start_machine(self):
      if self.water_level > 20:
          return True
      else:
          print("Please add water!")
          return False
    @log
    def boil_water(self):
        return "boiling..."

    @log
    def make_coffee(self):
        if self.start_machine():
            for _ in range(20):
                time.sleep(0.1)
                self.water_level -= 1
            print(self.boil_water())
            print("Coffee is ready!")

    @log
    def add_water(self, water_level):
        time.sleep(randint(1, 5))
        self.water_level += water_level
        print("Blub blub blub...")


if __name__ == "__main__":

    machine = CoffeeMachine()
    for i in range(0, 5):
        machine.make_coffee()

    machine.make_coffee()
    machine.add_water(70)