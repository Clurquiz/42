#include <stdlib.h>
#include <stdio.h>

int			ft_sqrt(int nb);

int			main(int argc, char **argv)
{
	int		a;
	if (argc != 2)
		return (0);
	a = atoi(argv[1]);
	printf ("a = %d\n", a);
	printf ("racine de a = %d\n", ft_sqrt(a));
	return (0);
}
