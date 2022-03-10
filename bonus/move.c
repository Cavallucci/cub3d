/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:41:59 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 18:14:28 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	rotation(t_data *data)
{
	double	angle;

	if (data->key->left > 0)
		angle = -data->key->left * 3.1415 / 90;
	else if (data->key->right > 0)
		angle = data->key->right * 3.1415 / 90;
	else if (data->key->left == -1)
		angle = -3.1415 / 90;
	else
		angle = 3.1415 / 90;
	rotate(angle, &data->dir);
	rotate(angle, &data->plane);
	if (data->key->left > 0)
		data->key->left = 0;
	if (data->key->right > 0)
		data->key->right = 0;
}

void	move(t_data *data)
{
	if (data->key->left || data->key->right)
		rotation(data);
	if (data->key->w && !hit_up(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, 0.1));
	if (data->key->s && !hit_down(data))
		data->pos = add_vec(data->pos, mult_dbl(data->dir, -0.1));
	if (data->key->a && !hit_left(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, -0.15));
	if (data->key->d && !hit_right(data))
		data->pos = add_vec(data->pos, mult_dbl(data->plane, 0.15));
}
