/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:31:18 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 18:05:01 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	draw_sprites_angle_y(t_data *data, int x, t_vec	size, t_vec start)
{
	int	color;
	int	y;

	y = data->mlx->screen.y / 2 - (int)size.y;
	start.y = y;
	if (y < 0)
		y = 0;
	while (y < start.y + 2 * size.y && y < (int)data->mlx->screen.y)
	{
		color = get_color(1 - ((double)x - start.x) / (size.x * 2),
				((double)y - start.y) / (size.y * 2), data->sprite_img);
		if (color != 0x00FF00)
			my_mlx_pixel_put(data, x, y, color);
		y++;
	}
	return (color);
}

double	draw_sprites_angle(t_data *data, t_sprit *s, double angle)
{
	int		x;
	t_vec	size;
	t_vec	start;
	int		color;

	if (is_left(init_vec(0, 0), data->dir, sub_vec(s->pos, data->pos)))
		angle *= -1;
	x = 0.75 * (tan(angle) + 0.6667) * data->mlx->screen.x;
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
			color = draw_sprites_angle_y(data, x, size, start);
		x++;
	}
	return (angle);
}
