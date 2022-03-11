/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:27:14 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/11 18:42:22 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	win_close(t_data *data, int e)
{
	if (data->north)
		mlx_free_img(data->mlx->mlx_ptr, data->north);
	if (data->south)
		mlx_free_img(data->mlx->mlx_ptr, data->south);
	if (data->west)
		mlx_free_img(data->mlx->mlx_ptr, data->west);
	if (data->east)
		mlx_free_img(data->mlx->mlx_ptr, data->east);
	if (data->door)
		mlx_free_img(data->mlx->mlx_ptr, data->door);
	if (data->sprite_img)
		mlx_free_img(data->mlx->mlx_ptr, data->sprite_img);
	if (data->mlx)
	{
		mlx_destroy_image(data->mlx->mlx_ptr, data->mlx->img);
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
		mlx_destroy_display(data->mlx->mlx_ptr);
		free(data->mlx->mlx_ptr);
		free(data->mlx);
	}
	free_data(data);
	exit(e);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == W)
		data->key->w = 1;
	if (keycode == A)
		data->key->a = 1;
	if (keycode == S)
		data->key->s = 1;
	if (keycode == D)
		data->key->d = 1;
	if (keycode == 106 || keycode == 65361)
		data->key->left = -1;
	if (keycode == 108 || keycode == 65363)
		data->key->right = -1;
	if (keycode == ESC)
		win_close(data, 0);
	if (keycode == 49 && hit_door(data))
		open_door(data);
	if (keycode == 32 && hit_door(data))
		open_door(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->key->w = 0;
	if (keycode == A)
		data->key->a = 0;
	if (keycode == S)
		data->key->s = 0;
	if (keycode == D)
		data->key->d = 0;
	if (keycode == 106 || keycode == 65361)
		data->key->left = 0;
	if (keycode == 108 || keycode == 65363)
		data->key->right = 0;
	return (0);
}
