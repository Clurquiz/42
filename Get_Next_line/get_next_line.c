/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/10 19:37:37 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_find_or_create(t_file **begin, int fd)
{
	t_file	*new;
	t_file	*current;

	current = *begin;
	while (current && fd != current->fd)
		current = current->next;
	if (current == NULL)
	{
		current = *begin;
		if (!(new = (t_file *)malloc(sizeof(*new))))
			return ;
		new->fd = fd;
		new->endbuff = NULL;
		new->next = NULL;
		if (*begin == NULL)
			*begin = new;
		else
		{
			while (current->next)
				current = current->next;
			current->next = new;
		}
	}
}

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
	static t_file	*file;
	t_file			*current;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (!line)
		return (-1);
	ft_find_or_create(&file, fd);
	current = file;
	while (fd != current->fd)
		current = current->next;
	*line = NULL;
	if (ft_work_on_buffers(current->endbuff, &(current->endbuff), line) == 1)
		return (1);
	while ((ret = read(current->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_work_on_buffers(buff, &(current->endbuff), line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (*line != NULL)
		return (1);
	return (0);
}
