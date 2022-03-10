/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:34:22 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 15:25:59 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	open_door(t_data *data)
{
	t_vec   new;
	double  i;
	t_door	*cell;
	long	wait;

	wait = get_time();
	i = 0.11;
	while (i <= 0.51)
	{
		new = add_vec(data->pos, mult_dbl(data->dir, i));
		if (data->map[(int)(data->height - new.y)][(int)(new.x)] == 'D')
		{
			cell = new_cell(new.x, (data->height - new.y), wait);
			add_cell(&data->list_door, cell);
			data->map[(int)(data->height - new.y)][(int)(new.x)] = '0';
			re_draw(data);
			break;
		}
		i += 0.1;
	}
}
