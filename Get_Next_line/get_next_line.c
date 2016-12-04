/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:34:05 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/04 19:15:25 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// peut etre pas top car *line n'est pas remis a NULL
// pour palier a ça : faire un tmp qui prend la valeur de line (pas l'adresse je suppose) par ex avec un strdup
// puis free et mettre a NULL line (= strdel ?)
// puis faire *line = strjoin(tmp, buff)
void	ft_realloc_line(char **line, char *buff)
{
	if (*line == NULL)
		*line = ft_strdup(buff);
	else
	{
		free(*line);
		*line = ft_strjoin(*line, buff);
	}
}



int		get_next_line(const int fd, char **line)
{
	int		i;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	i = 0;
	ret = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		//printf("%s\n", buff);
		ft_realloc_line(line, buff);
		//printf("%s\n\n", *line);
	}
	printf("FINAL : %s\n", *line);

	return (0);
}
