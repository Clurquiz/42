/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/09 17:18:38 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_use_buff(char **line, char *buff, char **endbuff)
{
	int		i;
	char	*tmp_sub;
	char	*tmp_line;

	if (ft_strchr(buff, '\n'))
	{
		i = 0;
		while (buff[i] != '\n')
			i++;
		tmp_sub = ft_strsub(buff, 0, i);
		tmp_line = *line;
		*line = ft_strjoin(tmp_line, tmp_sub);
		ft_strdel(&tmp_line);
		ft_strdel(&tmp_sub);
		ft_strdel(endbuff);
		*endbuff = ft_strdup(ft_strchr(buff, '\n') + 1);
		return (1);
	}
	tmp_line = *line;
	*line = ft_strjoin(tmp_line, buff);
	ft_strdel(&tmp_line);
	return (0);
}

int		ft_use_endbuff(char **endbuff, char **line)
{
	int		i;
	char	*tmp;

	*line = NULL;
	if (!(*endbuff) || !(**endbuff))
		return (0);
	if (ft_strchr(*endbuff, '\n'))
	{
		i = 0;
		while ((*endbuff)[i] != '\n')
			i++;
		*line = ft_strsub(*endbuff, 0, i);
		tmp = *endbuff;
		*endbuff = ft_strdup(ft_strchr(*endbuff, '\n') + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(*endbuff);
	ft_strdel(endbuff);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*endbuff;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	if (!line)
		return (-1);
	if (ft_use_endbuff(&endbuff, line) == 1)
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_use_buff(line, buff, &endbuff) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (*line != NULL)
		return (1);
	return (0);
}
