# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:44:30 by scoron            #+#    #+#              #
#    Updated: 2019/02/11 18:11:48 by scoron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS= -Wall -Wextra -Werror

SRCS_NAME = parse.c \
			printf.c \
			float_print.c \
			convert_speci.c \
			int_print.c \
			size.c \

SRCS = $(addprefix srcs/,$(SRCS_NAME))

OBJS = $(addprefix objs/,$(SRCS_NAME:.c=.o))

all : $(NAME)

$(NAME) : lib $(OBJS)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

objs/%.o : srcs/%.c includes/ft_printf.h
	@mkdir -p objs
	@clang $(FLAGS) -I includes -c $< -o $@

clean :
	@make -C libft/ clean
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf objs

fclean : clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re : fclean all

lib :
	@make -C libft/

norme:
	norminette ./libft/
	@echo
	norminette ./includes/
	@echo
	norminette ./srcs/

push : fclean
	@git add -A
	@git commit -m "quick push"
	@git push origin master
	git status

.PHONY: all, clean, fclean, re, push, lib, norme
