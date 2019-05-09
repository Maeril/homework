# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 15:49:54 by myener            #+#    #+#              #
#    Updated: 2019/05/09 15:57:44 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re
NAME = ft_ls

SRCDIR	:=	./
OBJDIR	:=	./objs

SRCS =	ft_ls.c					\
		flag_manager.c			\
		get_file_info.c			\
		initializer.c			\
		sort_list.c

FLAGS = -g -Wall -Wextra -Werror

OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))
LIBPRINTF = ls_libft/ft_printf/libftprintf.a
LIBFT = ls_libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBPRINTF) $(LIBFT) ft_ls.h
	@printf "\e[36m Creating: \e[32m$(NAME)\n"
	@gcc $(FLAGS) $(LIBFT) $(LIBPRINTF) $(OBJS) -o ft_ls

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

$(LIBPRINTF):
	@make -C ls_libft/ft_printf

$(LIBFT):
	@make -C ls_libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[34m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@printf "\e[34m Cleaning ft_ls:	\e[0m$(OBJDIR)\e[0m\n"
	@rm -rf $(OBJDIR)
	@make clean -C ls_libft/ft_printf
	@make clean -C ls_libft

fclean: clean
	@printf "\e[36m Removing: \e[0m"
	@printf "\e[32mft_ls \e[0m\n"
	@rm -rf ft_ls ls_libft/ft_printf/libftprintf.a ls_libft/libft.a

re: fclean $(NAME)