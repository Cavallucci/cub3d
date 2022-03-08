/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:04:43 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/04 16:44:37 by paulguign        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mlx_mouse_moving(int x, int y, void *params)
{
	t_data	*data;
	double	angle;
	t_vec	tmp;

	data = (t_data *)params;
	if ((x - data->mlx->screen.x / 2) * (x - data->mlx->screen.x / 2) > 10000)
	{
		angle = (2 * 3.1415 * ((double)x - (data->mlx->screen.x / 2))) / 12960;
		tmp = data->dir;
		data->dir.x = tmp.x * cos(angle) + tmp.y * sin(angle);
		data->dir.y = tmp.y * cos(angle) - tmp.x * sin(angle);
		tmp = data->plane;
		data->plane.x = tmp.x * cos(angle) + tmp.y * sin(angle);
		data->plane.y = tmp.y * cos(angle) - tmp.x * sin(angle);
		mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win,
			data->mlx->screen.x / 2, data->mlx->screen.y / 2);
		re_draw(data);
	}
	if ((y - data->mlx->screen.y / 2) * (y - data->mlx->screen.y / 2) > 10000)
	{
		mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win,
			data->mlx->screen.x / 2, data->mlx->screen.y / 2);
		re_draw(data);
	}
	return (0);
}
