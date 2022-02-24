/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:36:49 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/24 17:26:54 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_left(t_vec pos, t_vec v, t_vec point)
{
	double	cross_prod;

	cross_prod = (v.x - pos.x) * (point.y - pos.y)
		- (v.y - pos.y) * (point.x - pos.x);
	if (cross_prod > 0)
		return (1);
	return (0);
}

static int	get_wall_color(t_data *data, t_vec pos, t_vec pix)
{
	int	color;

	if (pos.x < 0 || pos.x >= data->width
		|| (int)pos.y > data->height - 1 || pos.y <= 0)
	{
		if ((char)(data->mlx->buffer[(int)((data->mlx->screen.y - pix.y - 1)
				* data->mlx->line_bytes + pix.x * 4)]) == 0)
			color = 0xFFFFFF;
		else
			color = -1;
	}
	else if (data->map[data->height - (int)pos.y - 1][(int)pos.x] == '1')
		color = 0;
	else
	{
		if ((char)(data->mlx->buffer[(int)((data->mlx->screen.y - pix.y - 1)
				* data->mlx->line_bytes + pix.x * 4)]) == 0)
			color = 0xFFFFFF;
		else
			color = -1;
	}
	return (color);
}

static int	get_color(t_data *data, t_vec min, t_vec max, t_vec pix)
{
	t_vec	v_min;
	t_vec	v_max;
	t_vec	pos;
	int		color;

	v_min = add_vec(data->pos, sub_vec(data->dir, data->plane));
	v_max = add_vec(data->pos, add_vec(data->dir, data->plane));
	pos.x = ((pix.x - min.x) / (max.x - min.x) * 15 - 7.5 + data->pos.x);
	pos.y = ((pix.y - min.y) / (max.y - min.y) * 10 - 5 + data->pos.y);
	color = get_wall_color(data, pos, pix);
	if (!is_left(data->pos, pos, v_max) && is_left(data->pos, pos, v_min))
	{
		if (color)
			color = 0xFF8888;
		else
			color = 0x880000;
	}
	if (dot(sub_vec(pos, data->pos), sub_vec(pos, data->pos)) < 0.05)
		color = 0xFF0000;
	return (color);
}

void	minimap(t_data *data)
{
	t_vec	min;
	t_vec	max;
	t_vec	pix;
	int		color;

	min = mult_dbl(data->mlx->screen, 0.05);
	max = mult_dbl(data->mlx->screen, 0.25);
	pix = min;
	pix.y = floor(pix.y);
	while (pix.y < max.y)
	{
		pix.x = floor(min.x);
		while (pix.x < max.x)
		{
			color = get_color(data, min, max, pix);
			if (color != -1)
				my_mlx_pixel_put(data, (int)pix.x, (int)pix.y, color);
			pix.x += 1;
		}
		pix.y += 1;
	}
}
