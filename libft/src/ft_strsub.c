/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:27:32 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/18 14:40:35 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (len + 1))))
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[len] = '\0';
	return (tmp);
}
