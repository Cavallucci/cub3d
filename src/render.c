/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:09 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/22 17:46:45 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	mlx_mouse_moving(int x, int y, void *params)
{
	t_data	*data;
	double	angle;
	t_vec	tmp;

	(void)y;
	data = (t_data *)params;
	if ((x - data->mlx->screen.x / 2) * (x - data->mlx->screen.x / 2) > 10000)
	{
		angle = (2 * 3.1415 * ((double)x - (data->mlx->screen.x / 2))) / 6480;
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
	return (0);
}

void	mlx_mouse_handling(t_data *data)
{
	mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win,
			data->mlx->screen.x / 2, data->mlx->screen.y / 2);
	mlx_mouse_hide(data->mlx->mlx_ptr, data->mlx->win);
	mlx_mouse_hook(data->mlx->win, &mlx_mouse_moving, data);

}

void	mlx_handling(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 6, 1L << 6, mlx_mouse_moving, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx->win, 17, 0, win_close, data);
	mlx_mouse_handling(data);
	mlx_loop(data->mlx->mlx_ptr);
}

void	render(t_data *data)
{
	data->width = data->pars->nb_bigger_line;
	data->height = data->pars->nb_line_of_file;
	data->plane = init_vec(2 * data->dir.y / 3, -2 * data->dir.x / 3);
	draw(data);
	mlx_handling(data);
}
