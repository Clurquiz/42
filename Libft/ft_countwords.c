/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:04:47 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/18 12:06:44 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int		cpt;

	cpt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cpt++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (cpt);
}
