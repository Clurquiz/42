/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:35:34 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/05 18:21:31 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include <stdio.h> //A ENLEVER
# include <fcntl.h> //A ENLEVER => pour open

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_file
{
	int		fd;
	char	*content;
	int		row;
	void	*next;
}					t_file;

char 	*ft_strdup(char *s);
char	*ft_strnew(size_t size);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_strdel(char **as);

int		get_next_line(const int fd, char **line);


#endif
