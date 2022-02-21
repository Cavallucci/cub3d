/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:09 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/21 15:16:44 by pguignie         ###   ########.fr       */
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
	data->north = malloc(sizeof(t_mlx));
	data->north->img = NULL;
	data->north->mlx_ptr = NULL;
	data->north->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "./img/hitler.xpm", &data->north->img_width, &data->north->img_height);
	data->north->mlx_ptr = mlx_get_data_addr(data->north->img, &data->north->pixel_bits,
			&data->north->line_bytes, &data->north->endian);
	data->width = data->pars->nb_bigger_line;
	data->height = data->pars->nb_line_of_file;
	data->plane = init_vec(2 * data->dir.y / 3, -2 * data->dir.x / 3);
	draw(data);
	mlx_handling(data);
}
