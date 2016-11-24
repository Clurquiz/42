/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:29:23 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/24 11:40:09 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"

char	*ft_read_and_fill(int fd)
{
	char	buf[SIZE + 1];
	char	*rslt;
	int		ret;
	
	rslt = (char *)malloc(sizeof(*rslt) * 1);
	*rslt = '\0';
	while ((ret = read(fd, buf, SIZE)) != 0)
	{
		buf[ret] = '\0';
		rslt = ft_strjoin(rslt, buf);
	}
	return (rslt);
}
