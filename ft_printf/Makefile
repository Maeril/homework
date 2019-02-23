# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 21:20:38 by myener            #+#    #+#              #
#    Updated: 2019/02/23 20:35:03 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC		=	clean_data.c			\
			ft_printf.c				\
			parser.c				\
			print_type.c			\
			spec_instructions.c		\
			typeis_int.c			\
			typeis_char.c			\
			typeis_unsign.c			\
			typeis_str.c			\
			typeis_ptr.c			\
			typeis_octal.c			\
			typeis_hexl.c			\
			typeis_hexu.c			\
			typeis_perc.c			\
			width_printer.c

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

