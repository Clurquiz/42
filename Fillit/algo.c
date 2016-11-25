/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:44:30 by baparis           #+#    #+#             */
/*   Updated: 2016/11/25 15:28:45 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_case(char **endgrid, int i, int j)
{
	if (endgrid[i][j] == '$' || endgrid[i][j] == '#' || endgrid[i][j] == '\0')
		return (0);
	return (1);
}

int		ft_check_a_position(char **endgrid, t_list *lst, i, j)
{
	int		k;
	int		l;

	k = 0;
	while ((lst->tetri2d)[k])
	{
		l = 0;
		while ((lst->tetri2d)[k][l])
		{
			l++;
		}
		
		k++;
	}
}


int		ft_check_and_place(char **endgrid, t_list *lst)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

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
			if (endgrid[j][i] == c)
				endgrid[j][i] = '.';
			i++;
		}
		j++;
	}
}

int		ft_algo(t_list *lst, char **endgrid)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->used == 1)
		tmp = tmp->next;
	if (!(tmp))
		return (1);
	while (tmp)
	{
		while (tmp->used == 1 && tmp)
			tmp = tmp->next;
		if (ft_check_and_place(endgrid, c, *tmp))
		{
			tmp->used = 1;
			if (ft_algo(c + 1, lst, endgrid))
				ft_erase(tmp, endgrid, c);
			else
				return (1);
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}

