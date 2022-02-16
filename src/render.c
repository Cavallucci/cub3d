/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:50:09 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/16 18:00:27 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * 10);
	i = 0;
	while (i < 10)
	{
		map[i] = (char *)malloc(sizeof(char) * 11);
		j = 0;
		while (j < 10)
		{
			if (i == 0 || i == 9 || j == 0 || j == 9)
				map[i][j] = '1';
			else
				map[i][j] = '0';
			j++;
		}
		map[i][j] = 0;
		i++;
	}
	data->map = map;
}

void	mlx_handling(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win,
		data->mlx->img, 0, 0);
	mlx_key_hook(data->mlx->win, key_hook, data);
	mlx_hook(data->mlx->win, 17, 0, win_close, data);
	mlx_loop(data->mlx->mlx_ptr);
}

void	render(t_data *data)
{
	int	i;
	int	j;

	test(data);
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (data->map[i][j])
			write(1, &data->map[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
	data->pos = init_vec(4.5, 4.5);
	data->dir = init_vec(0, 1);
	data->plane = init_vec(0.66, 0);
	data->mlx = init_mlx(data);
	draw(data);
	mlx_handling(data);
}
