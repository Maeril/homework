# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 15:49:54 by myener            #+#    #+#              #
#    Updated: 2019/10/10 16:06:37 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

SRCDIR	:=	./
OBJDIR	:=	./objs

SRCS_NAME_PS =	checker.c				\
				checker_vetting.c		\
				list_manip.c			\
				main.c					\
				movements.c				\
				pipe_cleaner.c			\
				push_swap.c				\
				sorting_algs.c			\
				split.c					\
				tools.c

SRCS_NAME_CH =	checker.c				\
				checker_vetting.c		\
				list_manip.c			\
				main.c					\
				movements.c				\
				pipe_cleaner.c			\
				push_swap.c				\
				sorting_algs.c			\
				split.c					\
				tools.c

FLAGS =	 -Wall -Wextra -Werror -ggdb3

OBJS_PS	:=	$(addprefix $(OBJDIR)/,$(SRCS_NAME_PS:.c=.o))
OBJS_CH	:=	$(addprefix $(OBJDIR)/,$(SRCS_NAME_CH:.c=.o))

SRCS_PS	:=	$(addprefix $(SRCDIR)/,$(SRCS_NAME_PS))
SRCS_CH	:=	$(addprefix $(SRCDIR)/,$(SRCS_NAME_CH))

LIBPRINTF = libft/ft_printf/libftprintf.a
LIBFT = libft/libft.a

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(OBJS_PS) $(LIBPRINTF) $(LIBFT) push_swap.h
	@printf "\e[36m Creating: \e[32m$(NAME_PS)\n"
	@gcc $(FLAGS) $(LIBFT) $(LIBPRINTF) $(OBJS_PS) -o $(NAME_PS)

$(NAME_CH): $(OBJS_CH) $(LIBPRINTF) $(LIBFT) push_swap.h
	@printf "\e[36m Creating: \e[32m$(NAME_CH)\n"
	@gcc $(FLAGS) $(LIBFT) $(LIBPRINTF) $(OBJS_CH) -o $(NAME_CH)

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
	@printf "\e[34m Cleaning push_swap:	\e[0m$(OBJDIR)\e[0m\n"
	@rm -f $(OBJ_PS) $@
	@rm -f $(OBJ_CH) $@
	@rm -rf $(OBJDIR)
	@make clean -C libft/ft_printf
	@make clean -C libft

fclean: clean
	@printf "\e[36m Removing: \e[0m"
	@printf "\e[32mpush_swap \e[0m\n"
	@rm -f $(NAME_PS) $@
	@rm -f $(NAME_CH) $@
	@rm -rf libft/ft_printf/libftprintf.a libft/libft.a

re: fclean all

.PHONY: all, clean, fclean, re