/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:34:05 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/05 18:21:28 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_realloc_and_fill(char **dst, char *buff)
{
	char	*tmp;

	if (dst && buff)
	{
		if (*dst == NULL)
			*dst = ft_strdup(buff);
		else
		{
			tmp = ft_strdup(*dst);
			ft_strdel(dst);
			*dst = ft_strjoin(tmp, buff);
			ft_strdel(&tmp);
		}
	}
}

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
	ft_strdel(&tmp);
	if (file->content[i] == '\0')
		return (0);
	else
		return (1);
}

void	ft_init_file(t_file *file, int fd)
{
	file->content = NULL;
	file->fd = fd;
	file->row = 0;
}

int		get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	static t_file	file;

	ret = 0;
	(file.row)++;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ft_realloc_and_fill(&(file.content), buff);
	}
	if (ret < 0)
		return (-1);
	if (file.content == NULL) //cas du fichier vide
		file.content = ft_strdup("\0");
	return (ft_fill_line(&file, line));
}
