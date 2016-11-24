/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:25:31 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/24 13:57:21 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fillit.h"

// 1er test : check s'il n'y a que des '.' des '#' et des '\n'
int		ft_check_typeofchar(char *file)
{
	while (*file)
	{
		if (*file != '.' && *file != '#' && *file != '\n')
			return (0);
		file++;
	}
	return (1);
}

// 2nd test : retourne le nb de grand block dans le fichier (strctmt > 1) ou 0 si ya une erreur
// erreur = mauvaise separation ou saut de ligne debut ou fin de fichier
int		ft_count_bigblocks(char *file)
{
	int		cpt;
	int		i;
	int		len;

	len = ft_strlen(file);
	cpt = 0;
	i = 0;
	if (*file == '\n')
		return (0);
	else
		cpt++;
	while (i < len - 2)
	{
		if (ft_strncmp(file, "\n\n\n", 3) == 0)
			return (0);
		else if (ft_strncmp(file, "\n\n", 2) == 0)
			cpt++;
		file++;
		i++;
	}
	if (*file == '\n' || *(file + 1) != '\n')
		return (0);
	return (cpt);
}

// 3eme test : check que chaque grand bloque a bien une hauteur de 4
// renvoie 1 si ok, 0 sinon
int		ft_check_hight(char *file)
{
	int		i;
	int		len;
	int		cpt;

	i = 0;
	cpt = 0;
	len = ft_strlen(file);
	while (i < len - 1)
	{
		if (*file == '\n')
			cpt++;
		if ((ft_strncmp(file, "\n\n", 2) == 0) && cpt != 4)
			return (0);
		else if ((ft_strncmp(file, "\n\n", 2) == 0) && cpt == 4)
		{
			cpt = 0;
			file++;
			i++;
		}
		i++;
		file++;
	}
	if (*file == '\n')
		cpt++;
	if (cpt != 4)
		return (0);
	return (1);
}

// 4ème test : check s'il y a bien 4 '#' dans chaque grands blocks.
int		ft_check_nbblocks(char *file)
{
	int		cpt_block;
	int		i;
	int		len;

	cpt_block = 0;
	i = 0;
	len = ft_strlen(file);
	while (i < len - 1)
	{
		if (*file == '#')
			cpt_block++;
		if (ft_strncmp(file, "\n\n", 2) == 0)
		{
			if (cpt_block != 4)
				return (0);
			cpt_block = 0;
			i++;
			file++;
		}
		i++;
		file++;
	}
	if (*file == '#')
		cpt_block++;
	if (cpt_block != 4)
		return (0);
	return (1);
}

// 5ème test : Vient après le strsplit. Check si toutes les lignes de chaque grand block ont bien une largeur de 4.
// retourne 1 si ok, 0 sinon
int		ft_check_rowlen(char **tab)
{
	while (*tab)
	{
		if (ft_strlen(*tab) != 4)
			return (0);
		tab++;
	}
	return (1);
}

//6ème test : vient après tous les autres tests. Check si le blocks forment un tetriminos
//retourne 1 si ok, 0 sinon

// sous fonction : check si le block touche au moins un autre block (retourne 1 si ok, sinon 0)
int		ft_checkaround(char **tab, int i, int j)
{
	int		cpt;

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


// la fct principale du 6ème test
int		ft_check_tetriminos(char **tab)
{
	int		i;
	int		j;

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
