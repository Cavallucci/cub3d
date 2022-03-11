/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:09 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/11 14:21:53 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate(double angle, t_vec *v)
{
	t_vec	tmp;

	tmp = *v;
	v->x = tmp.x * cos(angle) + tmp.y * sin(angle);
	v->y = tmp.y * cos(angle) - tmp.x * sin(angle);
}

void	move_data_key(t_data *data)
{
	if (data->key->w && !hit_up(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, 0.1));
	if (data->key->s && !hit_down(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, -0.1));
	if (data->key->a && !hit_left(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, -0.15));
	if (data->key->d && !hit_right(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, 0.15));
}

static int	move(t_data *data)
{
	double	angle;

	if (data->key->left || data->key->right)
	{
		if (data->key->left > 0)
			angle = -data->key->left * 3.1415 / 90;
		else if (data->key->right > 0)
			angle = data->key->right * 3.1415 / 90;
		else if (data->key->left == -1)
			angle = -3.1415 / 90;
		else
			angle = 3.1415 / 90;
		rotate(angle, &data->dir);
		rotate(angle, &data->plane);
		if (data->key->left > 0)
			data->key->left = 0;
		if (data->key->right > 0)
			data->key->right = 0;
	}
	move_data_key(data);
	re_draw(data);
	return (0);
}

void	mlx_handling(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx->win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx->win, 17, 0, win_close, data);
	mlx_loop_hook(data->mlx->mlx_ptr, move, data);
	mlx_loop(data->mlx->mlx_ptr);
}

void	render(t_data *data)
{
	data->width = data->pars->nb_bigger_line;
	data->height = data->pars->nb_line_of_file;
	data->z_buffer = (double *)malloc(sizeof(double) * data->mlx->screen.x);
	data->top = (int)data->mlx->screen.y / 2;
	data->down = (int)data->mlx->screen.y / 2;
	data->plane = init_vec(2 * data->dir.y / 3, -2 * data->dir.x / 3);
	draw(data);
	mlx_handling(data);
}
