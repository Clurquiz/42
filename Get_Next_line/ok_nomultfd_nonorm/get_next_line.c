/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/08 17:43:49 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_realloc(char **dst, char *src)
{
	char	*tmp;

	if (dst && src)
	{
		if (*dst == NULL)
			*dst = ft_strdup(src);
		else
		{
			tmp = *dst;
			*dst = ft_strjoin(*dst, src);
			ft_strdel(&tmp);
		}
	}
}

int		ft_use_endbuff(char **endbuff, char **line)
{
	int		i;
	char	*tmp;

	if (!line)
		return (0);
	if (!(*endbuff) || !(**endbuff))
	{
		*line = ft_strdup("\0");
		return (0);
	}
	if (ft_strchr(*endbuff, '\n'))
	{
		i = 0;
		while ((*endbuff)[i] != '\n')
			i++;
		*line = ft_strsub(*endbuff, 0, i);
		tmp = ft_strdup(ft_strchr(*endbuff, '\n') + 1);
		ft_strdel(endbuff);
		*endbuff = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}	
	else
	{
		*line = ft_strdup(*endbuff);
		ft_strdel(endbuff);
		return (0);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*endbuff;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;
	int			i;

	if (ft_use_endbuff(&endbuff, line) == 1)
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n'))
		{
			i = 0;
			while (buff[i] != '\n')
				i++;
			tmp = ft_strsub(buff, 0, i);
			ft_realloc(line, tmp);
			ft_strdel(&tmp);
			ft_strdel(&endbuff);
			endbuff = ft_strdup(ft_strchr(buff, '\n') + 1);
			//ft_realloc(&endbuff, ft_strchr(buff, '\n') + 1);
			return (1);
		}
		ft_realloc(line, buff);
	}
	if (ret < 0)
		return (-1);
	if (*(line[0]) != '\0')
		return (1);
	return (0);
}
