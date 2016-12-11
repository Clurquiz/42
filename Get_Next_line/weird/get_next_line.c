/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/11 13:54:55 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

t_file	*ft_find_or_create(t_file **begin, int fd)
{
	t_file	*new;
	t_file	*current;

	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (NULL);
	new->fd = fd;
	new->endbuff = NULL;
	new->next = NULL;
	if (*begin == NULL)
		*begin = new;
	current = *begin;
	while (current && fd != current->fd)
		current = current->next;
	if (current == NULL)
	{
		current = *begin;
		while (current->next)
			current = current->next;
		current->next = new;
		return (current->next);
	}
	return (current);
}

int		ft_use_buff(char **line, char *buff, char **endbuff)
{
	int		i;
	char	*tmp_sub;
	char	*tmp_line;
	
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
	{
		tmp_sub = ft_strsub(buff, 0, i);
		tmp_line = *line;
		*line = ft_strjoin(tmp_line, tmp_sub);
		ft_strdel(&tmp_line);
		ft_strdel(&tmp_sub);
		*endbuff = NULL;
		//*endbuff = ft_strchr(buff, '\n') + 1;
		*endbuff = buff + i + 1;
		printf("endbuff use_buff = %s\n", *endbuff);
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

	*line = NULL;
	//printf("endbuff use_endbuff = %s\n", *endbuff);
	if (!(*endbuff))
		return (0);
	i = 0;
	while ((*endbuff)[i] && (*endbuff)[i] != '\n')
		i++;
	if ((*endbuff)[i] == '\n')
	{
		*line = ft_strsub(*endbuff, 0, i);
		//*endbuff = ft_strchr(*endbuff, '\n') + 1;
		*endbuff = *endbuff + i + 1;
		return (1);
	}
	*line = ft_strdup(*endbuff);
	if (**line == '\0')
		*line = NULL;
	*endbuff = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_file	*file;
	t_file			*current;
	char			*buff;
	int				ret;

	if (!line)
		return (-1);
	current = ft_find_or_create(&file, fd);
	printf("endbuff  = %s\n", current->endbuff);
	//*line = NULL;
	if (ft_use_endbuff(&(current->endbuff), line) == 1)
		return (1);
	buff = (char *)malloc(sizeof(*buff) *(BUFF_SIZE + 1));
	while ((ret = read(current->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		//printf ("ret  = %d\n", ret);
		//printf ("buff = %s\n", buff);
		if (ft_use_buff(line, buff, &(current->endbuff)) == 1)
		{
			ft_strdel(&buff);
			return (1);
		}
		//ft_strdel(&buff);
	}
	ft_strdel(&buff);
	if (ret < 0)
		return (-1);
	if (*line != NULL)
		return (1);
	return (0);
}
