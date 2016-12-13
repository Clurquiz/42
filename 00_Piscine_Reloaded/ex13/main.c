#include <stdlib.h>
#include <stdio.h>

int			ft_recursive_factorial(int nb);

int			main(int argc, char **argv)
{
	int		a;
	if (argc != 2)
		return (0);
	a = atoi(argv[1]);
	printf ("a = %d\n", a);
	printf ("factorielle a = %d\n", ft_recursive_factorial(a));
	return (0);
}
