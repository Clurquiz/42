/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:02:40 by baparis           #+#    #+#             */
/*   Updated: 2016/11/24 15:11:53 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

# define SIZE 1

typedef struct	s_list
{
	int				used;
	char			*piece1d;
	char			**piece2d;
	struct s_list	*next;
}				t_list;

int					ft_inputchck(int ac, char **av);
void				ft_printsolve(char **solve);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putendl(char *str);
void				ft_putstr(char *str);
size_t				ft_strlen(char *str);
char				**ft_strsplit(char const *s, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_read_and_fill(char *av);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_resolve(int ac, char **av, char **solve);

// ---------

int					ft_check_typeofchar(char *file);
int					ft_count_bigblocks(char *file);
int					ft_check_hight(char *file);
int					ft_check_nbblocks(char *file);
int					ft_check_rowlen(char **tab);
int					ft_check_tetriminos(char **tab);
int					ft_check_input(int ac, char **av);

#endif
