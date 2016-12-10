/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/10 20:59:25 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_work_on_buffers(char *buff, char **endbuff, char **line)
{
	int		i;
	char	*tmp_sub;
	char	*tmp_line;

	if (!buff)
		return (0);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	tmp_sub = ft_strsub(buff, 0, i);
	tmp_line = *line;
	*line = ft_strjoin(tmp_line, tmp_sub);
	ft_strdel(&tmp_line);
	ft_strdel(&tmp_sub);
	ft_strdel(endbuff);
	if (ft_strchr(buff, '\n'))
	{
		*endbuff = ft_strdup(ft_strchr(buff, '\n') + 1);
		return (1);
	}
	if (**line == '\0')
		*line = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*endbuff;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (!line)
		return (-1);
	*line = NULL;
	if (ft_work_on_buffers(endbuff, &endbuff, line) == 1)
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_work_on_buffers(buff, &endbuff, line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (*line != NULL)
		return (1);
	return (0);
}
