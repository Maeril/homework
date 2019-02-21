# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 21:20:38 by myener            #+#    #+#              #
#    Updated: 2019/02/19 18:09:02 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	clean_data.c			\
			find_type.c				\
			ft_printf.c				\
			parser.c				\
			spec_instructions.c		\
			print_all.c 			\
			flag_minus.c 			\
			width_and_precision.c	\
			typeis_int.c			\
			typeis_char.c			\
			typeis_unsign.c			\
			typeis_str.c			\
			typeis_octal.c			\
			typeis_hexl.c			\
			typeis_hexu.c			\
			conv_octal.c			\
			pourcentage.c

FLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@ar -rc $(NAME) $(OBJ)
	@make -C libft/

clean :
	@rm -rf $(OBJ)
	@make -C libft clean

fclean : clean
	@/bin/rm -f $(NAME)
	@make -C libft fclean

re : fclean all

