# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 13:04:05 by myener            #+#    #+#              #
#    Updated: 2019/02/15 13:05:33 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	:= make
CC		:= gcc
LD		:= gcc
RM		:= rm -rf

SRCDIR	:=	./
OBJDIR	:=	./objs
INCLDIR	:=	-I./libft
LIBDIR 	:=	libft/

CFLAGS	:=	-Wall -Wextra -Werror $(INCLDIR)
LDFLAGS	:=	-L$(LIBDIR) -lft

SRCS    :=	clean_data.c \
			find_type.c \
			ft_printf.c \
			parser.c \
			spec_instructions.c \
			print_width.c \
			flag_minus.c \
			width_and_precision.c \
			print_octal.c \
			conv_octal.c \
			pourcentage.c \
			libft/ft_putchar.c \
			libft/ft_putstr.c \
			libft/ft_putnbr.c \
			libft/ft_strsub.c \
			libft/ft_atoi.c \
			libft/ft_itoa.c \
			libft/ft_strlen.c \
			libft/ft_intlen.c \
			libft/ft_strdup.c

OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))
LIB		:=	$(LIBDIR)/libft.a
NAME	:=	libftprintf.a

$(NAME): $(LIB) $(OBJS)
	@printf "\e[32m  Creating: \e[0m$(NAME)\n"
	@$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

$(LIB):
	$(MAKE) -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[32m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "\e[32m  Cleaning: \e[0m$(OBJDIR)\e[0m\n"
	@$(RM) $(OBJDIR)
	$(MAKE) -C libft clean

fclean: clean
	@printf "\e[32m  Removing: \e[0m"
	@find . -name "fillit" -exec sh -c 'basename {}' \; | tr "\n" " "
	@echo ""
	@$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
