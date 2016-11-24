/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:28:38 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/24 13:39:31 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Affiche tab_file
void	ft_print_tabfile(char **tab)
{
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	char	*file;
	char	**tab_file;

	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	tab_file = NULL;
	file = ft_read_and_fill(fd);
	//ft_putstr(file);

	if (ft_check_typeofchar(file) == 0)
	{
		printf("erreur type de char\n");
		return (0);
	}
	if (ft_count_bigblocks(file) == 0)
	{
		printf("erreur separations sur les grands blocks\n");
		return (0);
	}
	else
		printf("nbre de grands blocks : %d\n", ft_count_bigblocks(file));
	if (ft_count_bigblocks(file) > 26)
	{
		printf("erreur nb de grands blocks supérieur à 26\n");
		return (0);
	}
	if (ft_check_hight(file) == 0)
	{
		printf("erreur hauteur des grands blocks\n");
		return (0);
	}
	if (ft_check_nbblocks(file) == 0)
	{
		printf("erreur nb de blocks (#)\n");
		return (0);
	}
	tab_file = ft_strsplit(file, '\n');
	ft_print_tabfile(tab_file);
	if (ft_check_rowlen(tab_file) == 0)
	{
		printf("erreur largeur des grands blocks \n");
		return (0);
	}
	printf("\ncheck tetriminos valide : %d\n", ft_check_tetriminos(tab_file));
	return (0);
}
