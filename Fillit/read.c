/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:29:23 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/04 12:50:45 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Lit l'input et récupère le contenu
** /!\ Fuites de mémoire car malloc non free dans strjoin
*/
char	*ft_read_and_fill(char *av)
{
	int		fd;
	int		ret;
	char	buf[SIZE + 1];
	char	*rslt;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	rslt = (char *)malloc(sizeof(*rslt) * 1);
	*rslt = '\0';
	while ((ret = read(fd, buf, SIZE)) != 0)
	{
		buf[ret] = '\0';
		rslt = ft_strjoin(rslt, buf);
	}
	if (close(fd) == -1)
		return (NULL);
	return (rslt);
}
