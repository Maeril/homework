# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 16:21:39 by myener            #+#    #+#              #
#    Updated: 2019/02/08 15:18:00 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c \

HEADER = ft_printf.h

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)

.c.o: $(SRC)
	@gcc $(FLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: clean fclean
