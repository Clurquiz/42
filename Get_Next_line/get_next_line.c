/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/11 18:18:06 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_file	*ft_find_or_create(t_file **begin, int fd)
{
	t_file	*new;
	t_file	*current;

	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (NULL);
	new->fd = fd;
	if (!(new->buff = ft_strnew(BUFF_SIZE)))
		return (NULL);
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

int		ft_work_with_buff(char *buff, char **line)
{
	int		i;
	int		start;
	char	*tmp_sub;
	char	*tmp_line;

	//if (!buff)
	//	return (0);
	i = 0;
	start = 0;
	while (i < BUFF_SIZE && *buff != '\n')
	{
		if (*buff == '\0')
			start = i + 1;
		buff++;
		i++;
	}
	tmp_sub = ft_strsub(buff - i, start, i - start);
	//printf("tmp_sub = %s\n", tmp_sub);
	tmp_line = *line;
	*line = ft_strjoin(tmp_line, tmp_sub);
	ft_strdel(&tmp_line);
	ft_strdel(&tmp_sub);
	printf("*line = %s\n", *line);
	//*buff = NULL;
	if (*buff  == '\n')
	{
		printf("plop\n");
		*buff = '\0';
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
	int				ret;

	if (!line)
		return (-1);
	current = ft_find_or_create(&file, fd);
	*line = NULL;
	if (ft_work_with_buff(current->buff, line) == 1)
		return (1);
	while ((ret = read(current->fd, current->buff, BUFF_SIZE)) > 0)
	{
		(current->buff)[ret] = '\0';
		if (ft_work_with_buff(current->buff, line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (*line != NULL)
	{
		printf("plouf");	
		return (1);
	}
	return (0);
}
