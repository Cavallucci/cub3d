/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:29:13 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/08 17:29:49 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_free_img(void *mlx_ptr, t_mlx *mlx)
{
	mlx_destroy_image(mlx_ptr, mlx->img);
	free(mlx);
}

void	free_sprites(t_sprit *s)
{
	t_sprit	*tmp;

	while (s)
	{
		tmp = s;
		s = s->next;
		free(tmp);
		tmp = NULL;
	}
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
	if (data->z_buffer)
		free(data->z_buffer);
	free_sprites(data->sprite);
	free(data->pars);
	free(data);
}
