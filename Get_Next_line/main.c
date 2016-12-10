#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		ret;
	int		cpt;

	cpt = 0;
	if (ac != 2)
		return (0);
	
	//line = ft_strdup("ecole42 => ");
	line = NULL;

	fd = open(av[1], O_RDONLY);

	/*ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	free(line);
	printf("--------------------------\n");
	ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	free(line);
	printf("--------------------------\n");*/
	
	/*while ((ret = get_next_line(fd, &line)) >  0)
	{	
		printf("ret = %d\n", ret);
		printf("line : %s\n", line);
		free(line);
		printf("------------------------\n");
	}
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	free(line);*/
	
	while ((ret = get_next_line(fd, &line)) >  0)
		printf("%s\n", line);
	printf("%s", line);
	//printf("ret = %d\n", ret);
	
	/*while (cpt < 5)
	{
		ret = get_next_line(fd, &line);
		printf("ret = %d\n", ret);
		cpt++;
	}
	printf("ret = %d\n\n", ret);
	printf("line :\n%s", line);*/

	if (close(fd) == -1)
		return (0);
	return (0);
}
