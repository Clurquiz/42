/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:20:35 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/29 16:41:45 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** La vraie fonction atoi ne prend pas en compte tous les caractères invisibles
** inf. à 32
*/

int		ft_atoi(const char *str)
{
	int		neg;
	int		result;

	neg = 1;
	result = 0;
	while (*str >= 0 && *str <= 32)
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * neg);
}
