/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/12 13:12:47 by curquiza         ###   ########.fr       */
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
	/*i = 0;
	printf("buff = ");
	while (i <= BUFF_SIZE)
	{
		printf("%c", buff[i]);
		i++;
	}
	printf("\n");*/
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
	tmp_line = *line;
	*line = ft_strjoin(tmp_line, tmp_sub);
	ft_strdel(&tmp_line);
	ft_strdel(&tmp_sub);
	if (*buff  == '\n')
	{
		*buff = '\0';
		return (1);
	}
	if (**line == '\0')
		*line = NULL;
	//ft_bzero(buff, i - start);
	ft_bzero(buff - i, BUFF_SIZE);
	
	//i = 0;
	//printf("buff = ");
	//while (i <= BUFF_SIZE)
	//{
	//	printf("%c", buff[i]);
	//	i++;
	//}
	//printf("\n");

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
		//ft_bzero(current->buff, BUFF_SIZE);
	}
	if (ret < 0)
		return (-1);
	if (*line != NULL)
	{
		//printf("plouf");	
		return (1);
	}
	//ft_strdel(&(current->buff));
	return (0);
}
