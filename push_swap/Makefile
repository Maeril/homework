# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/16 15:49:54 by myener            #+#    #+#              #
#    Updated: 2020/01/06 18:50:41 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

SRCDIR	:=	./
OBJDIR	:=	./objs

SRCS_NAME_PS =	bonus.c					\
				checker.c				\
				checker_vetting.c		\
				cleaner.c				\
				insertion_sort.c		\
				list_manip.c			\
				main.c					\
				movements.c				\
				push_swap.c				\
				quicksort.c				\
				split.c					\
				tools.c

SRCS_NAME_CH =	bonus.c					\
				checker.c				\
				checker_vetting.c		\
				cleaner.c				\
				insertion_sort.c		\
				list_manip.c			\
				main.c					\
				movements.c				\
				push_swap.c				\
				quicksort.c				\
				split.c					\
				tools.c

FLAGS =	 -Wall -Wextra -Werror -I libft

OBJS_PS	:=	$(addprefix $(OBJDIR)/,$(SRCS_NAME_PS:.c=.o))
OBJS_CH	:=	$(addprefix $(OBJDIR)/,$(SRCS_NAME_CH:.c=.o))

SRCS_PS	:=	$(addprefix $(SRCDIR)/,$(SRCS_NAME_PS))
SRCS_CH	:=	$(addprefix $(SRCDIR)/,$(SRCS_NAME_CH))

LIBFT = libft/libft.a

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(OBJS_PS) $(LIBFT) push_swap.h
	@printf "\e[36m Creating: \e[32m$(NAME_PS)\n"
	@gcc $(OBJS_PS) $(LIBFT) -o $(NAME_PS)
	@printf "\033[0m"

$(NAME_CH): $(OBJS_CH) $(LIBPRINTF) $(LIBFT) push_swap.h
	@printf "\e[36m Creating: \e[32m$(NAME_CH)\n"
	@gcc $(OBJS_CH) $(LIBFT) -o $(NAME_CH)
	@printf "\033[0m"

$(LIBFT):
	@make -C libft

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[34m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) -c $< -o $@
	@printf "\033[0m"

clean:
	@printf "\e[34m Cleaning push_swap:	\e[0m$(OBJDIR)\e[0m\n"
	@rm -f $(OBJ_PS) $@
	@rm -f $(OBJ_CH) $@
	@rm -rf $(OBJDIR)
	@make clean -C libft
	@printf "\033[0m"

fclean: clean
	@printf "\e[36m Removing: \e[0m"
	@printf "\e[32mpush_swap \e[0m\n"
	@printf "\e[36m Removing: \e[0m"
	@printf "\e[32mchecker \e[0m\n"
	@rm -f $(NAME_PS) $@
	@rm -f $(NAME_CH) $@
	@rm -rf libft/libft.a
	@printf "\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re