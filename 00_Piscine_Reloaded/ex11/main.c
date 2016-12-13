#include <stdlib.h>
#include <stdio.h>

void		ft_swap(int *a, int *b);
void 		ft_div_mod(int a, int b, int *div, int *mod);

int			main(int argc, char **argv)
{
	int		a;
	int		b;
	int		div;
	int		mod;

	if (argc != 3)
		return (0);
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	div = 0;
	mod = 0;
	printf ("a = %d b = %d\n", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf ("a = %d b = %d div = %d mod = %d\n", a, b, div, mod);
	return (0);
}
