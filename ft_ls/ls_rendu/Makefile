# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 15:49:54 by myener            #+#    #+#              #
#    Updated: 2019/04/16 19:31:48 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re
NAME = ft_ls

SRCDIR	:=	./
OBJDIR	:=	./objs

SRCS =	ft_ls.c				\
		flag_manager.c		\
		parser.c			\
		initializer.c

FLAGS = -Wall -Wextra -Werror

OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))
LIB = ls_libft/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIB) ft_ls.h
	@printf "\e[36m Creating: \e[32m$(NAME)\n"
	@gcc $(FLAGS) $(LIB) $(OBJS) -o ft_ls

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

$(LIB):
	@make -C ls_libft/ft_printf

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[34m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@printf "\e[34m Cleaning ft_ls:	\e[0m$(OBJDIR)\e[0m\n"
	@rm -rf $(OBJDIR)
	@make clean -C ls_libft/ft_printf
	@rm ls_libft/ft_printf/*.o

fclean: clean
	@printf "\e[36m Removing: \e[0m"
	@printf "\e[32mft_ls \e[0m\n"
	@rm -rf ft_ls ls_libft/ft_printf/libftprintf.a

re: fclean $(NAME)