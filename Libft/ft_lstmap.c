/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:24:39 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/19 16:47:31 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*start;

	if (!f || !lst)
		return (NULL);
	if (!(tmp = (t_list *)malloc(sizeof(*tmp))))
		return (NULL);
	tmp = (*f)(lst);
	start = tmp;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp->next = (t_list *)malloc(sizeof(*tmp))))
			return (NULL);
		tmp->next = (*f)(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (start);
}
