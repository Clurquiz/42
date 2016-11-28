/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:02:40 by baparis           #+#    #+#             */
/*   Updated: 2016/11/28 12:32:24 by curquiza         ###   ########.fr       */
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

typedef struct		s_list
{
	int				used;
	char			letter;
	char			*tetri1d;
	char			**tetri2d;
	int				tab_block[4];
	struct s_list	*next;
}					t_list;


void				ft_printsolve(char **solve);

// FCT LIBFT
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putendl(char *str);
void				ft_putstr(char *str);
size_t				ft_strlen(char *str);
char				**ft_strsplit(char const *s, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(char *s);
char				*ft_strnew(size_t size);

// FCT DE READ
char				*ft_read_and_fill(char *av);

// FCT DE CHECK.C
int					ft_check_typeofchar(char *file);
int					ft_count_bigblocks(char *file);
int					ft_check_hight(char *file);
int					ft_check_nbblocks(char *file);

// FCT DE CHECK2.C
int					ft_check_rowlen(char **tab);
int					ft_checkaround(char **tab, int i, int j);
int					ft_check_tetriminos(char **tab);

// FCT DE LST_INIT.C
void				ft_lst_pushback(t_list **alst, t_list *new);
void				ft_fill_tabblock(t_list *lst);
t_list				*ft_create_elem(char *tetri1d, int num);
t_list				*ft_fill_lst(char *av);

// FCT DE ALGO.C
int					ft_check_a_position(char **endgrid, t_list lst, int i, int j);
int					ft_check_and_place(char **endgrid, t_list lst, int i, int j);
void				ft_erase(t_list *lst, char **endgrid);
int					ft_algo(t_list *lst, char **endgrid);

//FCT DE MAIN.C
int					ft_check_input(int ac, char **av);
char				**ft_taballoc(int i);
void				ft_print_tabfile(char ** tab);

#endif
