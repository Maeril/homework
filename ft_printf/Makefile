# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 21:20:38 by myener            #+#    #+#              #
#    Updated: 2019/04/11 14:52:07 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libftprintf.a

SRC_LIBFT=  ./printf_libft/ft_abs.c			\
			./printf_libft/ft_atoi.c			\
			./printf_libft/ft_atoll.c			\
			./printf_libft/ft_bzero.c			\
			./printf_libft/ft_strlen.c 		\
			./printf_libft/ft_memset.c 		\
			./printf_libft/ft_putchar.c 		\
			./printf_libft/ft_putstr.c 		\
			./printf_libft/ft_putnbr.c			\
			./printf_libft/ft_putnbr_base.c	\
			./printf_libft/ft_putunbr_base.c	\
			./printf_libft/ft_putnbr_long.c	\
			./printf_libft/ft_putunbr_long.c	\
			./printf_libft/ft_strnew.c 		\
			./printf_libft/ft_strcmp.c 		\
			./printf_libft/ft_strsub.c 		\
			./printf_libft/ft_strdup.c 		\
			./printf_libft/ft_itoc.c   		\
			./printf_libft/ft_lltoa.c  		\
			./printf_libft/ft_intlen.c 		\
			./printf_libft/ft_octlen.c 		\
			./printf_libft/ft_hexlen.c			\
			./printf_libft/ft_uintlen.c

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

LIBFT   =   printf_libft
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
