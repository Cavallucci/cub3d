/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:09 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/02 15:41:18 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	get_time(void)
{
	struct timeval	time;
	unsigned long	timestamp;

	gettimeofday(&time, NULL);
	timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (timestamp);
}

void	open_door(t_data *data)
{
	t_vec   new;
	double  i;
	t_door	*cell;

	data->wait = get_time();
	i = 0.11;
	while (i <= 0.51)
	{
		new = add_vec(data->pos, mult_dbl(data->dir, i));
		if (data->map[(int)(data->height - new.y)][(int)(new.x)] == 'D')
		{
			cell = new_cell(new.x, (data->height - new.y));
			add_cell(&data->list_door, cell);
			data->map[(int)(data->height - new.y)][(int)(new.x)] = '0';
			re_draw(data);
			break;
		}
		i += 0.1;
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

void	mlx_handling(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
			data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 6, 1L << 6, mlx_mouse_moving, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx->win, 17, 0, win_close, data);
	mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->screen.x / 2, data->mlx->screen.y / 2);
	mlx_mouse_hide(data->mlx->mlx_ptr, data->mlx->win);
	mlx_loop(data->mlx->mlx_ptr);
}

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
