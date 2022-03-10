/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:27:14 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/09 14:40:36 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	win_close(t_data *data)
{
	mlx_free_img(data->mlx->mlx_ptr, data->north);
	mlx_free_img(data->mlx->mlx_ptr, data->south);
	mlx_free_img(data->mlx->mlx_ptr, data->west);
	mlx_free_img(data->mlx->mlx_ptr, data->east);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx->mlx_ptr);
	free(data->mlx);
	free_data(data);
	exit(0);
}

static void	rotate(double angle, t_vec *v)
{
	t_vec	tmp;

	tmp = *v;
	v->x = tmp.x * cos(angle) + tmp.y * sin(angle);
	v->y = tmp.y * cos(angle) - tmp.x * sin(angle);
}

static void	move(int keycode, t_data *data)
{
	double	angle;

	if (keycode == 37 || keycode == 38)
	{
		angle = 3.1415 / 45 * (37.5 - (double)keycode);
		rotate(angle, &data->dir);
		rotate(angle, &data->plane);
	}
	if (keycode == 65361 || keycode == 65363)
	{
		angle = 3.1415 / 90 * (keycode - 65362);
		rotate(angle, &data->dir);
		rotate(angle, &data->plane);
	}
	if (keycode == 106 || keycode == 108)
	{
		angle = 3.1415 / 90 * (keycode - 107);
		rotate(angle, &data->dir);
		rotate(angle, &data->plane);
	}
	if (keycode == W && !hit_up(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, 0.15));
	if (keycode == S && !hit_down(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, -0.15));
	if (keycode == A && !hit_left(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, -0.225));
	if (keycode == D && !hit_right(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, 0.225));
	if (keycode == 13 && !hit_up(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, 0.15));
	if (keycode == 1 && !hit_down(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, -0.15));
	if (keycode == 0 && !hit_left(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, -0.225));
	if (keycode == 2 && !hit_right(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, 0.225));
	re_draw(data);
}

int	key_hook(int keycode, t_data *data)
{
	int		i;

	i = -1;
	while (++i < 5)
		move(keycode, data);
	return (0);
}
