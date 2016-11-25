/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:18:28 by baparis           #+#    #+#             */
/*   Updated: 2016/11/25 15:24:12 by baparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_rowlen(char **tab)
{
	while (*tab)
	{
		if (ft_strlen(*tab) != 4)
			return (0);
		tab++;
	}
	return (1);
}

int	ft_checkaround(char **tab, int i, int j)
{
	int	cpt;

	cpt = 0;
	if (tab[i][j + 1] == '#')
		cpt++;
	if (i % 4 != 0 && tab[i - 1][j] == '#')
		cpt++;
	if (i % 4 != 3 && tab[i + 1][j] == '#')
		cpt++;
	if (j != 0 && tab[i][j - 1] == '#')
		cpt++;
	if (cpt == 0)
		return (0);
	return (1);
}

int	ft_check_tetriminos(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#' && ft_checkaround(tab, i, j) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
