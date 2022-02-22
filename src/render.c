/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:09 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/22 15:01:37 by pguignie         ###   ########.fr       */
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
	data->north = malloc(sizeof(t_mlx));
	data->north->img = NULL;
	data->north->mlx_ptr = NULL;
	data->north->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "./img/NO.xpm", &data->north->img_width, &data->north->img_height);
	data->north->mlx_ptr = mlx_get_data_addr(data->north->img, &data->north->pixel_bits,
			&data->north->line_bytes, &data->north->endian);
	
	data->south = malloc(sizeof(t_mlx));
	data->south->img = NULL;
	data->south->mlx_ptr = NULL;
	data->south->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "./img/SO.xpm", &data->south->img_width, &data->south->img_height);
	data->south->mlx_ptr = mlx_get_data_addr(data->south->img, &data->south->pixel_bits,
			&data->south->line_bytes, &data->south->endian);

	data->west = malloc(sizeof(t_mlx));
	data->west->img = NULL;
	data->west->mlx_ptr = NULL;
	data->west->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "./img/WE.xpm", &data->west->img_width, &data->west->img_height);
	data->west->mlx_ptr = mlx_get_data_addr(data->west->img, &data->west->pixel_bits,
			&data->west->line_bytes, &data->west->endian);

	data->east = malloc(sizeof(t_mlx));
	data->east->img = NULL;
	data->east->mlx_ptr = NULL;
	data->east->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, "./img/EA.xpm", &data->east->img_width, &data->east->img_height);
	data->east->mlx_ptr = mlx_get_data_addr(data->east->img, &data->east->pixel_bits,
			&data->east->line_bytes, &data->east->endian);
	data->plane = init_vec(2 * data->dir.y / 3, -2 * data->dir.x / 3);
	draw(data);
	mlx_handling(data);
}
