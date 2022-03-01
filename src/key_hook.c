/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:27:14 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/28 17:49:51 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_free_img(void *mlx_ptr, t_mlx *mlx)
{
	mlx_destroy_image(mlx_ptr, mlx->img);
	free(mlx);
}

void	free_data(t_data *data)
{
	if (data->pars->file_fd)
		close(data->pars->file_fd);
	if (data->pars->file)
		free_str(data->pars->file);
	if (data->pars->north)
		free_str(data->pars->north);
	if (data->pars->south)
		free_str(data->pars->south);
	if (data->pars->west)
		free_str(data->pars->west);
	if (data->pars->east)
		free_str(data->pars->east);
	if (data->pars->door)
		free_str(data->pars->door);
	if (data->map)
		free_str(data->map);
	free(data->pars);
	free(data);
}

int	win_close(t_data *data)
{
	mlx_free_img(data->mlx->mlx_ptr, data->north);
	mlx_free_img(data->mlx->mlx_ptr, data->south);
	mlx_free_img(data->mlx->mlx_ptr, data->west);
	mlx_free_img(data->mlx->mlx_ptr, data->east);
	mlx_free_img(data->mlx->mlx_ptr, data->door);
	mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx->mlx_ptr);
	free(data->mlx);
	free_data(data);
	exit(0);
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
	int		i;

	i = 0;
	if (keycode == 65307 || keycode == 53)
		win_close(data);
	while (i < 5)
	{
		if (keycode == 65361 || keycode == 65363)
		{
			angle = 3.1415 / 90 * (keycode - 65362);
			rotate(angle, &data->dir);
			rotate(angle, &data->plane);
			re_draw(data);
		}
		if (keycode == 106 || keycode == 108)
		{
			angle = 3.1415 / 90 * (keycode - 107);
			rotate(angle, &data->dir);
			rotate(angle, &data->plane);
			re_draw(data);
		}
		if (keycode == W && !hit_up(data))
		{
			data->pos = add_vec(data->pos, mult_dbl(data->dir, 0.1));
			re_draw(data);
		}
		if (keycode == S && !hit_down(data))
		{
			data->pos = add_vec(data->pos, mult_dbl(data->dir, -0.1));
			re_draw(data);
		}
		if (keycode == A && !hit_left(data))
		{
			data->pos = add_vec(data->pos, mult_dbl(data->plane, -0.15));
			re_draw(data);
		}
		if (keycode == D && !hit_right(data))
		{
			data->pos = add_vec(data->pos, mult_dbl(data->plane, 0.15));
			re_draw(data);
		}
		i++;
	}
	return (0);
}
