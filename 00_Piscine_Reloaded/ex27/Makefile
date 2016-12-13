NAME = ft_display_file
FLAG = -Wall -Wextra -Werror
SRC = main.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : 
	gcc $(FLAG) $(SRC) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
