# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 21:20:38 by myener            #+#    #+#              #
#    Updated: 2019/03/17 00:17:03 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		:=	cleaner.c				\
			dispatcher.c			\
			finalizer.c				\
			ft_printf.c				\
			parser.c				\
			printer.c				\
			typeis_int.c			\
			typeis_char.c			\
			typeis_unsign.c			\
			typeis_str.c			\
			typeis_ptr.c			\
			typeis_octal.c			\
			typeis_hexl.c			\
			typeis_hexu.c			\
			typeis_perc.c			\
			typeis_float.c

OBJ		:=	$(SRCS:.c=.o)
NAME 	:=	libftprintf.a

FLAGS 	:=	-Wall -Wextra -Werror -I./libft/H

all: $(NAME)

$(NAME): libft $(OBJ)
	@gcc -c $(FLAGS) $(SRC)
	@ar rcs $(NAME) $(OBJ)

libft:
	@make -C libft

clean :
	@rm -rf $(OBJ)
	@make -C libft clean

fclean : clean
	@rm -rf $(NAME)
	@make -C libft fclean

re : fclean all

.PHONY: all clean fclean re