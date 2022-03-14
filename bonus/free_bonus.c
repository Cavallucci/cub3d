/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:29:13 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/14 10:19:43 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mlx_free_img(void *mlx_ptr, t_mlx *mlx)
{
	if (mlx->img)
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

void	free_doors(t_door *door)
{
	t_door	*tmp;

	while (door)
	{
		tmp = door;
		door = door->next;
		free(tmp);
		tmp = NULL;
	}
}

void	free_data_pars(t_pars *pars)
{
	if (pars->file_fd)
		close(pars->file_fd);
	if (pars->file)
		free_str(pars->file);
	if (pars->north)
		free_str(pars->north);
	if (pars->south)
		free_str(pars->south);
	if (pars->west)
		free_str(pars->west);
	if (pars->east)
		free_str(pars->east);
	if (pars->door)
		free_str(pars->door);
	if (pars->sprite)
		free_str(pars->sprite);
}

void	free_data(t_data *data)
{
	free_data_pars(data->pars);
	if (data->map)
		free_str(data->map);
	if (data->z_buffer)
		free(data->z_buffer);
	if (data->sprite)
		free_sprites(data->sprite);
	if (data->key)
		free(data->key);
	if (data->list_door)
		free_doors(data->list_door);
	free(data->pars);
	free(data);
}
