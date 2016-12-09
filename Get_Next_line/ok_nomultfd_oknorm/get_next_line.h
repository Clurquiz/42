/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:35:34 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/09 17:21:28 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_file
{
	int				fd;
	struct s_file	*next;
}					t_file;

int					ft_use_buff(char **line, char *buff, char **endbuff);
int					ft_use_endbuff(char **endbuff, char **line);
int					get_next_line(const int fd, char **line);

#endif
