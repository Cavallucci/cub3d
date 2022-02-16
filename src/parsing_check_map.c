/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/15 15:49:06 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int	check_first_last_line(t_pars *pars, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (i == 0 || i == pars->nb_line_of_file)
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] != '1' && map[i][j] != ' ')
					return (ERROR);
				j++;
			}
		}
		i++;
	}
	return (SUCCESS);
}

int	check_char_map(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W')
				return (ERROR);
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (ERROR);
	return (SUCCESS);
}

int	check_first_last_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
			return (ERROR);
		while (map[i][j])
			j++;
		j--;
		if (map[i][j] != '1')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	around_map(char **map, int i, int j)
{
	int	tmp;
	int	error_high;
	int	error_back;

	tmp = i;
	error_high = 0;
	error_back = 0;
	while (i - 1 > 0 && map[i - 1][j] == ' ')
		i--;
	if (i - 1 > 0)
		i--;
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W')
		error_high++;
	while (map[tmp + 1] && map[tmp + 1][j] == ' ')
		tmp++;
	if (map[tmp + 1])
		tmp++;
	if (map[tmp] && (map[tmp][j] == '0' || map[tmp][j] == 'N'
		|| map[tmp][j] == 'S' || map[tmp][j] == 'E' || map[tmp][j] == 'W'))
		error_back++;
	if (error_high > 0 || error_back > 0)
		return (ERROR);
	return (SUCCESS);
}

int	sides_map(char **map, int i, int j)
{
	int	tmp;
	int	error_high;
	int	error_back;

	tmp = j;
	error_high = 0;
	error_back = 0;
	while (j - 1 > 0 && map[i][j - 1] == ' ')
		j--;
	if (j - 1 > 0)
		j--;
	if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'E' || map[i][j] == 'W')
		error_high++;
	while (map[i][tmp + 1] && map[i][tmp + 1] == ' ')
		tmp++;
	if (map[i][tmp + 1])
		tmp++;
	if (map[i][tmp] && (map[i][tmp] == '0' || map[i][tmp] == 'N'
		|| map[i][tmp] == 'S' || map[i][tmp] == 'E' || map[i][tmp] == 'W'))
		error_back++;
	if (error_high > 0 || error_back > 0)
		return (ERROR);
	return (SUCCESS);

}

int	check_spaces_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				if (around_map(map, i, j) == ERROR || sides_map(map, i, j) == ERROR)
						return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	verify_map(t_pars *pars)
{
	if (check_first_last_line(pars, pars->data->map) == ERROR)
			return (ERROR);
	if (check_char_map(pars->data->map) == ERROR)
		return (ERROR);
//	if (check_first_last_char(pars->data->map) == ERROR)
//		return (ERROR);
	if (check_spaces_map(pars->data->map) == ERROR)
		return (ERROR);
	return (SUCCESS);
	//si il y a des espaces, verifier celui d'en dessous ou dessus jusqu'a ce qu'il y ai un 1

}
