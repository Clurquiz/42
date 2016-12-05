/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:34:05 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/05 16:06:07 by curquiza         ###   ########.fr       */
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

void	ft_init_file(t_file *file, int fd)
{
	file->content = NULL;
	file->fd = fd;
	file->row = 0;
}

/*int		ft_check_newline(char *tmp)
{
	while (*tmp)
	{
		if (*tmp == '\n')
			return (1);
		tmp++;
	}
	return (0);
}*/

int		ft_fill_line(t_file *file, char **line)
{
	char	*tmp;
	int		cpt;
	int		start;
	int		i;

	cpt = 0;
	start = 0;
	i = 0;
	while (file->content[i] && cpt <= file->row)
	{
		if (cpt == file->row - 1)
		{
			start = i;
			cpt++;
		}
		if (file->content[i] == '\n')
			cpt++;
		i++;
	}
	tmp = ft_strsub(file->content, start, i - start);
	ft_realloc_and_fill(line, tmp);
	free(tmp);
	if (file->content[i] == '\0')
		return (0);
	else
		return (1);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static t_file	file;

	i = 0;
	ret = 0;
	(file.row)++;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ft_realloc_and_fill(&(file.content), buff);
	}
	if (ret < 0)
		return (-1);
	return (ft_fill_line(&file, line));
}
