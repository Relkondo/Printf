# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:44:30 by scoron            #+#    #+#              #
#    Updated: 2019/02/09 19:40:49 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = parse.c \
	   printf.c \
	   float_print.c \
	   convert_speci.c \
	   int_print.c \
	   size.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : lib $(OBJS)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o : %.c includes/ft_printf.h
	@clang -Wall -Wextra -Werror -I includes -c $< -o $@

clean :
	@make -C libft/ clean
	@/bin/rm -f $(OBJS)

fclean : clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re : fclean all

lib :
	@make -C libft/

comp : $(NAME) 
	clang main.c -fsanitize=address -g $(NAME) -Iincludes
	
test : comp
	./a.out

push : fclean
	@git add -A
	@git commit -m "quick push"
	@git push origin master
	git status

.PHONY: all, clean, fclean, re, push, lib
