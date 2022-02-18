/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:27:14 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/17 18:23:25 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	win_close(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

static void	re_draw(t_data *data)
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

int	key_hook(int keycode, t_data *data)
{
	double	angle;
	t_vec	tmp;

	if (keycode == 65307 || keycode == 53)
		win_close(data);
	if (keycode == 106 || keycode == 108)
	{
		angle = 3.1415 / 18 * (keycode - 107);
		tmp = data->dir;
		data->dir.x = tmp.x * cos(angle) + tmp.y * sin(angle);
		data->dir.y = tmp.y * cos(angle) - tmp.x * sin(angle);
		tmp = data->plane;
		data->plane.x = tmp.x * cos(angle) + tmp.y * sin(angle);
		data->plane.y = tmp.y * cos(angle) - tmp.x * sin(angle);
		re_draw(data);
	}
	if (keycode == W)
		data->pos = add_vec(data->pos, mult_dbl(data->dir, 0.5));
	if (keycode == S)
		data->pos = add_vec(data->pos, mult_dbl(data->dir, -0.5));
	if (keycode == A)
		data->pos = add_vec(data->pos, mult_dbl(data->plane, -0.75));
	if (keycode == D)
		data->pos = add_vec(data->pos, mult_dbl(data->plane, 0.75));
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		re_draw(data);
	return (0);
}
