# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 17:52:34 by myener            #+#    #+#              #
#    Updated: 2019/04/18 12:36:42 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME	=	libft.a

SRCDIR	:=	./
OBJDIR	:=	./objs

SRCS	=	ft_abs.c \
			ft_strdup.c \
			ft_strcmp.c \
			ft_strlen.c \
			ft_atoi.c \
			ft_atoll.c \
			ft_memset.c \
			ft_bzero.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_putnbr_base.c \
			ft_putunbr_base.c \
			ft_putnbr_long.c \
			ft_putunbr_long.c \
			ft_strnew.c \
			ft_strsub.c \
			ft_itoc.c	\
			ft_lltoa.c	\
			ft_intlen.c \
			ft_octlen.c \
			ft_hexlen.c \
			ft_uintlen.c \


OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))

CFLAGS	=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@printf "\e[36m Creating: \e[32m$(NAME)\n"
	@ar -rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[34m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -c $< -o $@

clean :
	@printf "\e[34m Cleaning libft:	\e[0m$(OBJDIR)\e[0m\n"
	@rm -rf $(OBJDIR)

fclean : clean
	@printf "\e[36m Removing: \e[32m$(NAME)\e[0m\n"
	@rm -rf $(NAME)

re : fclean all
