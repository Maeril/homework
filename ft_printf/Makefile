# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 22:13:37 by myener            #+#    #+#              #
#    Updated: 2019/02/14 21:20:44 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLDIR	:=	-I./libft

SRC = clean_data.c \
	  find_type.c \
	  ft_printf.c \
	  parser.c \
	  spec_instructions.c \
	  print_width.c \
	  flag_minus.c \
	  width_and_precision.c \
	  print_octal.c \
	  conv_octal.c \
	  pourcentage.c \
	  libft/ft_putchar.c \
	  libft/ft_putstr.c \
	  libft/ft_putnbr.c \
	  libft/ft_strsub.c \
	  libft/ft_atoi.c \
	  libft/ft_itoa.c \
	  libft/ft_strlen.c \
	  libft/ft_intlen.c \
	  libft/ft_strdup.c

FLAGS = -Wall -Werror -Wextra $(INCLDIR)

all: $(NAME)

OBJ = clean_data.o \
	  find_type.o \
	  ft_printf.o \
	  parser.o \
	  spec_instructions.o \
	  print_width.o \
	  flag_minus.o \
	  width_and_precision.o \
	  print_octal.o \
	  conv_octal.o \
	  pourcentage.o \
	  libft/ft_putchar.o \
	  libft/ft_putstr.o \
	  libft/ft_putnbr.o \
	  libft/ft_strsub.o \
	  libft/ft_atoi.o \
	  libft/ft_itoa.o \
	  libft/ft_strlen.o \
	  libft/ft_intlen.o \
	  libft/ft_strdup.o

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
