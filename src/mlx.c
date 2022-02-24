/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:14:59 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/24 17:15:18 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	t_mlx	*mlx;
	char	*dst;
	int		pixel;

	mlx = data->mlx;
	pixel = (mlx->screen.y - y - 1) * mlx->line_bytes + x * 4;
	dst = mlx->buffer + pixel;
	*(unsigned int *)dst = color;
}
