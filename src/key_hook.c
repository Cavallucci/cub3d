/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:27:14 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/27 17:06:38 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	win_close(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

void	rotate(double angle, t_vec *v)
{
	t_vec	tmp;

	tmp = *v;
	v->x = tmp.x * cos(angle) + tmp.y * sin(angle);
	v->y = tmp.y * cos(angle) - tmp.x * sin(angle);
}

int	key_hook(int keycode, t_data *data)
{
	double	angle;
	long	time;

	time = get_time();
	if (time - data->wait > 5000)
		data->map[(int)data->pos_door.y][(int)data->pos_door.x] = 'D';
	if (keycode == ESC || keycode == 53)
		win_close(data);
	if (keycode == 65361 || keycode == 65363)
	{
		angle = 3.1415 / 18 * (keycode - 65362);
		rotate(angle, &data->dir);
		rotate(angle, &data->plane);
		re_draw(data);
	}
	if (keycode == 106 || keycode == 108)
	{
		angle = 3.1415 / 18 * (keycode - 107);
		rotate(angle, &data->dir);
		rotate(angle, &data->plane);
		re_draw(data);
	}
	if (keycode == W && !hit_up(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, 0.5));
	if (keycode == S && !hit_down(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, -0.5));
	if (keycode == A && !hit_left(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, -0.75));
	if (keycode == D && !hit_right(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, 0.75));
	if (keycode == 32 && hit_door(data))
		open_door(data);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		re_draw(data);
	return (0);
}
