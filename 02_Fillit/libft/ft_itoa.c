/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:59:29 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/29 16:07:07 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Si n est nul, ne pas renvoyer juste "0" sinon le char* retourné ne sera pas
** mallocé
*/

char			*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = ft_intlen(n);
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	if (n < 0)
		*str = '-';
	if (n == 0)
	{
		*str = '0';
		return (str);
	}
	str[size--] = '\0';
	while (n != 0)
	{
		if (n < 0)
			str[size--] = '0' - n % 10;
		else
			str[size--] = '0' + n % 10;
		n = n / 10;
	}
	return (str);
}
