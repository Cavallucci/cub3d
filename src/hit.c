/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:05:23 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/21 15:25:46 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hit_up(t_data *data)
{
	t_vec	new_pos;

	new_pos = add_vec(data->pos, mult_dbl(data->dir, 0.51));
	if (data->map[(int)(data->height - new_pos.y)][(int)(new_pos.x)] == '1')
		return (1);
	if (data->map[(int)(data->height - data->pos.y)][(int)(new_pos.x)] == '1' && data->map[(int)(data->height - new_pos.y)][(int)(data->pos.x)] == '1')
		return (1);
	return (0);
}

int	hit_down(t_data *data)
{
	t_vec	new_pos;

	new_pos = add_vec(data->pos, mult_dbl(data->dir, -0.51));
	if (data->map[(int)(data->height - new_pos.y)][(int)(new_pos.x)] == '1')
		return (1);
	if (data->map[(int)(data->height - data->pos.y)][(int)(new_pos.x)] == '1' && data->map[(int)(data->height - new_pos.y)][(int)(data->pos.x)] == '1')
		return (1);
	return (0);
}

int	hit_right(t_data *data)
{
	t_vec	new_pos;

	new_pos = add_vec(data->pos, mult_dbl(data->plane, 0.76));
	if (data->map[(int)(data->height - new_pos.y)][(int)(new_pos.x)] == '1')
		return (1);
	if (data->map[(int)(data->height - data->pos.y)][(int)(new_pos.x)] == '1' && data->map[(int)(data->height - new_pos.y)][(int)(data->pos.x)] == '1')
		return (1);
	return (0);
}

int	hit_left(t_data *data)
{
	t_vec	new_pos;

	new_pos = add_vec(data->pos, mult_dbl(data->plane, -0.76));
	if (data->map[(int)(data->height - new_pos.y)][(int)(new_pos.x)] == '1')
		return (1);
	if (data->map[(int)(data->height - data->pos.y)][(int)(new_pos.x)] == '1' && data->map[(int)(data->height - new_pos.y)][(int)(data->pos.x)] == '1')
		return (1);
	return (0);
}