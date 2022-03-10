/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:56:35 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 15:37:28 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vec	init_vec(double x, double y)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	return (v);
}

double	size_vec(t_vec v)
{
	double	size;

	size = sqrt(v.x * v.x + v.y * v.y);
	return (size);
}

void	rotate(double angle, t_vec *v)
{
	t_vec	tmp;

	tmp = *v;
	v->x = tmp.x * cos(angle) + tmp.y * sin(angle);
	v->y = tmp.y * cos(angle) - tmp.x * sin(angle);
}
