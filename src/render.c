/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:09 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/28 17:39:49 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	mlx_handling(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 6, 1L << 6, mlx_mouse_moving, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx->win, 17, 0, win_close, data);
	mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->screen.x / 2, data->mlx->screen.y / 2);
	mlx_loop(data->mlx->mlx_ptr);
}
/*mlx_mouse_hide(data->mlx->mlx_ptr, data->mlx->win);*/

void	render(t_data *data)
{
	data->width = data->pars->nb_bigger_line;
	data->height = data->pars->nb_line_of_file;
	data->top = (int)data->mlx->screen.y / 2;
	data->down = (int)data->mlx->screen.y / 2;
	data->plane = init_vec(2 * data->dir.y / 3, -2 * data->dir.x / 3);
	draw(data);
	mlx_handling(data);
}
