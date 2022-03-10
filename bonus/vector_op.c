/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:13:16 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/10 15:37:38 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_vec	add_vec(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_vec	sub_vec(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return (c);
}

t_vec	mult_dbl(t_vec v, double dbl)
{
	v.x *= dbl;
	v.y *= dbl;
	return (v);
}

double	dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y);
}

t_vec	normalize(t_vec v)
{
	double	d;

	if (v.x == 0 && v.y == 0)
		return (v);
	d = sqrt(v.x * v.x + v.y * v.y);
	return (mult_dbl(v, 1 / d));
}
