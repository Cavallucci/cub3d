/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:31:18 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/17 16:25:52 by pguignie         ###   ########.fr       */
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
		side.x = (pos.x - fabs(pos.x)) * delta.x;
	else
		side.x = (fabs(pos.x) - pos.x + 1) * delta.x;
	if (dir.y < 0)
		side.y = (pos.y - fabs(pos.y)) * delta.y;
	else
		side.y = (fabs(pos.y) - pos.y + 1) * delta.y;
	return (side);
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

void	draw(t_data **datas)
{
	printf("draw bigger_line: %d\n", (*datas)->pars->nb_bigger_line);
	t_vec	v;
	t_vec	delta;
	t_vec	side;
	t_vec	map;
	double	step;
	int		hit;
	int		wall;
	double	dist;
	int		x;
	int		y;
	t_data	*data = *datas;

	printf("draw bigger_line: %d\n", data->pars->nb_bigger_line);
	v = add_vec(data->pos, sub_vec(data->dir, data->plane));
	step = size_vec(data->plane) * 2 / data->mlx->screen.x;
	x = 0;
	while (x < (int)data->mlx->screen.x)
	{
		map.x = fabs(data->pos.x);
		map.y = fabs(data->pos.y);
		delta = get_delta(v);
		side = get_side(data->pos, v, delta);
		hit = 0;
		while (!hit)
		{
			wall = check_hit(&map, &side, delta, v);
			if (data->map[10 - (int)map.y - 1][(int)map.x] == '1')
			{
				hit = 1;
				if (wall)
					dist = side.y - delta.y;
				else
					dist = side.x - delta.x;
				//printf("dist: %lf\n", dist);
				y = 0;
				while (y < (int)data->mlx->screen.y)
				{
					if (y < ((int)data->mlx->screen.y / 2) - ((int)data->mlx->screen.y / 2) / dist) 
						my_mlx_pixel_put(data, x, y, 0);
					else if (y > ((int)data->mlx->screen.y / 2) + ((int)data->mlx->screen.y / 2) / dist) 
						my_mlx_pixel_put(data, x, y, 0xFFFFFF);
					else if (wall && data->dir.y > 0)
						my_mlx_pixel_put(data, x, y, 0x00FF00);
					else if (wall && data->dir.y < 0)
						my_mlx_pixel_put(data, x, y, 0x0000FF);
					else if (!wall && data->dir.x < 0)
						my_mlx_pixel_put(data, x, y, 0xFF0000);
					else if (!wall && data->dir.x > 0)
						my_mlx_pixel_put(data, x, y, 0xFF00FF);
					y++;
				}
			}
		}
		v = add_vec(v, mult_dbl(data->plane, step));
		x++;
	}
	minimap(data);
}
