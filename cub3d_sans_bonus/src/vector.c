/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:56:35 by pguignie          #+#    #+#             */
/*   Updated: 2022/02/24 17:13:45 by pguignie         ###   ########.fr       */
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

double	size_vec(t_vec v)
{
	double	size;

	size = sqrt(v.x * v.x + v.y * v.y);
	return (size);
}
