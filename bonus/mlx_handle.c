/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:35:53 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/14 14:16:05 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

static void	close_door(t_data *data)
{
	long	time;

	time = get_time();
	while (data->list_door)
	{
		if (time - data->list_door->wait > 5000)
		{
			data->map[(int)data->list_door->pos_door.y]
			[(int)data->list_door->pos_door.x] = 'D';
			data->list_door = delete_lst(data->list_door);
		}
		else
			break ;
	}
}

static void	recalc_dist(t_data *data)
{
	t_sprit	*tmp;

	tmp = data->sprite;
	while (tmp)
	{
		tmp->dist = calc_dist(data, tmp->pos);
		tmp = tmp->next;
	}
}

static int	refresh(t_data *data)
{
	close_door(data);
	move(data);
	recalc_dist(data);
	re_draw(data);
	return (0);
}

void	mlx_handling(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 6, 1L << 6, mlx_mouse_moving, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx->win, 17, 0, win_close, data);
	mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->screen.x / 2, data->mlx->screen.y / 2);
	mlx_loop_hook(data->mlx->mlx_ptr, refresh, data);
	mlx_loop(data->mlx->mlx_ptr);
}
