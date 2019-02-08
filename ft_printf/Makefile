# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpicard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/07 14:07:28 by mpicard           #+#    #+#              #
#    Updated: 2019/02/08 14:19:51 by mpicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		ft_printf

SRC = 		ft_printf.c \
			libft/ft_putchar.c \
			libft/ft_strsub.c \
			specific_cases_instructions.c \
			find_type.c

OBJ = 		ft_printf.o \
			libft/ft_putchar.o \
			libft/ft_strsub.c \
			specific_cases_instructions.o \
			find_type.o

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c -Wall -Wextra -Werror $(SRC)
	gcc $(OBJ) libft/libft.a -o $(NAME)

clean:
	/bin/rm -f $(NAME)
	make fclean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all
