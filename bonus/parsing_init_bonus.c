/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/03/10 18:28:10 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	collect_textures_bonus(t_pars *pars, int count, int i)
{
	if (count == 2)
		pars->south = ft_split(pars->file[i], ' ');
	else if (count == 3)
		pars->west = ft_split(pars->file[i], ' ');
	else if (count == 4)
		pars->east = ft_split(pars->file[i], ' ');
	else if (count == 5)
		pars->door = ft_split(pars->file[i], ' ');
	else if (count == 6)
		pars->sprite = ft_split(pars->file[i], ' ');
	else if (count == 7)
		pars->floor = pars->file[i];
	else if (count == 8)
		pars->ceiling = pars->file[i];
}

void	collect_textures(t_pars *pars)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (count++ < 9)
	{
		while (pars->file[i] && ft_is_space(pars->file[i]) == SUCCESS)
			i++;
		if (count == 1)
			pars->north = ft_split(pars->file[i], ' ');
		else
			collect_textures_bonus(pars, count, i);
		i++;
	}
}

void	init_data(t_data *d)
{
	d->mlx = NULL;
	d->last_move = 0;
	d->list_door = malloc(sizeof(t_door));
	d->sprite = NULL;
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
