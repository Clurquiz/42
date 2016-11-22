/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:29:23 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/22 16:29:32 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

#define SIZE 1

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putendl(char *str);
void	ft_putstr(char *str);
size_t	ft_strlen(char *str);
char	**ft_strsplit(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_read_and_fill(int fd)
{
	char	buf[SIZE + 1];
	char	*rslt;
	int		ret;
	
	rslt = (char *)malloc(sizeof(*rslt) * 1);
	*rslt = '\0';
	while ((ret = read(fd, buf, SIZE)) != 0)
	{
		buf[ret] = '\0';
		rslt = ft_strjoin(rslt, buf);
	}
	return (rslt);
}


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


// retourne le nb de grand block dans le fichier (strctmt > 1) ou -1 si ya une erreur
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
		return (-1);
	else
		cpt++;
	while (i < len - 2)
	{
		if (ft_strncmp(file, "\n\n\n", 3) == 0)
			return (-1);
		else if (ft_strncmp(file, "\n\n", 2) == 0)
			cpt++;
		file++;
		i++;
	}
	if (*file == '\n' || *(file + 1) != '\n')
		return (-1);
	printf("nbre de grands blocks : %d\n", cpt);
	return (cpt);
}

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
		printf("A");
		if (*file == '\n')
			cpt++;
		if ((ft_strncmp(file, "\n\n", 2) == 0) && cpt != 4)
			return (0);
		else if ((ft_strncmp(file, "\n\n", 2) == 0) && cpt == 4)
		{
			printf("B");
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

//check si toutes les lignes de chaque grand block ont bien une largeur de 4
//retourne 1 si ok, 0 sinon
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

// Affcihe tab_file
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
		printf("pas bon type de char\n");
		return (0);
	}
	if (ft_count_bigblocks(file) == -1)
	{
		printf("erreur separations sur les grands blocks\n");
		return (0);
	}
	printf("%d\n", ft_check_hight(file));
	tab_file = ft_strsplit(file, '\n');
	//ft_print_tabfile(tab_file);
	if (ft_check_rowlen(tab_file) == 0)
	{
		printf("erreur largeur des grands blocks \n");
		return (0);
	}
	return (0);
}
