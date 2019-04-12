# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 21:20:38 by myener            #+#    #+#              #
#    Updated: 2019/04/12 18:37:52 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME    =   libftprintf.a

SRCDIR	:=	./
OBJDIR	:=	./objs

SRCS	=   ./../ft_abs.c				\
			./../ft_atoi.c				\
			./../ft_atoll.c				\
			./../ft_bzero.c				\
			./../ft_strlen.c 			\
			./../ft_memset.c 			\
			./../ft_putchar.c 			\
			./../ft_putstr.c 			\
			./../ft_putnbr.c			\
			./../ft_putnbr_base.c		\
			./../ft_putunbr_base.c		\
			./../ft_putnbr_long.c		\
			./../ft_putunbr_long.c		\
			./../ft_strnew.c 			\
			./../ft_strcmp.c 			\
			./../ft_strsub.c 			\
			./../ft_strdup.c 			\
			./../ft_itoc.c   			\
			./../ft_lltoa.c  			\
			./../ft_intlen.c 			\
			./../ft_octlen.c 			\
			./../ft_hexlen.c			\
			./../ft_uintlen.c			\
			cleaner.c           		\
			dispatcher.c        		\
			finalizer.c         		\
			float_tools.c				\
			ft_printf.c         		\
			parser.c            		\
			parser_helper.c				\
			printer.c           		\
			typeis_int.c				\
			typeis_char.c       		\
			typeis_unsign.c     		\
			typeis_str.c        		\
			typeis_ptr.c        		\
			typeis_octal.c      		\
			typeis_hexl.c       		\
			typeis_hexu.c       		\
			typeis_perc.c       		\
			typeis_float.c

OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))
LIBFT = ../

CFLAGS  =  -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "\e[34m  Creating: \e[32m$(NAME)\n"
	@ar -rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[34m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -c $< -o $@

clean :
	@printf "\e[34m  Cleaning:  \e[0m$(OBJDIR)\e[0m\n"
	@rm -rf $(OBJDIR)
	@rm *.o

fclean : clean
	@printf "\e[34m  Removing: \e[32m$(NAME)\e[0m\n"
	@rm -rf $(NAME)

re : fclean all