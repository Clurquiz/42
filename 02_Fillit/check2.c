/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:18:28 by baparis           #+#    #+#             */
/*   Updated: 2016/12/04 13:12:42 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** VÉRIFICATION DU FICHIER INPUT - SUITE
** Les focntions suivantes se font après un strsplit
*/

/*
** Check la longueur des grands blocs (doit être égale à 4)
** Retourne 1 si ok, 0 sinon
*/

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

/*
** Retourne le nombre de connections d'un bloc '#' en position [i][j]
** càd le nombre de blocs autour de lui
*/

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
	return (cpt);
}

/*
** Check si le tetri est valide
** Retorune 1 si ok, 0 sinon
*/

int	ft_check_tetriminos(char **tab)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	j = 0;
	cpt = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				cpt = cpt + ft_checkaround(tab, i, j);
			j++;
		}
		i++;
		if (i % 4 == 0)
		{
			if (cpt <= 4)
				return (0);
			cpt = 0;
		}
	}
	return (1);
}
