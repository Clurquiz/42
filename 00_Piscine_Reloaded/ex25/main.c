#include <stdio.h>
#include <unistd.h>

void	ft_foreach(int *tab, int length, void (*f)(int));

void	ft_42(int nb)
{
	//nb = nb + 42;
	printf("%d\n", nb);
}

int		main(void)
{
	int		tab[4] = {48, 97, 98, 100};
	int		length;

	length = 4;
	ft_foreach(tab, length, &ft_42);
	return (0);
}
