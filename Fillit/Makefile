# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curquiza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 17:08:05 by curquiza          #+#    #+#              #
#    Updated: 2016/12/01 12:18:44 by curquiza         ###   ########.fr        #
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
LIB = $(DIR_LIB)libft.a
DIR_LIB = Libft/

all : ($LIB) $(NAME)

($LIB):
	make re -C $(DIR_LIB)

$(NAME) : $(OBJ)
	@$(CC) $^ $(LIB) -o $@
	@echo "Make $@ : \033[1;32mOK\033[0m"

%.o: %.c
	@$(CC) -o $@ -c $<
	@echo "Make $@ : \033[1;32mOK\033[0m"

clean :
	@make clean -C $(DIR_LIB)
	@rm -f $(OBJ)
	@echo "Make $@ : \033[1;32mOK\033[0m"

fclean : clean
	@make fclean -C $(DIR_LIB)
	@rm -f $(NAME)
	@echo "Make $@ : \033[1;32mOK\033[0m"

re : fclean all
