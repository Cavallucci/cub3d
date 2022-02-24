/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:33:59 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/24 18:07:44 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_hit(t_vec *map, t_vec *side, t_vec delta, t_vec dir)
{
	int	wall;

	if (side->x < side->y)
	{
		side->x += delta.x;
		if (dir.x < 0)
			map->x -= 1;
		else
			map->x += 1;
		wall = 0;
	}
	else
	{
		side->y += delta.y;
		if (dir.y < 0)
			map->y -= 1;
		else
			map->y += 1;
		wall = 1;
	}
	return (wall);
}

double	get_dist_hit(t_data *data, t_vec v, int *wall)
{
	t_vec	map;
	t_vec	delta;
	t_vec	side;
	int		hit;
	double	dist;

	map = init_vec(floor(data->pos.x), floor(data->pos.y));
	delta = get_delta(v);
	side = get_side(data->pos, v, delta);
	hit = 0;
	while (!hit)
	{
		*wall = check_hit(&map, &side, delta, v);
		if (*wall)
			dist = side.y - delta.y;
		else
			dist = side.x - delta.x;
		if (data->map[data->height - (int)map.y - 1][(int)map.x] == '1')
			hit = 1;
		else if (data->map[data->height - (int)map.y - 1][(int)map.x] == '2')
		{
			hit = 1;
			*wall = 2;
		}
	}
	return (dist);
}
