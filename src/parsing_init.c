/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/03/02 15:41:35 by pguignie         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

void	init_data(t_data *d)
{
	d->mlx = NULL;
	d->last_move = 0;
	d->list_door = malloc(sizeof(t_door));
}

void	init_pars(t_pars *pars, char **argv, t_data *d)
{
	pars->nb_line_of_file = 0;
	pars->nb_bigger_line = 0;
	pars->file_name = argv[1];
	pars->file_fd = open(pars->file_name, O_RDONLY);
	if (pars->file_fd < 0)
		ft_error("Error\nOpen map");
	pars->file = NULL;
	pars->north = NULL;
	pars->south = NULL;
	pars->west = NULL;
	pars->east = NULL;
	pars->floor = NULL;
	pars->ceiling = NULL;
	pars->data = d;
	d->pars = pars;
}
