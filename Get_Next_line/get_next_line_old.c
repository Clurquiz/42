/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:34:05 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/05 13:02:56 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// peut etre pas top car *line n'est pas remis a NULL
// pour palier a ça : faire un tmp qui prend la valeur de line (pas l'adresse je suppose) par ex avec un strdup
// puis free et mettre a NULL line (= strdel ?)
// puis faire *line = strjoin(tmp, buff)
void	ft_realloc_and_fill(char **dst, char *buff)
{
	if (dst && buff)
	{
		if (*dst == NULL)
			*dst = ft_strdup(buff);
		else
		{
			free(*dst);
			*dst = ft_strjoin(*dst, buff);
		}
	}
}

int		ft_check_newline(char *tmp)
{
	while (tmp)
	{
		if (*tmp == '\n')
			return (1);
		tmp++;
	}
	return (0);
}

void	ft_keep_line(char *tmp)
{
	if (tmp)
	{
		while (tmp && *tmp != '\n')
			tmp++;
		if (*tmp == '\n')
			tmp++;
		*tmp = '\0';
	}
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	char			buff[BUFF_SIZE + 1];
	char static		*tmp_line;
	int				ret;

	i = 0;
	ret = 0;
	//tmp_line = NULL;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ft_realloc_and_fill(&tmp_line, buff);
		//if (ft_check_newline(buff) == 1)
		//	break;
	}
	printf("tmp_lin = %s\n", tmp_line);
	ft_keep_line(tmp_line);
	printf("tmp_lin = %s\n", tmp_line);
	ft_realloc_and_fill(line, tmp_line);
	//free(tmp_line);

	return (0);
}
