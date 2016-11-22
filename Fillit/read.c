/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:29:23 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/22 15:10:18 by curquiza         ###   ########.fr       */
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
		if (*file == '\n' && *(file + 1) == '\n' && *(file + 2) == '\n')
			return (-1);
		else if (*file == '\n' && *(file + 1) == '\n')
			cpt++;
		file++;
		i++;
	}
	if (*file == '\n' || *(file + 1) != '\n')
		return (-1);
	return (cpt);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*file;

	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	file = ft_read_and_fill(fd);


	//ft_putstr(file);
	if(ft_check_typeofchar(file) == 0)
	{
		printf("pas bon type de char\n");
		return (0);
	}
	printf("%d\n", ft_count_bigblocks(file));
	return (0);
}
