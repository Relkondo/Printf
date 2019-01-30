# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:44:30 by scoron            #+#    #+#              #
#    Updated: 2019/01/21 15:55:51 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

SRCS = main.c \
	   parse.c \
	   printf.c \
	   support.c \
	   flags.c \
	   convert_speci.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : lib $(OBJS)
		@gcc -o $(NAME) $(OBJS) -I libft/includes -L libft/ -lft

%.o : %.c
	@gcc -I libft/includes -c $< -o $@

clean :
	@make -C libft/ clean
	@/bin/rm -f $(OBJS)

fclean : clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re : fclean all

lib :
	@make -C libft/

push : fclean
	@git add -A
	@git commit -m "quick push"
	@git push origin master
	git status

.PHONY: all, clean, fclean, re, push, lib
