#include <stdio.h>
#include <unistd.h>

void	ft_count_if(int **tab, int (*f)(char*));

void	ft_42(int nb)
{
	//nb = nb + 42;
	printf("%d\n", nb);
}

int		main(int ac, char **av)
{
	int		tab[4];

	if (ac != 5)
		return (0);
	tab[0] = av[1];
	tab[1] = av[2];
	tab[2] = av[3];
	tab[3] = av[4];
	ft_count_if(tab, &ft_42);
	return (0);
}
