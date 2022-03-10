/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:39:03 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 15:36:10 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vec	get_delta(t_vec dir)
{
	t_vec	delta;

	if (dir.x != 0)
		delta.x = fabs(1 / dir.x);
	else
		delta.x = 1e30;
	if (dir.y != 0)
		delta.y = fabs(1 / dir.y);
	else
		delta.y = 1e30;
	return (delta);
}

t_vec	get_side(t_vec pos, t_vec dir, t_vec delta)
{
	t_vec	side;

	if (dir.x < 0)
		side.x = (pos.x - floor(pos.x)) * delta.x;
	else
		side.x = (floor(pos.x) - pos.x + 1) * delta.x;
	if (dir.y < 0)
		side.y = (pos.y - floor(pos.y)) * delta.y;
	else
		side.y = (floor(pos.y) - pos.y + 1) * delta.y;
	return (side);
}
