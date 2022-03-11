/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:31:18 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/11 14:46:11 by lcavallu         ###   ########.fr       */
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

void	re_draw(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img);
	data->mlx->img = mlx_new_image(data->mlx->mlx_ptr, data->mlx->screen.x,
			data->mlx->screen.y);
	data->mlx->buffer = mlx_get_data_addr(data->mlx->img,
			&data->mlx->pixel_bits, &data->mlx->line_bytes, &data->mlx->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img, 0, 0);
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
}
