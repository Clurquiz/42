/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/11 17:37:42 by curquiza         ###   ########.fr       */
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
	new->buff = NULL;
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

int		get_next_line(const int fd, char **line)
{
	//static t_file	*file;
	static char		*buff;
	//t_file			*current;
	int				ret;
	int				i;

	if (!line)
		return (-1);
	//current = ft_find_or_create(&file, fd);

	//*line = ft_strdup('\0');
	*line = NULL;
	ret = 0;
	
	if (buff == NULL)
		buff = ft_strnew(BUFF_SIZE);
	
	if (ft_strchr(buff, '\n'))
	{
		i = 0;
		while (buff[i] != '\n')
			i++;
		buff[i] = '\0';
		*line = buff;
		printf("line = %s\n", *line);
		buff = buff + i + 1;
		return (1);
	}
	*line = buff;
	//*buff = '\0';
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	
	if (ret < 0)
		return (-1);
	while (ret > 0 && ft_strchr(buff, '\n') == NULL)
	{
		if (!*line)
		{
			*line = buff;
			printf("*line debut = %s\n", *line);
		}
		else
		{
			printf("ft_strlen(*line) = %zu\n", ft_strlen(*line));
			printf("*line = %s\n", *line);
			*(line + ft_strlen(*line)) = buff;
			//ft_strlcat(*line, buff, ft_strlen(*line) + ft_strlen(buff));
		}
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
	}
	if (ft_strchr(buff, '\n'))
	{
		if (!*line)
			*line = buff;
		else
		{
			i = 0;
			while (buff[i] != '\n')
				i++;
			buff[i] = '\0';
			*(line + ft_strlen(*line) - 1) = buff;
			//ft_strlcat(*line, buff, ft_strlen(*line) + ft_strlen(buff));
			buff = buff + i + 1;
			
		}
		return (1);
	}
	return (0);
}

/*int		get_next_line(const int fd, char **line)
{
	static t_file	*file;
	t_file			*current;
	char			*buff;
	int				ret;

	if (!line)
		return (-1);
	current = ft_find_or_create(&file, fd);
	if (ft_use_endbuff(&(current->endbuff), line) == 1)
		return (1);
	if ((buff = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
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
}*/
