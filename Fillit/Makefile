# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curquiza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 17:08:05 by curquiza          #+#    #+#              #
#    Updated: 2016/11/29 18:06:38 by curquiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc $(FLAG)
FLAG = -Wall -Wextra -Werror
SRC = main.c \
	read.c \
	check.c \
	check2.c \
	lst_init.c \
	algo.c
OBJ = $(SRC:%.c=%.o)
LIB = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $^ $(LIB) -o $@
	@echo "Make $@ : \033[1;32mOK\033[0m"

%.o: %.c
	@$(CC) -o $@ -c $<

clean :
	@rm -f $(OBJ)
	@echo "Make $@ : \033[1;32mOK\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "Make $@ : \033[1;32mOK\033[0m"

re : fclean $(NAME)
