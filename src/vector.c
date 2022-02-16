/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:56:35 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/16 18:05:50 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec	init_vec(double x, double y)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	return (v);
}

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

double	size_vec(t_vec v)
{
	double	size;

	size = sqrt(v.x * v.x + v.y * v.y);
	return (size);
}
