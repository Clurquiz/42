/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:10:28 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/25 15:46:34 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Pas possible de prendre celui de la libft car pas la meme structure
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

// Creer un maillon
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
	new->next = NULL;
	return (new);
}

// Remplit la liste chainee = ajoute des maillons en fonction du nombre de grands blocks
void		ft_fill_lst(t_list **alst, char *file)
{
	int		cpt;

	cpt = 0;
	while (*file)
	{
		ft_lst_pushback(alst, ft_create_elem(ft_strsub(file, 0, 20), cpt));
		file = file + 20;
		if (*file)
			file++;
		cpt++;
	}
}

// POUR TEST : affiche les composants de chaque maillon
void		ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("used : %d\n", lst->used);
		printf("letter : %c\n", lst->letter);
		printf("tetri1d :\n%s", lst->tetri1d);
		printf("tetri2d :\n");
		while (*(lst->tetri2d))
		{
			printf("%s\n", *(lst->tetri2d));
			(lst->tetri2d)++;
		}
		printf("\n");
		lst = lst->next;
	}
}

t_list		*ft_lstinit(char *av)
{
	t_list	*lst;
	char	*file;

	lst = NULL;
	file = ft_read_and_fill(av);
	ft_fill_lst(&lst, file);
	return (lst);
}

// VERSION FOIREUSE CLEM
/*t_list		*ft_create_lst(char *file)
{
	t_list	*lst;
	t_list	*start;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	start = lst;
	while (*file)
	{
		if (!(lst = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		lst->used = 0;
		lst->tetri1d = ft_strsub(file, 0, 20);
		lst->tetri2d = ft_strsplit(lst->tetri1d, '\n');
		lst->next = NULL;
		lst = lst->next;
		file = file + 20;
		if (*file)
			file++;
	}
	return (start);
}*/

// VERSION FOIREUSE BASTIEN
/*t_list	*ft_create_lst(char *file)
{
	t_list	*lst;
	int	i;

	i = 0;
	lst = NULL;
	if (file)
	{
		if (!(lst->tetri1d = (char*)malloc(sizeof(char) * 20)))
			return(NULL);
		if (!(lst->tetri2d = (char**)malloc(sizeof(char*) * 4)))
			return (NULL);
		while (i < 4)
			if (!(lst->tetri2d[i++] = (char*)malloc(sizeof(char) * 5)))
				return (NULL);
		lst->used = 0;
		ft_strncpy(lst->tetri1d, file, 19);
		lst->tetri1d[20] = '\0';
		i = 0;
		while (i < 4)
		{
			ft_strncpy(lst->tetri2d[i], file + (5 * i), 4);
			lst->tetri2d[i++][5] = '\0';
		}
		lst->next = ft_create_lst(file + 21);
		return (lst);
	}
	return (NULL);
}*/
