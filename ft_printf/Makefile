# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 21:20:38 by myener            #+#    #+#              #
#    Updated: 2019/02/17 21:25:13 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	clean_data.c			\
			find_type.c				\
			ft_printf.c				\
			parser.c				\
			spec_instructions.c		\
			print_width.c 			\
			flag_minus.c 			\
			width_and_precision.c	\
			print_octal.c			\
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

