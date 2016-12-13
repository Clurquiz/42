#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src);

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("%s\n", argv[1]);
	printf("mon strdup : %s\n", ft_strdup(argv[1]));
	printf("le vrai strdup : %s\n", strdup(argv[1]));
}
