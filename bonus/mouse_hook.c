/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:04:43 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 15:32:48 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mlx_mouse_moving(int x, int y, void *params)
{
	t_data	*data;

	(void)y;
	data = (t_data *)params;
	if ((x - data->mlx->screen.x / 2) * (x - data->mlx->screen.x / 2) > 1)
	{
		if (x - data->mlx->screen.x / 2 > 0)
			data->key->right = (x - data->mlx->screen.x / 2) / 10;
		else
			data->key->left = (data->mlx->screen.x / 2 - x) / 10;
	}
	mlx_mouse_move(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->screen.x / 2, data->mlx->screen.y / 2);
	return (0);
}
