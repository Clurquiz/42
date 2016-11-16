/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:56:49 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/03 13:29:48 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_abs.h"

int		main(int ac, char **av)
{
	int		a;
	int		abs;

	if (ac != 2)
		return (0);
	a = atoi(av[1]);
	abs = ABS(a);
	printf("%d\n", abs);	
	printf("%d\n", ABS(a));
	return (0);
}
