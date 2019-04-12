# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 21:20:38 by myener            #+#    #+#              #
#    Updated: 2019/04/12 16:09:43 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libftprintf.a

SRC_LIBFT=  ./../ft_abs.c				\
			./../ft_atoi.c				\
			./../ft_atoll.c				\
			./../ft_bzero.c				\
			./../ft_strlen.c 			\
			./../ft_memset.c 			\
			./../ft_putchar.c 			\
			./../ft_putstr.c 			\
			./../ft_putnbr.c			\
			./../ft_putnbr_base.c		\
			./../ft_putunbr_base.c		\
			./../ft_putnbr_long.c		\
			./../ft_putunbr_long.c		\
			./../ft_strnew.c 			\
			./../ft_strcmp.c 			\
			./../ft_strsub.c 			\
			./../ft_strdup.c 			\
			./../ft_itoc.c   			\
			./../ft_lltoa.c  			\
			./../ft_intlen.c 			\
			./../ft_octlen.c 			\
			./../ft_hexlen.c			\
			./../ft_uintlen.c

SRC     =   cleaner.c           		\
			dispatcher.c        		\
			finalizer.c         		\
			float_tools.c				\
			ft_printf.c         		\
			parser.c            		\
			parser_helper.c				\
			printer.c           		\
			typeis_int.c				\
			typeis_char.c       		\
			typeis_unsign.c     		\
			typeis_str.c        		\
			typeis_ptr.c        		\
			typeis_octal.c      		\
			typeis_hexl.c       		\
			typeis_hexu.c       		\
			typeis_perc.c       		\
			typeis_float.c

LIBFT   =   ../
OBJ     =   $(SRC:.c=.o)
OBJ_LIBFT=  $(SRC_LIBFT:.c=.o)

CFLAGS  =  -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(OBJ_LIBFT)
	@ar rcs $(NAME) $(OBJ) $(OBJ_LIBFT)

clean :
	@rm -rf $(OBJ) $(OBJ_LIBFT)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re
