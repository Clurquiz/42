/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:49:16 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/25 15:26:51 by baparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_lst_pushback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst == NULL)
		return ;
	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_list		*ft_create_elem(char *tetri1d, char c)
{
	t_list	*new;

	if (tetri1d == NULL)
		return (NULL);
	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->used = 0;
	new->letter = c;
	new->tetri1d = ft_strdup(tetri1d);
	new->tetri2d = ft_strsplit(new->tetri1d, '\n');
	new->next = NULL;
	return (new);
}

void		ft_fill_lst(t_list **alst, char *file)
{
	char c;

	c = 'A';
	while (*file)
	{
		ft_lst_pushback(alst, ft_create_elem(ft_strsub(file, 0, 20), c++));
		file = file + 20;
		if (*file)
			file++;
	}
}

t_list		*ft_resolve(char *av)
{
	t_list	*lst;
	char	*file;

	lst = NULL;
	file = ft_read_and_fill(av);
	ft_fill_lst(&lst, file);
	return (lst);
}
