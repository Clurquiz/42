/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:44:30 by baparis           #+#    #+#             */
/*   Updated: 2016/12/01 11:15:38 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_and_place(char **endgrid, t_list lst, int i, int j)
{
	int		k;

	if (endgrid[i][j] != '.')
		return (0);
	k = 1;
	while (k < 4)
	{
		if (endgrid[i + (lst.tab_block[k] / 4 - lst.tab_block[0] / 4)]
					[j + (lst.tab_block[k] % 4 - lst.tab_block[0] % 4)] != '.')
			return (0);
		k++;
	}
	endgrid[i][j] = lst.letter;
	k = 1;
	while (k < 4)
	{
		endgrid[i + (lst.tab_block[k] / 4 - lst.tab_block[0] / 4)]
			[j + (lst.tab_block[k] % 4 - lst.tab_block[0] % 4)] = lst.letter;
		k++;
	}
	return (1);
}

void	ft_erase(t_list *lst, char **endgrid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	lst->used = 0;
	while (endgrid[i])
	{
		j = 0;
		while (endgrid[i][j])
		{
			if (endgrid[i][j] == lst->letter)
				endgrid[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_setnextline(int *i, int *j)
{
	*i = *i + 1;
	*j = 0;
}

int		ft_algo(t_list *lst, char **gri, int i, int j)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp && tmp->used == 1)
		tmp = tmp->next;
	if (!(tmp))
		return (1);
	while (tmp)
	{
		while ((gri[i + 2] != 0 || gri[i][j] != '\0') && tmp && tmp->used == 0)
		{
			if (!(gri[i][j]))
				ft_setnextline(&i, &j);
			if (ft_check_and_place(gri, *tmp, i, ++j) == 1)
			{
				tmp->used = 1;
				if (ft_algo(lst, gri, 0, 0))
					return (1);
			}
			ft_erase(tmp, gri);
		}
		tmp = tmp->next;
	}
	return (0);
}
