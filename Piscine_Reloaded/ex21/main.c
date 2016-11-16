#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		*ft_range(int min, int max);

int		main(int argc, char **argv)
{
	int		min;
	int		max;
	int		i;
	int		*tab;

	if (argc != 3)
		return (0);
	i = 0;
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	tab = ft_range(min, max);
	while (i < max - min)
	{
		printf("%d ", tab[i]);
		i++;
	}
}
