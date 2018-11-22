# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:52:35 by myener            #+#    #+#              #
#    Updated: 2018/11/21 18:49:20 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_memcpy.c\
	  ft_memset.c\
	  ft_strcat.c\
	  ft_strchr.c\
	  ft_strcmp.c\
	  ft_strcpy.c\
	  ft_strdup.c\
	  ft_strlen.c\
	  ft_strncat.c\
	  ft_strncmp.c\
	  ft_strncpy.c\
	  ft_strrchr.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_bzero.c\
	  ft_memccpy.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_memmove.c\
	  ft_strlcat.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putnbr.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_strrev.c

INCLUDES = /includes/

HEADERS = libft.h

OBJECT = $(SRC:.c=.o)

all: $(NAME)

#
#	ENLEVE CE PUTIN DE FCLEAN AVANT DE RENDRE
#

$(NAME): fclean
			gcc $(FLAGS) -c $(SRC)
			ar rc $(NAME) $(OBJECT)

clean:
			rm -f $(OBJECT)

fclean: clean
			rm -f $(NAME)

re: fclean all
