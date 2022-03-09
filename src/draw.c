/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:31:18 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/09 16:11:06 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color(double x, double y, t_mlx *side)
{
	x = (1 - x) * side->img_width;
	y = (1 - y) * side->img_height;
	return (((int *)side->mlx_ptr)[(int)((int)x + (int)y * (side->line_bytes
			/ 4))]);
}

static int	get_wall_color(t_data *data, t_vec v, int wall, double height)
{
	int		color;

	color = 0;
	if (wall == 3 && v.y > 0)
		color = get_color(1 - (data->pos.x + v.x * data->dist)
				+ floor(data->pos.x + v.x * data->dist), height, data->door);
	else if (wall == 3 && v.y < 0)
		color = get_color((data->pos.x + v.x * data->dist)
				- floor(data->pos.x + v.x * data->dist), height, data->door);
	else if (wall == 2 && v.x < 0)
		color =  get_color(1 - (data->pos.y + v.y * data->dist)
				+ floor(data->pos.y + v.y * data->dist), height, data->door);
	else if (wall == 2 && v.x > 0)
		color = get_color((data->pos.y + v.y * data->dist)
				- floor(data->pos.y + v.y * data->dist), height, data->door);
	else if (wall && v.y > 0)
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

static void	draw_ray(t_data *data, int x, int wall, t_vec v)
{
	int		y;
	int		top;
	int		down;
	int		color;
	double	height;

	top = data->top + data->top / data->dist;
	down = data->down - data->down / data->dist;
	y = 0;
	while (y < (int)data->mlx->screen.y)
	{
		height = (double)(y - down) / (double)(top - down);
		if (y <= down)
			color = data->color_f;
		else if (y > top)
			color = data->color_c;
		else
			color = get_wall_color(data, v, wall, height);
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

static int	is_left(t_vec pos, t_vec v, t_vec point)
{
	double	cross_prod;

	cross_prod = (v.x - pos.x) * (point.y - pos.y)
		- (v.y - pos.y) * (point.x - pos.x);
	if (cross_prod > 0)
		return (1);
	return (0);
}

void	draw_sprites(t_data *data)
{
	t_sprit	*s;
	double	angle;
	int		x;
	int		y;
	t_vec	size;
	t_vec	start;
	int		color;

	s = data->sprite;
	while (s)
	{
		angle = acos(dot(data->dir, normalize(sub_vec(s->pos, data->pos))));
		if (angle < 0.85)
		{
			if (is_left(init_vec(0, 0), data->dir, sub_vec(s->pos, data->pos)))
				angle *= -1;
			x = 0.75 * (tan(angle) + 0.6667) * data->mlx->screen.x;
			//x = ((angle + 0.588003) / 1.176006) * data->mlx->screen.x;
			size.y = data->sprite_img->img_height / s->dist;
			size.x = data->sprite_img->img_width / s->dist;
			x -= (int)size.x;
			start.x = x;
			size.x = size.x;
			if (x < 0)
				x = 0;
			while (x < start.x + 2 * size.x && x < (int)data->mlx->screen.x)
			{
				if (data->z_buffer[x] > s->dist)
				{
					y = data->mlx->screen.y / 2 - (int)size.y;
					start.y = y;
					if (y < 0)
						y = 0;
					while (y < start.y + 2 * size.y && y < (int)data->mlx->screen.y)
					{
						color = get_color(1 - ((double)x - start.x) / (size.x * 2), ((double)y - start.y) / (size.y * 2), data->sprite_img);
						if (color != 0x00FF00)
							my_mlx_pixel_put(data, x, y, color);
						y++;
					}
				}
				x++;
			}
		}
		s = s->next;
	}
}

void	draw(t_data *data)
{
	t_vec	orig;
	t_vec	v;
	int		wall;
	int		x;

	orig = sub_vec(data->dir, data->plane);
	v = orig;
	x = 0;
	while (x < (int)data->mlx->screen.x)
	{
		wall = 0;
		data->dist = get_dist_hit(data, v, &wall);
		data->z_buffer[x] = data->dist;
		draw_ray(data, x, wall, v);
		v = add_vec(orig, mult_dbl(data->plane, 2 * (double)x
					/ data->mlx->screen.x));
		x++;
	}
	draw_sprites(data);
	minimap(data);
}
