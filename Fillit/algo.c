/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:44:30 by baparis           #+#    #+#             */
/*   Updated: 2016/11/25 11:58:20 by baparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_and_place(char **endgrid, char c, t_list lst)
{
	printf("lol\n");
	return (0);
}

void	ft_erase(t_list *lst, char **endgrid, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	lst->used = 0;
	while (endgrid[j])
	{
		i = 0;
		while (endgrid[j][i])
		{
			if (endgrid[j][i] == c)
				endgrid[j][i] = '.';
			i++;
		}
		j++;
	}
}

int		ft_algo(char c, t_list *lst, char **endgrid)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->used == 1)
		tmp = tmp->next;
	if (!(tmp))
		return (1);
	while (tmp)
	{
		while (tmp->used == 1 && tmp)
			tmp = tmp->next;
		if (ft_check_and_place(endgrid, c, *tmp))
		{
			tmp->used = 1;
			if (ft_algo(c + 1, lst, endgrid))
				ft_erase(tmp, endgrid, c);
			else
				return (1);
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}

