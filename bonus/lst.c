/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkralik <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:40:36 by mkralik           #+#    #+#             */
/*   Updated: 2022/03/10 18:13:18 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_door	*delete_lst(t_door *lst)
{
	t_door	*tmp;

	tmp = lst;
	lst = lst->next;
	free(tmp);
	return (lst);
}

t_door	*ft_lstlast(t_door *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_door	*new_cell(double x, double y, long w)
{
	t_door	*cell;

	cell = malloc(sizeof(t_door));
	if (!cell)
		return (NULL);
	cell->pos_door.x = (int)x;
	cell->pos_door.y = (int)y;
	cell->wait = w;
	cell->next = NULL;
	return (cell);
}

void	add_cell(t_door **door, t_door *new)
{
	t_door	*last;

	if (!*door)
		*door = new;
	else
	{
		last = ft_lstlast(*door);
		last->next = new;
	}
}
