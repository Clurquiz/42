#include "get_next_line.h"

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
	printf("line : %s", line);
	printf("--------------------------\n");
	ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s", line);
	printf("--------------------------\n");
	ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s", line);
	printf("--------------------------\n");
	ret = get_next_line(fd, &line);
	printf("ret = %d\n", ret);
	printf("line : %s", line);
	printf("--------------------------\n");*/

	int		i = 0;
	while ((ret = get_next_line(fd, &line)) >  0)
	{	
		i++;
		printf("ret = %d\n", ret);
		printf("line : %s\n", line);
		printf("------------------------\n");
		//ft_strdel(&line);
	}
	printf("ret = %d\n", ret);
	printf("line : %s", line);
	printf("\ni =  %d", i);
	
	/*while ((ret = get_next_line(fd, &line)) >  0)
		printf("%s", line);
	printf("%s", line);
	//printf("ret = %d\n", ret);*/
	
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
