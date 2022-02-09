/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcavallu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:06:52 by lcavallu          #+#    #+#             */
/*   Updated: 2022/02/09 14:12:20 by lcavallu         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "cub3d.h"

int	get_nb_line(t_pars	*pars)
{
	char	*line;
	int		file;
	int		count_line;

	count_line = 0;
	file = open(pars->file_name, O_RDONLY);
	if (file < 0)
		ft_free_close_error("Error\nOpen map", pars);
	line = get_next_line(file, &line);
	if (!line)
		ft_free_close_error("Error\nEmpty file", pars);
	count_line++;
	while (line)
	{
		free(line);
		line = get_next_line(file, &line);
		count_line++;
	}
	close(file);
	free(line);
	return (count_line);
}

void	collect_textures(t_pars *pars)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (count < 7)
	{
		while (pars->file[i] && ft_is_space(pars->file[i]) == SUCCESS)
			i++;
		if (count == 1)
			pars->north = ft_split(pars->file[i], ' ');
		else if (count == 2)
			pars->south = ft_split(pars->file[i], ' ');
		else if (count == 3)
			pars->west = ft_split(pars->file[i], ' ');
		else if (count == 4)
			pars->east = ft_split(pars->file[i], ' ');
		else if (count == 5)
			pars->floor = ft_split(pars->file[i], ' ');
		else if (count == 6)
			pars->ceiling = ft_split(pars->file[i], ' ');
		i++;
		count++;
	}
}

void	parsing(t_data *d, char **argv)
{
	t_pars	pars[1];

	init_pars(pars, argv, d);
	check_informations(pars);
	//si textures ok, verifir la map
	//si map ok, mettre la map dans un ** a part

}
