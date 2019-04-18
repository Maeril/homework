# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 21:20:38 by myener            #+#    #+#              #
#    Updated: 2019/04/18 12:39:15 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME    =   libftprintf.a

SRCDIR	:=	./
OBJDIR	:=	./objs

SRCS	=   printf_libft/ft_abs.c				\
			printf_libft/ft_atoi.c				\
			printf_libft/ft_atoll.c				\
			printf_libft/ft_bzero.c				\
			printf_libft/ft_strlen.c 			\
			printf_libft/ft_memset.c 			\
			printf_libft/ft_putchar.c 			\
			printf_libft/ft_putstr.c 			\
			printf_libft/ft_putnbr.c			\
			printf_libft/ft_putnbr_base.c		\
			printf_libft/ft_putunbr_base.c		\
			printf_libft/ft_putnbr_long.c		\
			printf_libft/ft_putunbr_long.c		\
			printf_libft/ft_strnew.c 			\
			printf_libft/ft_strcmp.c 			\
			printf_libft/ft_strsub.c 			\
			printf_libft/ft_strdup.c 			\
			printf_libft/ft_itoc.c   			\
			printf_libft/ft_lltoa.c  			\
			printf_libft/ft_intlen.c 			\
			printf_libft/ft_octlen.c 			\
			printf_libft/ft_hexlen.c			\
			printf_libft/ft_uintlen.c			\
			cleaner.c           				\
			dispatcher.c        				\
			finalizer.c         				\
			float_tools.c						\
			ft_printf.c         				\
			parser.c            				\
			parser_helper.c						\
			printer.c           				\
			typeis_int.c						\
			typeis_char.c       				\
			typeis_unsign.c     				\
			typeis_str.c        				\
			typeis_ptr.c        				\
			typeis_octal.c      				\
			typeis_hexl.c       				\
			typeis_hexu.c       				\
			typeis_perc.c       				\
			typeis_float.c

OBJS	:=	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
SRCS	:=	$(addprefix $(SRCDIR)/,$(SRCS))
LIBFT = printf_libft/

CFLAGS  =  -Wall -Wextra -Werror

all:  $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "\e[36m Creating: \e[32m$(NAME)\n"
	@ar -rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[34m Compiling: \e[0m$< -> $@\n"
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) -c $< -o $@

clean :
	@printf "\e[34m Cleaning ft_printf:	\e[0m$(OBJDIR)\e[0m\n"
	@rm -rf $(OBJDIR)

fclean : clean
	@printf "\e[36m Removing: \e[32m$(NAME)\e[0m\n"
	@rm -rf $(NAME)

re : fclean all