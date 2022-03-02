/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguignie <pguignie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:18:20 by pguignie          #+#    #+#             */
/*   Updated: 2022/03/02 15:55:44 by pguignie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_sprites(t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			printf("%c", data->map[data->pars->nb_line_of_file - 1 - i][j++]);
		printf("\n");
		i++;
	}
}
