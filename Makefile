# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzungula <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/20 09:22:22 by yzungula          #+#    #+#              #
#    Updated: 2018/08/20 10:04:57 by yzungula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler
FLAGS= -Wall -Wextra -Werror
COMPILER= gcc
LIBFT= ./libft/libft.a
FILLER= ./filler.h
SRC=	algos.c\
		filler.c\
		get_data.c\
		play.c\
		seeking_functions.c\
		token.c\
		utilities.c\
		main.c

OBJC= $(SRC: .c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	@make -C ./libft/
	@gcc $(FLAGS)  $(SRC) -L./libft -lft -o $@

clean_libft:
	make  -C libft/ clean

fclean_libft:
	make  -C libft/ fclean

clean: clean_libft
	rm -rf *.o

fclean:  clean
	rm filler

re: fclean all
