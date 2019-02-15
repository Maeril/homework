# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 13:04:05 by myener            #+#    #+#              #
#    Updated: 2019/02/15 13:51:31 by myener           ###   ########.fr        #
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
			pourcentage.c

OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))
LIB		:=	$(LIBDIR)/libft.a
NAME	:=	libftprintf.a

$(NAME): $(LIB) $(OBJS)
	@printf "\e[94m  Creating: \e[0m$(NAME)\n"
	@$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

$(LIB):
	@$(MAKE) -C libft/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[94m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "\e[94m  Cleaning: \e[0m$(OBJDIR)\e[0m\n"
	@$(RM) $(OBJDIR)
	@$(MAKE) -C libft clean

fclean: clean
	@printf "\e[94m  Removing:\e[0m libftprintf.a"
	@echo ""
	@$(RM) $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
