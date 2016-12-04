/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:16:01 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/18 14:59:26 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (*s1)
	{
		*tmp = *s1;
		s1++;
		tmp++;
	}
	while (*s2)
	{
		*tmp = *s2;
		s2++;
		tmp++;
	}
	*tmp = '\0';
	tmp = tmp - (len_s1 + len_s2);
	return (tmp);
}
