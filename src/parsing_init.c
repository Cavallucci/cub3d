/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/09 14:36:59 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

void    init_data(t_data *d)
{
	d->mlx = NULL;
	d->pars = NULL;
}

void    init_pars(t_pars *pars, char **argv, t_data *d)
{
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
}
