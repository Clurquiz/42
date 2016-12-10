/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/10 22:29:28 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		//ft_strdel(endbuff);
		*endbuff = ft_strchr(buff, '\n') + 1;
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
	//char	*tmp;

	printf("endbuff = %s\n", *endbuff);
	*line = NULL;
	//if (!(*endbuff) || !(**endbuff))
	if (!(*endbuff))
		return (0);
	if (ft_strchr(*endbuff, '\n'))
	{
		i = 0;
		while ((*endbuff)[i] != '\n')
			i++;
		*line = ft_strsub(*endbuff, 0, i);
		*endbuff = *endbuff + i + 1;
		//tmp = *endbuff;
		//*endbuff = ft_strdup(ft_strchr(*endbuff, '\n') + 1);
		//ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(*endbuff);
	endbuff = NULL;
	//ft_strdel(endbuff);
	return (0);
}

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
	if (ft_use_endbuff(&(current->endbuff), line) == 1)
		return (1);
	while ((ret = read(current->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_use_buff(line, buff, &(current->endbuff)) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (*line != NULL)
		return (1);
	return (0);
}
