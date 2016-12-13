NAME = libft.a
FLAG = -Wall -Wextra -Werror
D_SRC = srcs/
SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
HEADERS = includes
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : 
	gcc $(FLAG) -c $(addprefix $(D_SRC), $(SRC)) -I $(HEADERS)
	ar rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
