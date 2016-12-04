/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:35:34 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/04 19:15:28 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <stdio.h> //A ENLEVER
# include <fcntl.h> //A ENLEVER => pour open

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

char 	*ft_strdup(char *s);

char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

int		get_next_line(const int fd, char **line);


#endif
