/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:05:23 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/27 14:53:14 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	hit_door(t_data *data)
{
	t_vec	new;
	double	i;

	i = 0.11;
	while (i <= 0.51)
	{
		new = add_vec(data->pos, mult_dbl(data->dir, i));
		if (data->map[(int)(data->height - new.y)][(int)(new.x)] == 'D')
			return (1);
		if (data->map[(int)(data->height - data->pos.y)][(int)new.x] == 'D'
			&& data->map[(int)(data->height - new.y)][(int)data->pos.x] == 'D')
			return (1);
		i += 0.1;
	}
	return (0);
}


int	hit_up(t_data *data)
{
	t_vec	new;
	double	i;

	i = 0.11;
	while (i <= 0.51)
	{
		new = add_vec(data->pos, mult_dbl(data->dir, i));
		if (data->map[(int)(data->height - new.y)][(int)(new.x)] == '1'
			|| data->map[(int)(data->height - new.y)][(int)(new.x)] == 'D')
			return (1);
		if ((data->map[(int)(data->height - data->pos.y)][(int)new.x] == '1'
			&& data->map[(int)(data->height - new.y)][(int)data->pos.x] == '1')
			|| (data->map[(int)(data->height - data->pos.y)][(int)new.x] == 'D'
			&& data->map[(int)(data->height - new.y)][(int)data->pos.x] == 'D'))
			return (1);
		i += 0.1;
	}
	return (0);
}

int	hit_down(t_data *data)
{
	t_vec	new;
	double	i;

	i = -0.11;
	while (i >= -0.51)
	{
		new = add_vec(data->pos, mult_dbl(data->dir, i));
		if (data->map[(int)(data->height - new.y)][(int)new.x] == '1'
			|| data->map[(int)(data->height - new.y)][(int)new.x] == 'D')
			return (1);
		if ((data->map[(int)(data->height - data->pos.y)][(int)(new.x)] == '1'
			&& data->map[(int)(data->height - new.y)][(int)data->pos.x] == '1')
			|| (data->map[(int)(data->height - data->pos.y)][(int)(new.x)] == 'D'
			&& data->map[(int)(data->height - new.y)][(int)data->pos.x] == 'D'))
			return (1);
		i -= 0.1;
	}
	return (0);
}

int	hit_right(t_data *data)
{
	t_vec	new;
	double	i;

	i = 0.06;
	while (i <= 0.76)
	{
		new = add_vec(data->pos, mult_dbl(data->plane, i));
		if (data->map[(int)(data->height - new.y)][(int)new.x] == '1'
			|| data->map[(int)(data->height - new.y)][(int)new.x] == 'D')
			return (1);
		if ((data->map[(int)(data->height - data->pos.y)][(int)(new.x)] == '1'
			&& data->map[(int)(data->height - new.y)][(int)data->pos.x] == '1')
			|| (data->map[(int)(data->height - data->pos.y)][(int)(new.x)] == 'D'
			&& data->map[(int)(data->height - new.y)][(int)data->pos.x] == 'D'))
			return (1);
		i += 0.1;
	}
	return (0);
}

int	hit_left(t_data *data)
{
	t_vec	new;
	double	i;

	i = -0.06;
	while (i >= -0.76)
	{
		new = add_vec(data->pos, mult_dbl(data->plane, i));
		if (data->map[(int)(data->height - new.y)][(int)new.x] == '1'
			|| data->map[(int)(data->height - new.y)][(int)new.x] == 'D')
			return (1);
		if ((data->map[(int)(data->height - data->pos.y)][(int)new.x] == '1'
			&& data->map[(int)(data->height - new.y)][(int)data->pos.x] == '1')
			|| (data->map[(int)(data->height - data->pos.y)][(int)new.x] == 'D'
			&& data->map[(int)(data->height - new.y)][(int)data->pos.x] == 'D'))
			return (1);
		i -= 0.1;
	}
	return (0);
}
