/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:24:27 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/06 18:45:13 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_realloc_and_fill(char **dst, char *buff)
{
	char	*tmp;

	if (dst && buff)
	{
		if (*dst == NULL)
			*dst = ft_strdup(buff);
		else
		{
			tmp = ft_strdup(*dst);
			ft_strdel(dst);
			*dst = ft_strjoin(tmp, buff);
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
		ret = 1;
	tmp = ft_strsub(*endbuff, 0, i);
	ft_realloc_and_fill(line, tmp);
	if (ft_strchr(*endbuff, '\n'))
		ft_realloc_and_fill(endbuff, ft_strchr(*endbuff, '\n') + 1);
	free(tmp);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*endbuff;

	ft_strdel(line);
	if (ft_use_endbuff(&endbuff, line) == 1)
		return (1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && !(ft_strchr(buff, '\n')))
	{
		buff[ret] = '\0';
		ft_realloc_and_fill(line, buff);
	}
	if (ret < 0)
		return (-1);
	buff[ret] = '\0';
	ft_realloc_and_fill(line, buff);
	if (ft_strrchr(buff, '\n'))
		ft_realloc_and_fill(&endbuff, ft_strchr(buff, '\n') + 1);
	
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
		(*line)[i + 1] = '\0';
	
	if (ret == 0)
		return (0);
	return (1);
}

/*int		get_next_line(const int fd, char **line)
{
	int				ret;
	static char		buff[BUFF_SIZE + 1];
	int				i;

	ft_strdel(line);
	if (ft_strrchr(buff, '\n'))
		ft_realloc_and_fill(line, ft_strrchr(buff, '\n') + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && !(ft_strchr(buff, '\n')))
	{
		buff[ret] = '\0';
		ft_realloc_and_fill(line, buff);
	}
	if (ret < 0)
		return (-1);
	buff[ret] = '\0';
	ft_realloc_and_fill(line, buff);
	i = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if ((*line)[i] == '\n')
		(*line)[i + 1] = '\0';
	if (ret == 0)
		return (0);
	return (1);
}*/
