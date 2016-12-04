/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:44:30 by baparis           #+#    #+#             */
/*   Updated: 2016/12/01 15:33:37 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Le fichier algo.c avant la mise à la norme de la fontion ft_algo
*/

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

	j = 0;
	i = 0;
	lst->used = 0;
	while (endgrid[j])
	{
		i = 0;
		while (endgrid[j][i])
		{
			if (endgrid[j][i] == lst->letter)
				endgrid[j][i] = '.';
			i++;
		}
		j++;
	}
}

int		ft_algo(t_list *lst, char **endgrid)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = lst;
	while (tmp && tmp->used == 1)
		tmp = tmp->next;
	if (!(tmp))
		return (1);
	while (tmp)
	{
		while (tmp->used == 1 && tmp)
			tmp = tmp->next;
		if (!(tmp))
			return (1);
		while (endgrid[i + 2] != 0 || endgrid[i][j] != '\0')
		{
			if (!(endgrid[i][j]))
			{
				i++;
				j = 0;
			}
			j++;
			if (ft_check_and_place(endgrid, *tmp, i, j) == 1)
			{
				tmp->used = 1;
				if (ft_algo(lst, endgrid))
					return (1);
			}
			ft_erase(tmp, endgrid);
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}
