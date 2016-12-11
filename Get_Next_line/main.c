#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
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

	
	while ((ret = get_next_line(fd, &line)) >  0)
	{	
		printf("ret = %d\n", ret);
		printf("line : %s\n", line);
		ft_strdel(&line);
		printf("------------------------\n");
	}
	printf("ret = %d\n", ret);
	printf("line : %s\n", line);
	ft_strdel(&line);

	/*while ((ret = get_next_line(fd, &line)) >  0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}*/
	
	/*while (cpt < 5)
	{
		ret = get_next_line(fd, &line);
		printf("ret = %d\n", ret);
		printf("%s\n", line);
		printf("------------------\n");
		cpt++;
	}*/

	if (close(fd) == -1)
		return (0);
	return (0);
}
