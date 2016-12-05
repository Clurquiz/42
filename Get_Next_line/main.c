/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:50:14 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/05 16:06:02 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	if (ac != 2)
		return (0);
	
	//line = ft_strnew(100);
	//line = ft_strdup("ecole42 => ");
	line = NULL;

	fd = open(av[1], O_RDONLY);

	/*get_next_line(fd, &line);
	printf("line : %s", line);
	get_next_line(fd, &line);
	printf("line : %s", line);*/
	
	while (get_next_line(fd, &line) != 0)
		//printf("line : %s", line);
		;

	printf("line : %s", line);
	if (close(fd) == -1)
		return (0);
	return (0);
}
