/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:09 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 17:44:18 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		win_close(data);
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
