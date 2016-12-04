# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curquiza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 17:08:05 by curquiza          #+#    #+#              #
#    Updated: 2016/12/04 12:08:31 by curquiza         ###   ########.fr        #
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
DIR_LIB = libft/

all : $(NAME)

$(LIB) :
	@make -C $(DIR_LIB)

$(NAME) : $(LIB) $(OBJ)
	@$(CC) $^ $(LIB) -o $@
	@echo "Make $@ : \033[1;32mOK\033[0m"

%.o: %.c
	@$(CC) -o $@ -c $<
	@echo "Make $@ : \033[1;32mOK\033[0m"

clean :
	@make clean -C $(DIR_LIB)
	@echo "Make $@_libft : \033[1;33mOK\033[0m"
	@rm -f $(OBJ)
	@echo "Make $@ : \033[1;32mOK\033[0m"

fclean : clean
	@make fclean -C $(DIR_LIB)
	@echo "Make $@_libft : \033[1;33mOK\033[0m"
	@rm -f $(NAME)
	@echo "Make $@ : \033[1;32mOK\033[0m"

re : fclean all
