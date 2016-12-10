#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	int		ret;
	int		cpt;

	cpt = 0;
	if (ac != 4)
	{
		printf ("3 fichiers differents\n");
		return (0);
	}
	
	//line = ft_strdup("ecole42 => ");
	line = NULL;

	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);

	
	printf("FILE DESCRPTOR 1 :\n");
	ret = get_next_line(fd1, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	free(line);
	printf("--------------------------\n");
	printf("FILE DESCRPTOR 2 :\n");
	ret = get_next_line(fd2, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	free(line);
	printf("--------------------------\n");
	printf("FILE DESCRPTOR 3 :\n");
	ret = get_next_line(fd3, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	free(line);
	printf("--------------------------\n");
	printf("--------------------------\n");
	
	printf("FILE DESCRPTOR 1 :\n");
	while ((ret = get_next_line(fd1, &line)) >  0)
	{	
		printf("ret = %d\n", ret);
		printf("line : %s\n", line);
		free(line);
		printf("------------------------\n");
	}
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	free(line);
	printf("------------------------\n");
	
	printf("FILE DESCRPTOR 2 :\n");
	while ((ret = get_next_line(fd2, &line)) >  0)
	{	
		printf("ret = %d\n", ret);
		printf("line : %s\n", line);
		free(line);
		printf("------------------------\n");
	}
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	free(line);
	printf("------------------------\n");

	printf("FILE DESCRPTOR 3 :\n");
	while ((ret = get_next_line(fd3, &line)) >  0)
	{	
		printf("ret = %d\n", ret);
		printf("line : %s\n", line);
		free(line);
		printf("------------------------\n");
	}
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	free(line);

	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
