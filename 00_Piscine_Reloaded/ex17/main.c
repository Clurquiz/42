#include <stdio.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2);

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	printf("%s %s\n", argv[1], argv[2]);
	printf("mon strcmp : %d\n", ft_strcmp(argv[1], argv[2]));
	printf("le vrai strcmp : %d\n", strcmp(argv[1], argv[2]));
}
