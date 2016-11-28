/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:10:28 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/28 19:40:49 by curquiza         ###   ########.fr       */
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

void		ft_fill_tabblock(t_list *lst)
{
	int		i;
	int		k;
	char	*tmp;

	tmp = lst->tetri1d;
	i = 0;
	k = 0;
	while (*tmp)
	{
		if (*tmp == '#')
		{
			lst->tab_block[i] = k;
			i++;
		}
		tmp++;
		if (*tmp != '\n')
			k++;
	}
}

t_list		*ft_create_elem(char *tetri1d, int num)
{
	t_list	*new;

	if (tetri1d == NULL)
		return (NULL);
	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->used = 0;
	new->letter = 'A' + num;
	new->tetri1d = ft_strdup(tetri1d);
	new->tetri2d = ft_strsplit(new->tetri1d, '\n');
	ft_fill_tabblock(new);
	new->next = NULL;
	return (new);
}

t_list		*ft_fill_lst(char *av)
{
	int		cpt;
	t_list	*lst;
	char	*file;

	lst = NULL;
	file = ft_read_and_fill(av);
	cpt = 0;
	while (*file)
	{
		ft_lst_pushback(&lst, ft_create_elem(ft_strsub(file, 0, 20), cpt));
		file = file + 20;
		if (*file)
			file++;
		cpt++;
	}
	return (lst);
}
