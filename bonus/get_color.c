/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:31:18 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 18:06:35 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_color(double x, double y, t_mlx *side)
{
	x = (1 - x) * side->img_width;
	y = (1 - y) * side->img_height;
	return (((int *)side->mlx_ptr)[(int)((int)x + (int)y * (side->line_bytes
			/ 4))]);
}

int	get_doors_color(t_data *data, t_vec v, int wall, double height)
{
	int	color;

	color = 0;
	if (wall && v.y > 0)
		color = get_color(1 - (data->pos.x + v.x * data->dist)
				+ floor(data->pos.x + v.x * data->dist), height, data->north);
	else if (wall && v.y < 0)
		color = get_color((data->pos.x + v.x * data->dist)
				- floor(data->pos.x + v.x * data->dist), height, data->south);
	else if (!wall && v.x < 0)
		color = get_color(1 - (data->pos.y + v.y * data->dist)
				+ floor(data->pos.y + v.y * data->dist), height, data->west);
	else if (!wall && v.x > 0)
		color = get_color((data->pos.y + v.y * data->dist)
				- floor(data->pos.y + v.y * data->dist), height, data->east);
	return (color);
}

int	get_wall_color(t_data *data, t_vec v, int wall, double height)
{
	int	color;

	color = 0;
	if (wall == 3 && v.y > 0)
		color = get_color(1 - (data->pos.x + v.x * data->dist)
				+ floor(data->pos.x + v.x * data->dist), height, data->door);
	else if (wall == 3 && v.y < 0)
		color = get_color((data->pos.x + v.x * data->dist)
				- floor(data->pos.x + v.x * data->dist), height, data->door);
	else if (wall == 2 && v.x < 0)
		color = get_color(1 - (data->pos.y + v.y * data->dist)
				+ floor(data->pos.y + v.y * data->dist), height, data->door);
	else if (wall == 2 && v.x > 0)
		color = get_color((data->pos.y + v.y * data->dist)
				- floor(data->pos.y + v.y * data->dist), height, data->door);
	else
		color = get_doors_color(data, v, wall, height);
	return (color);
}
