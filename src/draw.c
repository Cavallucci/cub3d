/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:31:18 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/22 15:17:29 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	t_mlx	*mlx;
	char	*dst;
	int		pixel;

	mlx = data->mlx;
	pixel = (mlx->screen.y - y - 1) * mlx->line_bytes + x * 4;
	dst = mlx->buffer + pixel;
	*(unsigned int *)dst = color;
}

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

static t_vec	get_delta(t_vec dir)
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

static t_vec	get_side(t_vec pos, t_vec dir, t_vec delta)
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

int	get_color(double x, double y, t_mlx *side)
{
	x = (1 - x) * side->img_width;
	y = (1 - y) * side->img_height;
	return (((int *)side->mlx_ptr)[(int)((int)x + (int)y * (side->line_bytes / 4))]);
}

void	draw(t_data *data)
{
	t_vec	orig;
	t_vec	v;
	t_vec	map;
	t_vec	delta;
	t_vec	side;
	int		hit;
	int		wall;
	double	dist;
	int		y;
	double	step;
	int		x;

	orig = sub_vec(data->dir, data->plane);
	v = orig;
	step = (size_vec(data->plane) * 2) / data->mlx->screen.x;
	x = 0;
	while (x < (int)data->mlx->screen.x)
	{
		map.x = floor(data->pos.x);
		map.y = floor(data->pos.y);
		delta = get_delta(v);
		side = get_side(data->pos, v, delta);
		hit = 0;
		while (!hit)
		{
			wall = check_hit(&map, &side, delta, v);
			if (wall)
				dist = side.y - delta.y;
			else
				dist = side.x - delta.x;
			if (data->map[data->height - (int)map.y - 1][(int)map.x] == '1')
				hit = 1;
		}
		y = 0;
		int down = ((int)data->mlx->screen.y / 2) - ((int)data->mlx->screen.y / 2) / dist;
		int	top = ((int)data->mlx->screen.y / 2) + ((int)data->mlx->screen.y / 2) / dist;
		int	color;
		while (y < (int)data->mlx->screen.y)
		{
			if (y < down) 
				my_mlx_pixel_put(data, x, y, 0);
			else if (y > top) 
				my_mlx_pixel_put(data, x, y, 0xFFFFFF);
			else if (wall && v.y > 0)
			{
				color = get_color(1 - ((data->pos.x + v.x * dist) - floor(data->pos.x + v.x * dist)), (double)(y - down) / (double)(top - down), data->north);
				my_mlx_pixel_put(data, x, y, color);
			}
			else if (wall && v.y < 0)
			{
				color = get_color((data->pos.x + v.x * dist) - floor(data->pos.x + v.x * dist), (double)(y - down) / (double)(top - down), data->south);
				my_mlx_pixel_put(data, x, y, color);
			}
			else if (!wall && v.x < 0)
			{
				color = get_color(1 - ((data->pos.y + v.y * dist) - floor(data->pos.y + v.y * dist)), (double)(y - down) / (double)(top - down), data->east);
				my_mlx_pixel_put(data, x, y, color);
			}
			else if (!wall && v.x > 0)
			{
				color = get_color((data->pos.y + v.y * dist) - floor(data->pos.y + v.y * dist), (double)(y - down) / (double)(top - down), data->west);
				my_mlx_pixel_put(data, x, y, color);
			}
			y++;
		}
		v = add_vec(orig, mult_dbl(data->plane, 2 * (double)x / data->mlx->screen.x));
		x++;
	}
	minimap(data);
}
