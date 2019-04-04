# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 21:20:38 by myener            #+#    #+#              #
#    Updated: 2019/04/04 14:43:11 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libftprintf.a

SRC_LIBFT=  ./libft/ft_abs.c	\
			./libft/ft_atoi.c	\
			./libft/ft_atoll.c	\
			./libft/ft_bzero.c	\
			./libft/ft_strlen.c \
			./libft/ft_memset.c \
            ./libft/ft_putchar.c \
            ./libft/ft_putstr.c \
            ./libft/ft_putnbr.c \
            ./libft/ft_putnbr_base.c \
            ./libft/ft_putunbr_base.c \
            ./libft/ft_putnbr_long.c \
            ./libft/ft_putunbr_long.c \
            ./libft/ft_strnew.c \
            ./libft/ft_strcmp.c \
            ./libft/ft_strsub.c \
            ./libft/ft_strdup.c \
            ./libft/ft_itoc.c   \
            ./libft/ft_lltoa.c  \
            ./libft/ft_intlen.c \
            ./libft/ft_octlen.c \
            ./libft/ft_hexlen.c \
            ./libft/ft_uintlen.c

SRC     =   cleaner.c           \
            dispatcher.c        \
            finalizer.c         \
            float_tools.c		\
            ft_printf.c         \
            parser.c            \
			parser_helper.c		\
            printer.c           \
            typeis_int.c        \
            typeis_char.c       \
            typeis_unsign.c     \
            typeis_str.c        \
            typeis_ptr.c        \
            typeis_octal.c      \
            typeis_hexl.c       \
            typeis_hexu.c       \
            typeis_perc.c       \
            typeis_float.c

LIBFT   =   libft
OBJ     =   $(SRC:.c=.o)
OBJ_LIBFT=  $(SRC_LIBFT:.c=.o)

CFLAGS  =   -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(OBJ_LIBFT)
	@ar rcs $(NAME) $(OBJ) $(OBJ_LIBFT)

clean :
	@rm -rf $(OBJ) $(OBJ_LIBFT)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re
