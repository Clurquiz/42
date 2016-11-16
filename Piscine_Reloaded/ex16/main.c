#include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("%s", argv[1]);
	printf("\n%d", ft_strlen(argv[1]));
}
