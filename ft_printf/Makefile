# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpicard <mpicard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 17:47:18 by mpicard           #+#    #+#              #
#    Updated: 2019/02/11 18:16:10 by mpicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = clean_data.c \
      find_type.c \
      ft_printf.c \
      parser.c \
      spec_instructions.c \
      libft/ft_putchar.c \
      libft/ft_putstr.c \
      libft/ft_putnbr.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

OBJ = clean_data.o \
      find_type.o \
      ft_printf.o \
      parser.o \
      spec_instructions.o \
      ft_putchar.o \
      ft_putstr.o \
      ft_putnbr.o

$(NAME):
    gcc -c $(FLAGS) $(SRC)
    ar -rc $(NAME) $(OBJ)

clean:
    rm -rf $(OBJ)
    make clean -C libft/

fclean: clean
    /bin/rm -f $(NAME)
    make fclean -C libft/

re: fclean all
