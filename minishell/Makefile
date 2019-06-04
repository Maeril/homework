# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 15:49:54 by myener            #+#    #+#              #
#    Updated: 2019/06/04 16:17:37 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re
NAME = minishell

SRCDIR	:=	./
OBJDIR	:=	./objs

SRCS = 

FLAGS = -Wall -Wextra -Werror

OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))
LIBPRINTF = libft/ft_printf/libftprintf.a
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBPRINTF) $(LIBFT) minishell.h
	@printf "\e[36m Creating: \e[32m$(NAME)\n"
	@gcc $(FLAGS) $(LIBFT) $(LIBPRINTF) $(OBJS) -o minishell

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

$(LIBPRINTF):
	@make -C libft/ft_printf

$(LIBFT):
	@make -C libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[34m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@printf "\e[34m Cleaning minishell:	\e[0m$(OBJDIR)\e[0m\n"
	@rm -rf $(OBJDIR)
	@make clean -C libft/ft_printf
	@make clean -C libft

fclean: clean
	@printf "\e[36m Removing: \e[0m"
	@printf "\e[32mminishell \e[0m\n"
	@rm -rf minishell libft/ft_printf/libftprintf.a libft/libft.a

re: fclean $(NAME)
