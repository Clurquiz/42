/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:25:31 by curquiza          #+#    #+#             */
/*   Updated: 2016/12/04 12:59:57 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** VERIFICATION DU FICHIER INPUT
*/

/*
** Check qu'il y a seulement des '.', des '#' et des retours à la ligne
** Retourne 1 si ok, 0 sinon.
*/
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

/*
** Compte le nombre de grands blocs
** Retourne le compte, donc 0 s'il y a un souci
*/
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

/*
** Check la hauteur de chaque grand bloc (doit être égale à 4)
** Retourne 1 si ok, 0 sinon
*/
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
		if (file[i] == '\n')
			cpt++;
		if ((ft_strncmp(file + i, "\n\n", 2) == 0) && cpt != 4)
			return (0);
		else if ((ft_strncmp(file + i, "\n\n", 2) == 0) && cpt == 4)
		{
			cpt = 0;
			i++;
		}
		i++;
	}
	if (file[i] == '\n')
		cpt++;
	if (cpt != 4)
		return (0);
	return (1);
}

/*
** Check que le nombre de blocs ('#') est bien égal à 4
** Retourne 1 si ok, 0 sinon
*/
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
		if (file[i] == '#')
			cpt_block++;
		if (ft_strncmp(file + i, "\n\n", 2) == 0)
		{
			if (cpt_block != 4)
				return (0);
			cpt_block = 0;
			i++;
		}
		i++;
	}
	if (file[i] == '#')
		cpt_block++;
	if (cpt_block != 4)
		return (0);
	return (1);
}
