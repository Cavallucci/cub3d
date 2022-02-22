/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:14:22 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/22 17:45:55 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_mlx	*init_mlx()
{
	t_mlx	*ptr;
	int		size[2];

	ptr = malloc(sizeof(t_mlx));
	if (!ptr)
		return (NULL);
	ptr->mlx_ptr = mlx_init();
	if (!ptr->mlx_ptr)
		return (NULL);
	mlx_get_screen_size(ptr->mlx_ptr, &(size[0]), &(size[1]));
	ptr->screen = init_vec(size[0], size[1]);
	ptr->win = mlx_new_window(ptr->mlx_ptr, ptr->screen.x,
			ptr->screen.y, "cub3d");
	ptr->img = mlx_new_image(ptr->mlx_ptr, ptr->screen.x, ptr->screen.y);
	if (!ptr->win || !ptr->img)
		return (NULL);
	ptr->buffer = mlx_get_data_addr(ptr->img, &ptr->pixel_bits,
			&ptr->line_bytes, &ptr->endian);
	if (!ptr->buffer)
		return (NULL);
	return (ptr);
}
