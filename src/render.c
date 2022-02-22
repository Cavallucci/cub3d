/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:09 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/22 16:50:50 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_handling(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx->win, 17, 0, win_close, data);
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
