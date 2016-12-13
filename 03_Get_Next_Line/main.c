#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;

	if (ac > 2)
		return (0);
	if (ac == 1)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);

	line = NULL;

/*
** test sur 5 lignes sans risque de boucle infinie
*/

	/*ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	ft_strdel(&line);
	printf("--------------------------\n");
	ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	ft_strdel(&line);
	printf("--------------------------\n");
	ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	ft_strdel(&line);
	printf("--------------------------\n");
	ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	ft_strdel(&line);
	printf("--------------------------\n");
	ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	ft_strdel(&line);
	printf("--------------------------\n");
	ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	ft_strdel(&line);
	printf("--------------------------\n");*/


/*	
** test sur tout le fichier avec valeurs de retour
*/

	while ((ret = get_next_line(fd, &line)) >  0)
	{	
		printf("ret = %d\n", ret);
		printf("line : %s\n", line);
		//freeeline);
		ft_strdel(&line);
		printf("------------------------\n");
	}
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	//free(line);
	ft_strdel(&line);

/*
** test sur tout le fichier avec uniquement l'affichauge du fichier
*/

	/*while ((ret = get_next_line(fd, &line)) >  0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}*/
	
	close(fd);

	return (0);
}
