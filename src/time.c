/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:38:35 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/09 14:39:09 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	get_time(void)
{
	struct timeval	time;
	unsigned long	timestamp;

	gettimeofday(&time, NULL);
	timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (timestamp);
}
