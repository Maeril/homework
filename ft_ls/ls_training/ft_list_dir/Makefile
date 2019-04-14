# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 16:41:39 by myener            #+#    #+#              #
#    Updated: 2019/04/14 22:45:43 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re
NAME = ft_list_dir

SRCDIR	:=	./
OBJDIR	:=	./objs

SRCS =	ft_list_dir.c

FLAGS = -Wall -Wextra -Werror

OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))
LIB = ls_libft/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIB) ft_list_dir.h
	@printf "\e[34m  Creating: \e[32m$(NAME)\n"
	@gcc $(FLAGS) $(LIB) $(OBJS) -o ft_list_dir

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

$(LIB):
	@make -C ls_libft/ft_printf

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[34m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@printf "\e[34m  Cleaning ft_list_dir:  \e[0m$(OBJDIR)\e[0m\n"
	@rm -rf $(OBJDIR)
	@make clean -C ls_libft/ft_printf

fclean: clean
	@printf "\e[34m  Removing: \e[0m"
	@printf "\e[32m ft_list_dir \e[0m\n"
	@rm -rf ft_list_dir ls_libft/ft_printf/libftprintf.a

re: fclean $(NAME)
