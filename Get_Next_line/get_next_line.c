/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/07 13:33:47 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_realloc_and_add(char **dst, char *src)
{
	char	*tmp;

	if (dst && src)
	{
		if (*dst == NULL)
			*dst = ft_strdup(src);
		else
		{
			tmp = ft_strdup(*dst);
			ft_strdel(dst);
			*dst = ft_strjoin(tmp, src);
			ft_strdel(&tmp);
		}
	}
}

int		ft_use_endbuff(char **endbuff, char **line)
{
	int		i;
	char	*tmp;
	int		ret;

	if (!(*endbuff))
		return (0);
	ret = 0;
	i = 0;
	while ((*endbuff)[i] && (*endbuff)[i] != '\n')
		i++;
	if ((*endbuff)[i] == '\n')
	{
		ret = 1;
		tmp = ft_strsub(*endbuff, 0, i + 1);
	}
	else
		tmp = ft_strsub(*endbuff, 0, i);
	ft_realloc_and_add(line, tmp);
	ft_strdel(&tmp);
	if (ft_strchr(*endbuff, '\n'))
	{
		tmp = ft_strdup(ft_strchr(*endbuff, '\n') + 1);
		ft_strdel(endbuff);
		ft_realloc_and_add(endbuff, tmp);
		ft_strdel(&tmp);
	}
	else
		ft_strdel(endbuff);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*endbuff;
	char		*tmp;
	int			i;

	ft_strdel(line);
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
			tmp = ft_strsub(buff, 0, i + 1);
			ft_realloc_and_add(line, tmp);
			ft_strdel(&tmp);
			ft_strdel(&endbuff);
			ft_realloc_and_add(&endbuff, ft_strchr(buff, '\n') + 1);
			return (1);
		}
		ft_realloc_and_add(line, buff);
	}
	if (ret < 0)
		return (-1);
	return (0);
}
