/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fill_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/03/09 14:05:56 by lcavallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*put_file_in_map(t_pars *pars, char **new_map, int i)
{
	int	k;

	k = 0;
	new_map[i] = malloc(sizeof(char) * (pars->nb_bigger_line + 1));
	while (pars->data->map[i][k])
	{
		new_map[i][k] = pars->data->map[i][k];
		k++;
	}
	while (k < pars->nb_bigger_line)
	{
		new_map[i][k] = ' ';
		k++;
	}
	new_map[i][k] = '\0';
	return (new_map[i]);
}

void	init_position(int i, int j, t_data *d, char **map)
{
	if (map[i][j] == 'N')
		d->dir = init_vec(0, 1);
	if (map[i][j] == 'W')
		d->dir = init_vec(-1, 0);
	if (map[i][j] == 'S')
		d->dir = init_vec(0, -1);
	if (map[i][j] == 'E')
		d->dir = init_vec(1, 0);
}

int	is_charset_map(char map)
{
	if (map != ' ' && map != '0' && map != '1' && map != 'N'
		&& map != 'S' && map != 'E' && map != 'W')
		return (ERROR);
	if (map == 'N' || map == 'S' || map == 'E' || map == 'W')
		return (2);
	return (SUCCESS);
}

int	check_char_map(char **map, t_data *d, t_pars *pars)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_charset_map(map[i][j]) == ERROR)
				return (ERROR);
			if (is_charset_map(map[i][j]) == 2)
			{
				init_position(i, j, d, map);
				d->pos.y = (pars->nb_line_of_file - i - 1) + 0.5;
				d->pos.x = j + 0.5;
				player++;
			}
		}
	}
	if (player != 1)
		return (ERROR);
	return (SUCCESS);
}
