# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 22:13:37 by myener            #+#    #+#              #
#    Updated: 2019/02/12 13:56:53 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLDIR	:=	-I./libft

SRC = clean_data.c \
	  find_type.c \
	  ft_printf.c \
	  parser.c \
	  spec_instructions.c \
	  libft/ft_putchar.c \
	  libft/ft_putstr.c \
	  libft/ft_putnbr.c

FLAGS = -Wall -Werror -Wextra $(INCLDIR)

all: $(NAME)

OBJ = clean_data.o \
	  find_type.o \
	  ft_printf.o \
	  parser.o \
	  spec_instructions.o \
	  libft/ft_putchar.o \
	  libft/ft_putstr.o \
	  libft/ft_putnbr.o

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
