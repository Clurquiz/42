/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:43:03 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/03 18:23:57 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

#define SIZE 1

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[SIZE];

	ret = 0;
	if (ac == 1)
		write(1, "File name missing.\n", 19);
	else if (ac > 2)
		write(1, "Too many arguments.\n", 20);
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (0);
		while ((ret = read(fd, buf, SIZE)) != 0)
		{
			buf[ret] = '\0';
			write(1, buf, 1);
		}
		if (close(fd) == -1)
			return (0);
	}
	return (0);
}
