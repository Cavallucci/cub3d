/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:31:18 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 17:55:37 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

int	is_left(t_vec pos, t_vec v, t_vec point)
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

	s = data->sprite;
	while (s)
	{
		angle = acos(dot(data->dir, normalize(sub_vec(s->pos, data->pos))));
		if (angle < 0.85)
			angle = draw_sprites_angle(data, s, angle);
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
