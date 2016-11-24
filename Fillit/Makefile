# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: curquiza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/16 17:08:05 by curquiza          #+#    #+#              #
#    Updated: 2016/11/24 19:19:31 by curquiza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAG = -Wall -Wextra -Werror
SRC = main.c \
	read.c \
	check.c \
	resolve.c \
	ft_lstadd_back.c
OBJ = $(SRC:.c=.o)
LIB = libft.a



all : $(NAME)

$(NAME) : 
	gcc $(FLAG) $(SRC) $(LIB) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
