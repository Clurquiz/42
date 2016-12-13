#include <stdlib.h>
#include <stdio.h>

void		ft_swap(int *a, int *b);

int			main(int argc, char **argv)
{
	int		a;
	int		b;
	if (argc != 3)
		return (0);
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf ("a = %d b = %d\n", a, b);
	ft_swap(&a, &b);
	printf ("a = %d b = %d\n", a, b);
	return (0);
}
